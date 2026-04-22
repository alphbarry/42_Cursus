# 🐳 Inception - Docker Infrastructure

## 📍 Overview

**Inception** is a project in the 42 Cursus that demonstrates Docker containerization and orchestration. It implements a complete web application stack with Nginx, WordPress, and MariaDB running in isolated containers, demonstrating professional DevOps practices, infrastructure as code, and secure deployments.

## 🎯 Objectives

- Master Docker containerization and image creation
- Implement Docker Compose for multi-container orchestration
- Design secure deployment architectures
- Implement SSL/TLS encryption
- Manage persistent data with Docker volumes
- Configure service networking and communication
- Learn infrastructure automation and scripting
- Implement secrets management best practices

## 🏗️ Architecture

### Three-Tier Stack

```
┌─────────────────────────────────────────────┐
│          Docker Network Bridge              │
├─────────────────────────────────────────────┤
│                                             │
│  ┌─────────────────┐   ┌────────────────┐  │
│  │     Nginx       │   │   WordPress    │  │
│  │  (Port 443)     │──▶│   (PHP-FPM)    │  │
│  │  SSL Proxy      │   └────────────────┘  │
│  │  Static Files   │                       │
│  └─────────────────┘   ┌────────────────┐  │
│                        │    MariaDB     │  │
│                        │    (Port 3306) │  │
│                        │    (Internal)  │  │
│                        └────────────────┘  │
│                                             │
└─────────────────────────────────────────────┘
         ▲
         │ TLS/SSL
         │ (Port 443)
         │
    [Client Browser]
```

### Components

1. **Nginx** - Web server, reverse proxy, SSL/TLS termination
2. **WordPress** - Content management system with PHP-FPM
3. **MariaDB** - Relational database (MySQL compatible)

Each runs in **isolated Docker containers** with:
- Separate filesystems
- Network isolation
- Resource limits
- Health checks

## 🛠️ Features

### Container Management
- **Docker Compose Orchestration** - Define entire stack in YAML
- **Multi-stage Builds** - Optimize images for production
- **Custom Dockerfiles** - Minimal, production-ready images
- **Volume Management** - Persistent data across restarts
- **Health Checks** - Automatic service monitoring

### Security
- **SSL/TLS Encryption** - HTTPS with self-signed certificates
- **Secrets Management** - Separate environment variables and passwords
- **Network Isolation** - Internal bridge network
- **Access Control** - Service-to-service authentication
- **Container Hardening** - Minimal base images, no root

### Scalability
- **Service Restart Policies** - Automatic recovery
- **Resource Limits** - CPU and memory constraints
- **Volume Mounting** - Scalable data storage
- **Environment Configuration** - Easy customization

## 📦 Project Structure

```
Inception/
├── Makefile                    # Build automation
├── README.md                   # This file
├── USER_DOC.md                 # User documentation
├── DEV_DOC.md                  # Developer documentation
├── secrets/
│   ├── .gitkeep
│   ├── db_root_password.txt    # MariaDB root password
│   └── db_password.txt         # WordPress DB password
├── srcs/
│   ├── docker-compose.yml      # Compose configuration
│   ├── Makefile               # Container build targets
│   └── requirements/
│       ├── nginx/
│       │   ├── Dockerfile      # Nginx image definition
│       │   ├── conf/
│       │   │   └── nginx.conf  # Nginx configuration
│       │   └── tools/
│       │       └── generate_ssl.sh  # SSL certificate generator
│       ├── wordpress/
│       │   ├── Dockerfile      # WordPress image definition
│       │   └── tools/
│       │       └── wp_setup.sh # WordPress initialization script
│       └── mariadb/
│           ├── Dockerfile      # MariaDB image definition
│           ├── conf/
│           │   └── my.cnf      # MariaDB configuration
│           └── tools/
│               └── init_db.sh  # Database initialization script
├── .env.example               # Environment variables template
└── .gitignore                 # Git ignore rules
```

