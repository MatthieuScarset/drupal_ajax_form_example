#!/bin/bash

php-fpm --daemonize
exec yarn --cwd themes/theme_one_i watch
