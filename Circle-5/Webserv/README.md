# 🌐 Webserv - HTTP Server

## 📍 Overview

**Webserv** is a project in the 42 Cursus that implements a fully functional, non-blocking HTTP server in C++. It demonstrates advanced concepts in network programming, I/O multiplexing, and server architecture while being compatible with Nginx-style configuration files.

## 🎯 Objectives

- Implement a **non-blocking HTTP server** handling multiple clients concurrently
- Master socket programming and I/O multiplexing (`poll()`, `select()`, `epoll()`, or `kqueue()`)
- Parse HTTP requests and generate proper HTTP responses
- Support multiple virtual hosts and ports
- Implement CGI execution for dynamic content
- Handle file uploads and serve static files
- Process Nginx-style configuration files
- Maintain stability under stress testing

## 🛠️ Core Features

### HTTP Protocol Support
- **Methods:** GET, POST, DELETE (fully implemented)
- **Headers:** Proper HTTP header parsing and response
- **Status Codes:** 200, 201, 204, 301, 302, 304, 400, 403, 404, 405, 413, 500, 502, 503
- **Content Negotiation:** Correct MIME types
- **Keep-Alive:** Connection reuse (optional)

### Server Architecture
- **Non-blocking I/O:** Fully asynchronous operation
- **I/O Multiplexing:** Single poll/select/epoll managing all sockets
- **Multi-port Support:** Listen on multiple interfaces:port combinations
- **Client Management:** Concurrent handling of multiple clients
- **Connection Handling:** Proper graceful handling of disconnections

### Configuration
- **Nginx-style Config:** Familiar configuration syntax
- **Multiple Servers:** Virtual host support
- **Location Blocks:** Route-specific rules and handlers
- **Custom Error Pages:** Serve custom HTML for HTTP errors
- **Client Body Limits:** Control maximum upload size
- **Static File Serving:** Efficient file serving

### Dynamic Content
- **CGI Support:** Execute PHP, Python, or other scripts
- **File Uploads:** Handle multipart form data
- **Directory Listing:** Optional automatic directory indexes
- **Default Files:** Serve index.html for directory requests

## 📦 Project Structure

```
Webserv/
├── Makefile               # Build automation
├── README.md              # This file
├── include/
│   ├── HttpRequest.hpp    # HTTP request parsing
│   ├── HttpResponse.hpp   # HTTP response generation
│   ├── ConfigParser.hpp   # Parse nginx.conf files
│   ├── ServerConfig.hpp   # Server configuration
│   ├── LocationConfig.hpp # Location block config
│   ├── CGIHandler.hpp     # CGI execution
│   ├── CGI.hpp            # CGI utilities
│   ├── initServer.hpp     # Server initialization
│   ├── Signals.hpp        # Signal handling
│   ├── utils.hpp          # General utilities
│   ├── utilsCC.hpp        # C++ utilities
│   └── macros.hpp         # Macro definitions
├── src/
│   ├── main.cpp           # Entry point
│   ├── HttpRequest.cpp
│   ├── HttpResponse.cpp
│   ├── ConfigParser.cpp
│   ├── ServerConfig.cpp
│   ├── LocationConfig.cpp
│   ├── CGIHandler.cpp
│   ├── CGI.cpp
│   ├── initServer.cpp
│   ├── Signals.cpp
│   ├── utils.cpp
│   └── utilsCC.cpp
├── var/www/html/          # Web root directory
│   ├── index.html
│   ├── styles.css
│   ├── 400BadRequest.html
│   ├── 403Forbidden.html
│   ├── 404NotFound.html
│   ├── 405MethodNotAllowed.html
│   ├── 413PayloadTooLarge.html
│   ├── 500Error.html
│   └── directorio/        # Test directory
├── upload/                # File upload directory
├── form_result/           # CGI output directory
├── default.conf           # Default configuration
├── robust_config.conf     # Production configuration
├── multiple_servers.conf  # Multi-server example
├── multiple_locations.conf # Location routing example
└── other.conf             # Alternative configuration
```

## 🚀 Compilation & Execution

### Compilation

```bash
make              # Compile the server
make clean        # Remove object files
make fclean       # Remove all generated files
make re           # Full rebuild
```

Creates executable: `webserv`

### Running the Server

```bash
./webserv <configuration_file>
```

### Examples

