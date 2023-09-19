#!/usr/bin/env sh

envsubst '${CONTAINER_PHP_FPM}' < /etc/nginx/conf.d/default.conf.template > /etc/nginx/conf.d/default.conf.tmp
envsubst '${APP_NAME}' <  /etc/nginx/conf.d/default.conf.tmp > /etc/nginx/conf.d/default.conf

exec "$@"
