#FROM multirepo.orangeapplicationsforbusiness.com:5002/ops_bdx/nginx-php/alpine-php8:8.0

FROM php:8.0

#ADD --chown=nobody:www-data ./Sources /var/www/html/
#COPY --chown=nobody:www-data ./config /var/www

ADD ./build /var/www/html/
COPY ./config /var/www

