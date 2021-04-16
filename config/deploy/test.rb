set :stage, :test
set :branch, 'MEP_20200730'
server '10.36.204.17', domain: 'recetteclientrefonte.obs-ruby.build.620nm.net', user: 'oab_web'
set :deploy_to, '/var/www/test'
set :docker_file, '/etc/docker/server/test/docker-compose.yml'
