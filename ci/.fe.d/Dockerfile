FROM multirepo.orangeapplicationsforbusiness.com:5002/ops_bdx/nginx-php/alpine-php8:8.0


ADD --chown=nobody: ./build /var/www/html/
COPY --chown=nobody: ./config/sync /var/www/config/sync
COPY --chown=nobody: ./config/config_split /var/www/config/config_split

# Export vendor bin to get Drush
ENV PATH="$PATH:/var/www/html/vendor/bin"
