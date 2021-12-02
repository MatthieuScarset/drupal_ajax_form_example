FROM php:7.3-fpm

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
    zip \
    unzip \
    wget \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

# PHP iMagick
RUN apt-get update && apt-get install -y --no-install-recommends libmagickwand-dev imagemagick \
	&& pecl install imagick \
	&& docker-php-ext-enable imagick \
	&& apt-get clean; rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

# GD & MySql
RUN docker-php-ext-configure gd --with-gd --with-jpeg-dir --with-freetype-dir \
  && docker-php-ext-install gd pdo_mysql \
  && docker-php-ext-enable gd


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

# User
RUN adduser --uid $UID --gid $GID oab_web
USER oab_web

#Install drush
RUN composer global require drush/drush:9.7.3

# Export
ENV PATH="$PATH:/home/oab_web/.config/composer/vendor/bin"