## 🚀 Quick Start

### Prerequisites

```bash
# Required
- Docker Engine (20.10+)
- Docker Compose (v2 or v1.29+)
- Git
- Linux (Ubuntu 18.04+ recommended) or macOS/WSL2

# Verify installation
docker --version
docker compose version
```

### Installation

#### 1. Clone Repository

```bash
git clone <repository-url>
cd Inception
```

#### 2. Configure Environment Variables

```bash
# Create .env file in srcs/ directory
cd srcs

# Option A: Copy and edit template
cp ../.env.example .env
# Edit .env with your settings

# Option B: Create manually
cat > .env << 'ENDENV'
NGINX_PORT=443
DOMAIN_NAME=yourdomain.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=wp_user
WP_TITLE=My Website
WP_ADMIN_USER=admin_user
WP_ADMIN_EMAIL=admin@yourdomain.42.fr
WP_USER=editor
WP_USER_EMAIL=editor@yourdomain.42.fr
ENDENV
```

⚠️ **Important:** Admin username must NOT contain the substring "admin" (42 requirement)

#### 3. Create Secrets

```bash
# Create secrets directory (if doesn't exist)
cd ..
mkdir -p secrets

# Add passwords to secret files
echo "your_secure_db_root_password" > secrets/db_root_password.txt
echo "your_secure_db_password" > secrets/db_password.txt

# Secure the files
chmod 600 secrets/*.txt
```

#### 4. Create Host Directories for Volumes

```bash
# Create directories for persistent storage
# Replace "your_login" with your actual 42 login
mkdir -p /home/your_login/data/mariadb
mkdir -p /home/your_login/data/wordpress

# Set proper permissions
chmod 755 /home/your_login/data/*
```

#### 5. Build and Start Services

```bash
# Navigate to srcs directory
cd srcs

# Build images and start containers
make up

# Or using docker compose directly
docker compose up -d --build
```

#### 6. Access the Application

```bash
# Add to /etc/hosts (Linux/macOS)
echo "127.0.0.1 yourdomain.42.fr" | sudo tee -a /etc/hosts

# Access in browser
# Website: https://yourdomain.42.fr
# WordPress Admin: https://yourdomain.42.fr/wp-admin
```

## 🔧 Common Commands

### Using Make

```bash
make up               # Build and start all services
make down             # Stop and remove containers
make re               # Restart services
make logs             # View container logs
make clean            # Remove containers and volumes
make fclean           # Full clean (remove images too)
make set-port PORT=3000  # Change NGINX port
```

### Using Docker Compose

```bash
# Start services
docker compose up -d

# Stop services
docker compose down

# View logs
docker compose logs -f

# Restart service
docker compose restart wordpress

# View status
docker compose ps

# Execute command in container
docker compose exec wordpress wp --allow-root list users
```

### Database Management

```bash
# Access MariaDB CLI
docker compose exec mariadb mariadb -u root -p

# Backup database
docker compose exec mariadb mysqldump -u root -p wordpress > backup.sql

# Restore database
docker compose exec -T mariadb mysql -u root -p < backup.sql
```

## 📋 Configuration Details

### Docker Compose Services

| Service | Image | Purpose | Ports |
|---------|-------|---------|-------|
| Nginx | Alpine + Nginx | Reverse proxy, SSL termination | 443 (external) |
| WordPress | Alpine + PHP-FPM | CMS application | 9000 (internal) |
| MariaDB | Alpine + MariaDB | Database | 3306 (internal) |

### Nginx Configuration

```nginx
server {
    listen 443 ssl http2;
    server_name yourdomain.42.fr;
    
    ssl_certificate /etc/nginx/ssl/yourdomain.42.fr.crt;
    ssl_key /etc/nginx/ssl/yourdomain.42.fr.key;
    
    root /var/www/wordpress;
    index index.php;
    
    # PHP handling
    location ~ \.php$ {
        fastcgi_pass wordpress:9000;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    }
    
    # Static files
    location ~* \.(jpg|jpeg|png|gif|ico|css|js|svg)$ {
        expires 365d;
    }
}
```

