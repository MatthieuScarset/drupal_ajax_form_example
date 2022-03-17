#!/bin/bash

php-fpm --daemonize
yarn --cwd themes/theme_one_i install
yarn --cwd themes/theme_one_i watch
