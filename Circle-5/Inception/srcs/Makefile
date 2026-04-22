ENV_FILE ?= .env
PORT ?=

.PHONY: set-port
set-port:
	@if [ -z "$(PORT)" ]; then \
		echo "PORT variable is required (e.g. make set-port PORT=3000)"; \
		exit 1; \
	fi
	@if ! echo "$(PORT)" | grep -Eq '^[0-9]+$$'; then \
		echo "PORT must be a numeric value"; \
		exit 1; \
	fi
	@if [ ! -f "$(ENV_FILE)" ]; then \
		echo "Environment file $(ENV_FILE) not found"; \
		exit 1; \
	fi
	@tmp_file=$$(mktemp); \
	awk -v port="$(PORT)" 'BEGIN { updated=0 } \
	/^NGINX_PORT=/ { print "NGINX_PORT=" port; updated=1; next } \
	{ print } \
	END { if (!updated) { print "NGINX_PORT=" port } }' "$(ENV_FILE)" > $$tmp_file && \
	mv $$tmp_file "$(ENV_FILE)"
	@echo "NGINX_PORT set to $(PORT) in $(ENV_FILE)"