## 🐳 Docker Concepts

### Containers vs Images

| Aspect | Image | Container |
|--------|-------|-----------|
| Definition | Blueprint | Running instance |
| Persistence | Permanent | Temporary |
| Size | Smaller | Larger |
| Creation | `docker build` | `docker run` |

### Volumes

```bash
# Named volume
volumes:
  my_data:

# Bind mount (host path)
volumes:
  - /host/path:/container/path
```

### Networking

- **Bridge** - Default, containers communicate
- **Host** - Share host network
- **None** - Isolated network
- **Custom** - User-defined network (recommended)

## 🔒 Security Best Practices

### Secrets Management
- ✅ Store passwords in `/secrets/` directory
- ✅ Use `.env` files (never commit secrets)
- ✅ Use Docker secrets (production)
- ✅ Rotate passwords regularly

### Container Security
- ✅ Run as non-root user
- ✅ Use minimal base images (alpine)
- ✅ Regular security updates
- ✅ Read-only filesystems where possible

### SSL Certificate Generation

```bash
# Generate self-signed certificate
openssl req -x509 -days 365 -nodes \
    -newkey rsa:2048 \
    -keyout cert.key \
    -out cert.crt \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=42/CN=yourdomain.42.fr"
```

## 🧪 Testing & Debugging

### Health Checks

```bash
# Check if services are running
docker compose ps

# View service health
docker compose exec nginx curl -I https://localhost/

# Check database connectivity
docker compose exec wordpress mysql -h mariadb -u root -p -e "SHOW DATABASES;"
```

### Logs

```bash
# View logs for all services
docker compose logs

# Follow logs in real-time
docker compose logs -f

# View logs for specific service
docker compose logs -f wordpress

# View last 100 lines
docker compose logs --tail=100
```

### Container Shell

```bash
# Access Nginx container
docker compose exec nginx sh

# Access WordPress container
docker compose exec wordpress bash

# Access MariaDB container
docker compose exec mariadb bash
```

## 🛡️ Troubleshooting

| Issue | Solution |
|-------|----------|
| Port already in use | Change NGINX_PORT in .env |
| Containers won't start | Check logs: `docker compose logs` |
| Database connection fails | Verify DB_HOST matches service name |
| Permission denied on volumes | Check host directory ownership |
| SSL certificate errors | Regenerate SSL certificate |
| WordPress database empty | Run WP installation script |

## 📚 Key Docker Commands

```bash
# Image management
docker build -t name:tag .
docker images
docker rmi image_id

# Container management
docker run -d --name container_name image:tag
docker ps -a
docker stop container_id
docker rm container_id

# Compose management
docker compose up -d
docker compose down -v
docker compose logs -f

# Inspection
docker inspect container_id
docker stats
docker top container_id
```

## 📝 Notes

- All Dockerfiles use multi-stage builds for efficiency
- Containers run non-root services for security
- Volumes persist data between restarts
- SSL generated automatically on first run
- Database initialized automatically on first start

## 🎓 Learning Outcomes

After completing this project, you will understand:
- Docker containerization fundamentals
- Multi-container orchestration with Compose
- Dockerfile best practices and multi-stage builds
- Volume and network management
- SSL/TLS configuration
- Environment management and secrets
- Service communication patterns
- Infrastructure as Code principles

## 📌 Status

✅ **Completed** - Full Docker stack with Nginx, WordPress, and MariaDB

## 👥 Author

Created by [alphbarry](https://github.com/alphbarry) as part of the 42 curriculum.

---

For detailed documentation, see:
- [USER_DOC.md](USER_DOC.md) - User guide
- [DEV_DOC.md](DEV_DOC.md) - Developer guide
