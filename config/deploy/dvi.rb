set :stage, :dvi
set :branch, 'dvi'
set :deploy_to, '/var/www/DVI'
server '192.168.129.92', domain: 'orangepointcomrefonte.obs-ruby.proj.aql.fr', user: 'oab_web'