# config valid only for current version of Capistrano
#lock '3.4.0'

set :application, 'obs'
set :repo_url, 'git@git-oab.si.fr.intraorange:obs-com/Sources.git'
set :stages, fetch(:stages, []).push('dev', 'test', 'integration')
set :default_stage, "dev"
set :local_user,  "oab_web"
set :group, "www-data"
set :runner_group, "www-data"

# Default branch is :master
# ask :branch, `git rev-parse --abbrev-ref HEAD`.chomp

# Default deploy_to directory is /var/www/my_app_name
set :deploy_to, '/var/www/ruby'

# Default value for :scm is :git
# set :scm, :git

# Default value for :format is :pretty
# set :format, :pretty

# Default value for :log_level is :debug
# set :log_level, :debug

# Default value for :pty is false
# set :pty, true

# Default value for linked_dirs is []
set :linked_dirs, fetch(:linked_dirs, []).push('sites/default')

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
set :keep_releases, 5

# Set dev as default. Other are defined in there own deploy/stage.rb
set :docker_compose, 'docker-compose-#{fetch:stage}.yml'
set :container_php, 'ruby-d9_php-fpm'
set :container_nginx, 'ruby-d9_webserver'
set :drush, '/application/vendor/bin/drush'
set :root_dir, '/application'


namespace :deploy do

   desc 'Save the archive file'
   task :save_archive_file do
    on roles(:all) do
     execute :mkdir, "-p #{deploy_to}/shared/saved_archives"
     execute :tar, 'cfzp', "#{deploy_to}/shared/saved_archives/#{release_timestamp}.tar.gz", "-C #{releases_path} #{release_timestamp}"
    end
   end

end


namespace :drupal do

   desc 'Install composer dependencies'
   task :run_composer do
    on roles(:all) do
      execute "docker exec -w /application #{fetch(:container_php)} composer install"
    end
   end


   desc 'Update Drupal'
   task :drush_update do
    on roles(:all) do
     #execute "docker exec -it #{fetch(:container_php)} drush oab:updb --yes"

     execute "docker exec #{fetch(:container_php)} #{fetch(:drush)} --root=#{fetch(:root_dir)} updb --yes"
     execute "docker exec #{fetch(:container_php)} #{fetch(:drush)} --root=#{fetch(:root_dir)} cr"
     execute "docker exec #{fetch(:container_php)} #{fetch(:drush)} --root=#{fetch(:root_dir)} cim --yes"
     execute "docker exec #{fetch(:container_php)} #{fetch(:drush)} --root=#{fetch(:root_dir)} cr"
    end
   end
end

namespace :docker do

  desc 'Stop project containers'
  task :stop_containers do
    on roles(:all) do
      execute "docker-compose -f #{current_path}/#{fetch(:docker_compose)} -p #{fetch(:application)}_#{fetch(:stage)} down"
      execute "docker stop webserver"
    end
  end

  desc 'Run project containers'
  task :run_containers do
    on roles(:all) do
      execute "docker-compose -f #{current_path}/#{fetch(:docker_compose)} -p #{fetch(:application)}_#{fetch(:stage)} up -d --build "
      execute "docker-compose -f /etc/docker/server/master/docker-compose.yml up -d"
    end
  end

end


before 'deploy:starting', 'docker:stop_containers'
after 'deploy:updating', 'deploy:save_archive_file'
after 'deploy:publishing', 'docker:run_containers'
after 'deploy:publishing', 'drupal:run_composer'
after 'deploy:publishing', 'drupal:drush_update'
