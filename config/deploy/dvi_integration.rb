set :stage, :dvi_integration
set :branch, 'dvi'
set :deploy_to, '/var/www/DVI'
server '192.168.20.89', domain: 'recetteclientfinale.obs-ruby.build.620nm.net', user: 'oab_web'