```bash
# Use default configuration
./webserv default.conf

# Use production configuration
./webserv robust_config.conf

# Use custom configuration
./webserv your_config.conf
```

## ⚙️ Configuration File Format

### Basic Server Configuration

```nginx
# Listen on specific port
server {
    listen          80;
    server_name     localhost;
    
    # Maximum body size for uploads
    client_max_body_size 10M;
    
    # Error pages
    error_page 404 /404.html;
    error_page 500 /500.html;
    
    # Root directory
    root /var/www/html;
    
    # Default file for directory requests
    index index.html;
}
```

### Location Blocks (Routing)

```nginx
server {
    listen 80;
    server_name example.com;
    
    # Static files
    location / {
        root /var/www/html;
        index index.html;
    }
    
    # CGI scripts
    location /cgi-bin/ {
        root /var/www;
        cgi_pass /usr/bin/python3;  # Script interpreter
        allow_methods GET POST;
    }
    
    # File uploads
    location /upload/ {
        allow_methods POST;
        upload_dir /tmp/uploads;
    }
    
    # Redirections
    location /old_page {
        return 301 http://example.com/new_page;
    }
}
```

### Virtual Hosts

```nginx
server {
    listen 80;
    server_name site1.com;
    root /var/www/site1;
}

server {
    listen 80;
    server_name site2.com;
    root /var/www/site2;
}

# HTTPS with SSL
server {
    listen 443 ssl;
    server_name secure.com;
    ssl_certificate /path/to/cert.pem;
    ssl_key /path/to/key.pem;
}
```

### Configuration Options

| Option | Purpose | Example |
|--------|---------|---------|
| `listen` | Port/interface to listen on | `listen 80;` or `listen 127.0.0.1:8080;` |
| `server_name` | Virtual host name(s) | `server_name example.com www.example.com;` |
| `root` | Document root directory | `root /var/www/html;` |
| `index` | Default files for directories | `index index.html index.htm;` |
| `client_max_body_size` | Max upload size | `client_max_body_size 50M;` |
| `error_page` | Custom error pages | `error_page 404 /404.html;` |
| `allow_methods` | Allowed HTTP methods | `allow_methods GET POST DELETE;` |
| `cgi_pass` | CGI script interpreter | `cgi_pass /usr/bin/php-cgi;` |
| `upload_dir` | Directory for uploads | `upload_dir /tmp/uploads;` |
| `return` | HTTP redirect | `return 301 /new_location;` |
| `autoindex` | Directory listing | `autoindex on/off;` |

## 🌍 HTTP Methods

### GET
- Retrieve resource content
- Should not modify server state
- Browser cache-friendly

```bash
curl http://localhost:8080/index.html
```

### POST
- Submit form data or file uploads
- Creates new resource
- Required for form submissions

```bash
curl -X POST -F "file=@upload.txt" http://localhost:8080/upload/
```

### DELETE
- Remove resource from server
- Requires proper permissions
- Idempotent operation

```bash
curl -X DELETE http://localhost:8080/file.txt
```

## 🔄 Request/Response Cycle

```
1. Client connects via TCP socket
2. Server receives data (poll detects readiness)
3. Parse HTTP request headers
4. Find matching location block in config
5. Check allowed methods
6. Handle request:
   - Static file: Send file contents
   - CGI script: Execute script, capture output
   - Directory: List or serve index.html
   - Redirect: Send 301/302 response
7. Generate HTTP response
8. Send response to client
9. Close connection (or keep-alive)
```

## 🔑 Key Implementation Details

### Non-Blocking I/O

```cpp
// Set socket to non-blocking
fcntl(socket_fd, F_SETFL, O_NONBLOCK);

// Use poll to detect readiness
poll(fds, nfds, timeout);
// Returns when socket is readable/writable
```

### I/O Multiplexing Options

| Method | Platform | Advantage |
|--------|----------|-----------|
| `poll()` | Unix/Linux | Portable, no fd_set size limits |
| `select()` | Unix/Linux | Standard, but limited file descriptors |
| `epoll()` | Linux | High performance, level/edge triggered |
| `kqueue()` | BSD/macOS | Efficient, supports many event types |

### CGI Execution

```cpp
// Fork child process
pid_t pid = fork();
if (pid == 0) {
    // Child: redirect stdin/stdout, exec script
    dup2(input_fd, STDIN_FILENO);
    dup2(output_fd, STDOUT_FILENO);
    execve("/usr/bin/php-cgi", args, env);
}
// Parent: read child output
```

