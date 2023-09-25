FROM multirepo-oab.si.fr.intraorange:5002/portail_obs/base_images/php-fpm-local:latest

ARG UID
ARG GID

# NECESSAIRE POUR XDEBUG
ENV PHP_IDE_CONFIG = $PHP_IDE_CONFIG

# Verifie si le groupe oab_web existe et la crée s'il n'existe pas
RUN [ ! $(getent group oab_web) ] && groupadd -o --gid $GID oab_web || true

# User
RUN adduser --uid $UID --gid $GID oab_web
USER oab_web

# Export vendor bin to get Drush
ENV PATH="$PATH:/application/vendor/bin"
