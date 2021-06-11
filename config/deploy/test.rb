set :stage, :test
set :branch, 'RUBYPORTAILOBS-3746'
server '10.36.204.17', domain: 'recetteclientrefonte.obs-ruby.build.620nm.net', user: 'oab_web'
set :deploy_to, '/var/www/drupal_9'

