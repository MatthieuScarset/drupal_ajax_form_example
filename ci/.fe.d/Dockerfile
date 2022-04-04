FROM multirepo.orangeapplicationsforbusiness.com:5002/ops_bdx/nginx-php/alpine-php8:8.0

USER nobody

ADD --chown=nobody:www-data ./build /var/www/html/
COPY --chown=nobody:www-data ./config/sync /var/www/config/sync
COPY --chown=nobody:www-data ./config/config_split /var/www/config/config_split

