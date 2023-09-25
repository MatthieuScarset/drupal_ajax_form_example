FROM multirepo-oab.si.fr.intraorange:5002/portail_obs/base_images/php-fpm-base:latest


# Copy confs
COPY ./nginx.conf /etc/nginx/sites-enabled/default
COPY ./entrypoint.sh /etc/entrypoint.sh

# Install nginx
RUN apt-get update -y \
    && apt-get install -y nginx

#############################################################################
#############################################################################
#############################################################################
## Copy Drupal

ADD ./build /application
#COPY ./config/sync /application/config/sync
#COPY ./config/config_split /application/config/config_split


# Export vendor bin to get Drush
ENV PATH="$PATH:/application/vendor/bin"


ENTRYPOINT ["/etc/entrypoint.sh"]