### Configuration Parsing

```cpp
// Parse nginx.conf
std::vector<ServerConfig> servers;
ConfigParser parser("nginx.conf");
servers = parser.parse();

// Match incoming request to location
LocationConfig *location = server.findLocation(request_path);
```

## 📊 HTTP Status Codes

| Code | Meaning | Usage |
|------|---------|-------|
| 200 | OK | Successful request |
| 201 | Created | Resource created (POST) |
| 204 | No Content | Success, no response body |
| 301 | Moved Permanently | Permanent redirect |
| 302 | Found | Temporary redirect |
| 304 | Not Modified | Use cached version |
| 400 | Bad Request | Invalid request format |
| 403 | Forbidden | Access denied |
| 404 | Not Found | Resource doesn't exist |
| 405 | Method Not Allowed | HTTP method not supported |
| 413 | Payload Too Large | Upload size exceeds limit |
| 500 | Internal Server Error | Server error |
| 502 | Bad Gateway | CGI error |
| 503 | Service Unavailable | Server overloaded |

## 🧪 Testing

### Using curl

```bash
# Basic GET
curl http://localhost:8080/

# POST with data
curl -X POST -d "name=value" http://localhost:8080/form

# File upload
curl -F "file=@test.txt" http://localhost:8080/upload/

# Check headers
curl -I http://localhost:8080/

# DELETE request
curl -X DELETE http://localhost:8080/file.txt
```

### Using browser

```
http://localhost:8080/
http://localhost:8080/cgi-bin/script.php
http://localhost:8080/upload/
```

### Stress testing

```bash
# Use Apache Bench
ab -n 1000 -c 100 http://localhost:8080/

# Use wrk
wrk -t4 -c100 -d30s http://localhost:8080/
```

## 🛡️ Security Considerations

- **Path Traversal:** Prevent `../` attacks
- **File Permissions:** Respect filesystem permissions
- **Input Validation:** Sanitize all input
- **Buffer Overflow:** Use safe string operations
- **Timeout:** Prevent slow-client attacks
- **Resource Limits:** Set max connections and body size
- **SSL/TLS:** Support secure connections
- **Error Messages:** Don't leak sensitive information

## 📚 Learning Concepts

- **Socket Programming** - TCP/IP communication
- **I/O Multiplexing** - Efficient concurrent I/O
- **HTTP Protocol** - Request/response structure
- **Server Architecture** - Multi-client handling
- **Configuration Parsing** - nginx.conf format
- **Process Management** - fork/exec for CGI
- **Signal Handling** - Graceful shutdown
- **File I/O** - Efficient file serving

## 🔧 Debugging Tips

```bash
# Monitor network activity
netstat -tuln | grep 8080
lsof -i :8080

# Test with telnet
telnet localhost 8080
GET / HTTP/1.1
Host: localhost

# Enable verbose logging
./webserv config.conf 2>&1 | tee debug.log

# Check for memory leaks
valgrind --leak-check=full ./webserv config.conf
```

## ⚠️ Common Issues

| Issue | Cause | Solution |
|-------|-------|----------|
| Port in use | Another service on port | Use different port in config |
| Connection refused | Server not running | Start server with `./webserv config.conf` |
| 404 errors | Wrong document root | Check `root` directive in config |
| CGI not working | Incorrect script path | Verify `cgi_pass` and file permissions |
| Slow uploads | Poll timeout too short | Increase timeout value |
| Memory leak | Not cleaning resources | Use valgrind to detect leaks |

## 📝 Notes

- All code follows 42 Norm standards
- No external HTTP libraries allowed
- Must handle up to multiple concurrent connections
- Proper error handling for all edge cases
- Memory must be properly managed (no leaks)
- Configuration must be parsed correctly
- Server must remain responsive under load

## 🔧 Compilation Details

```bash
make              # Standard compilation
make clean        # Remove .o files
make fclean       # Remove executable and objects
make re           # Clean and rebuild
```

### Typical Compiler Command

```bash
clang++ -Wall -Wextra -Werror -std=c++98 -Iinclude src/*.cpp -o webserv
```

## 👥 Authors

Developed in collaboration with:
- [daortega](https://github.com/DavidOrtegaGarcia)
- [alphbarry](https://github.com/alphbarry)

## 📌 Status

✅ **Completed** - Full HTTP server with CGI, uploads, and configuration support

