#FROM phpdockerio/php71-fpm:latest
#FROM phpdockerio/php73-fpm:latest
FROM php:7.3-fpm

WORKDIR "/application"


# Fix debconf warnings upon build
ARG DEBIAN_FRONTEND=noninteractive

# Install selected extensions and other stuff
RUN apt-get update \
    && apt-get -y --no-install-recommends install \
	vim \
  libzip-dev \
	zip \
	unzip \
	wget \
	&& apt-get clean; rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

RUN apt-get update && apt-get install -y --no-install-recommends libmagickwand-dev imagemagick \
	&& pecl install imagick \
	&& docker-php-ext-enable imagick \
	&& docker-php-ext-enable zip \
	&& apt-get clean; rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*

RUN apt-get update \
	&& apt-get -y install git \
	&& apt-get clean; rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /usr/share/doc/*


RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer --version=1.10.19


RUN docker-php-ext-configure gd --with-gd --with-jpeg-dir --with-freetype-dir \
  && docker-php-ext-install gd pdo_mysql \
  && docker-php-ext-enable gd


## Mise en place Mailhog
RUN apt-get update \
	&& apt-get -y install wget \
	&& wget https://github.com/mailhog/mhsendmail/releases/download/v0.2.0/mhsendmail_linux_amd64 -O /usr/local/bin/mhsendmail \
	&& chmod +x /usr/local/bin/mhsendmail

#RUN service php7.3-fpm start
RUN groupmod -g 33 www-data
RUN groupadd -g 1001 oab_web
RUN useradd -r -u 1001 -g 1001 -G www-data oab_web
USER oab_web

WORKDIR "/application"
