#!/bin/sh
set -e

if [ -z "$DOMAIN_NAME" ]; then
  echo "DOMAIN_NAME environment variable is required" >&2
  exit 1
fi

CERT_DIR=/etc/nginx/ssl
NGINX_CONF=/etc/nginx/nginx.conf
NGINX_TEMPLATE=/etc/nginx/nginx.conf.template
mkdir -p $CERT_DIR

if [ ! -f "$NGINX_TEMPLATE" ]; then
  cp "$NGINX_CONF" "$NGINX_TEMPLATE"
fi
cp "$NGINX_TEMPLATE" "$NGINX_CONF"

if [ ! -f "$CERT_DIR/server.crt" ]; then
  openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout $CERT_DIR/server.key \
    -out $CERT_DIR/server.crt \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=$DOMAIN_NAME"
fi

DOMAIN_ESCAPED=$(printf '%s\n' "$DOMAIN_NAME" | sed 's/[\\/&]/\\&/g')
sed -i "s/__DOMAIN_NAME__/$DOMAIN_ESCAPED/g" "$NGINX_CONF"

LISTEN_PORT=${NGINX_PORT:-443}
if ! printf '%s' "$LISTEN_PORT" | grep -Eq '^[0-9]+$'; then
  echo "NGINX_PORT must be a numeric value (got '$LISTEN_PORT')" >&2
  exit 1
fi
if [ "$LISTEN_PORT" -lt 1 ] || [ "$LISTEN_PORT" -gt 65535 ]; then
  echo "NGINX_PORT must be between 1 and 65535 (got '$LISTEN_PORT')" >&2
  exit 1
fi
sed -i "s/__LISTEN_PORT__/$LISTEN_PORT/g" "$NGINX_CONF"
echo "Configured Nginx to listen on port $LISTEN_PORT"

# Asegurar permisos correctos en el directorio web
if [ -d /var/www/html ]; then
  chown -R www-data:www-data /var/www/html
  chmod -R 755 /var/www/html
fi

# Esperar a que PHP-FPM esté listo
echo "Esperando a que PHP-FPM esté disponible..."
until nc -z wordpress 9000 2>/dev/null; do
  echo "Esperando conexión a wordpress:9000..."
  sleep 2
done
echo "PHP-FPM está disponible"

# Verificar configuración de nginx
nginx -t

exec nginx -g "daemon off;"
