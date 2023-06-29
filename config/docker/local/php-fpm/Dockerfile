FROM php:8.1-fpm

WORKDIR "/application"

# Fix debconf warnings upon build
ARG DEBIAN_FRONTEND=noninteractive
ARG UID
ARG GID

ADD php-ini-overrides.ini /usr/local/etc/php/conf.d/99-overrides.ini

# Install selected extensions and other stuff
RUN apt-get update && apt-get -y --no-install-recommends install \
    vim \
    libzip-dev \
    zip \
    unzip \
    wget \
    git \
    nodejs \
    npm

RUN docker-php-ext-install zip

# PHP iMagick
RUN apt-get install -y --no-install-recommends libmagickwand-dev imagemagick \
	&& pecl install imagick \
	&& docker-php-ext-enable imagick


# GD & MySql
RUN docker-php-ext-configure gd --prefix=/usr --with-jpeg --with-freetype \
  && docker-php-ext-install gd pdo_mysql \
  && docker-php-ext-enable gd

# ADD Memached
RUN apt-get install	-y libmemcached-dev \
  && pecl install memcached \
	&& docker-php-ext-enable memcached


# ADD OpCache
RUN docker-php-ext-enable opcache
RUN pecl install apcu && docker-php-ext-enable apcu

# XDebug
RUN pecl install xdebug \
    && docker-php-ext-enable xdebug

## Mise en place Mailhog
RUN wget https://github.com/mailhog/mhsendmail/releases/download/v0.2.0/mhsendmail_linux_amd64 -O /usr/local/bin/mhsendmail
RUN chmod +x /usr/local/bin/mhsendmail

# Install composer
RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/bin --filename=composer

# Install yarn
RUN npm install -g yarn

# REMOVE APT CACHES
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

# Verifie si le groupe oab_web existe et la crée s'il n'existe pas
RUN [ ! $(getent group oab_web) ] && groupadd -o --gid $GID oab_web || true

# User
RUN adduser --uid $UID --gid $GID oab_web
USER oab_web


# Export vendor bin to get Drush
ENV PATH="$PATH:/application/vendor/bin"
