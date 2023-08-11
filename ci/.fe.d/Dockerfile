FROM multirepo.orangeapplicationsforbusiness.com:5002/portail_obs/nginx-php/alpine-php8.1:latest


ADD --chown=nobody:www-data ./build /var/www/html/
COPY --chown=nobody:www-data ./config/sync /var/www/config/sync
COPY --chown=nobody:www-data ./config/config_split /var/www/html/config/config_split

RUN cp /bin/wkhtmltopdf /var/www/html/vendor/h4cc/wkhtmltopdf-amd64/bin/wkhtmltopdf-amd64

# Export vendor bin to get Drush
ENV PATH="$PATH:/var/www/html/vendor/bin"
