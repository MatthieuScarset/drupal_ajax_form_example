FROM php:7.3-fpm

WORKDIR "/application"

# Fix debconf warnings upon build
ARG DEBIAN_FRONTEND=noninteractive

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
COPY --from=composer:2.0.11 /usr/bin/composer /usr/bin/composer
RUN mkdir /var/composer
ENV COMPOSER_HOME /var/composer
ENV COMPOSER_MEMORY_LIMIT -1
ENV COMPOSER_ALLOW_SUPERUSER 1

RUN ls -s

WORKDIR "/application"

#RUN composer install


## Unfortunately, adding the composer vendor dir to the PATH doesn't seem to work. So:
RUN ln -s $PWD/vendor/bin/drush /usr/local/bin/drush

