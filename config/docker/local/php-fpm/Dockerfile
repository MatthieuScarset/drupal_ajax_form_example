FROM php:8.0-fpm

WORKDIR "/application"

# Fix debconf warnings upon build
ARG DEBIAN_FRONTEND=noninteractive
ARG UID
ARG GID

ADD php-ini-overrides.ini /usr/local/etc/php/conf.d/99-overrides.ini

# Install selected extensions and other stuff
RUN apt-get update \
    && apt-get -y --no-install-recommends install \
    vim \
    libzip-dev \
    zip \
    unzip \
    wget \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

# PHP iMagick
RUN apt-get update && apt-get install -y --no-install-recommends libmagickwand-dev imagemagick \
	&& pecl install imagick \
	&& docker-php-ext-enable imagick \
	&& apt-get clean; rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

RUN docker-php-ext-install zip

# GD & MySql
RUN docker-php-ext-configure gd --prefix=/usr --with-jpeg --with-freetype \
  && docker-php-ext-install gd pdo_mysql \
  && docker-php-ext-enable gd


# ADD SOME CACHE
RUN docker-php-ext-enable opcache
RUN pecl install apcu && docker-php-ext-enable apcu


# Install git
RUN apt-get update \
    && apt-get -y install git \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*


## Mise en place Mailhog
RUN wget https://github.com/mailhog/mhsendmail/releases/download/v0.2.0/mhsendmail_linux_amd64 -O /usr/local/bin/mhsendmail
RUN chmod +x /usr/local/bin/mhsendmail

# Install composer
RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/bin --filename=composer


# Install npm
RUN apt-get update && apt-get install -y nodejs npm

# Install yarn
RUN npm install -g yarn

# Verifie si le groupe oab_web existe et la crée s'il n'existe pas
RUN [ ! $(getent group oab_web) ] && groupadd -o --gid $GID oab_web || true

# User
RUN groupadd -g $GID oab_web
RUN adduser --uid $UID --gid $GID oab_web
USER oab_web


# Export vendor bin to get Drush
ENV PATH="$PATH:/application/vendor/bin"
