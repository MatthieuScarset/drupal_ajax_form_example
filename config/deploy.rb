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
set :deploy_to, '/var/www'

# Default value for :scm is :git
# set :scm, :git

# Default value for :format is :pretty
# set :format, :pretty

# Default value for :log_level is :debug
# set :log_level, :debug

# Default value for :pty is false
# set :pty, true

# Default value for :linked_files is []
set :linked_files, fetch(:linked_files, []).push('portail/sites/default/settings.php')

# Default value for linked_dirs is []
set :linked_dirs, fetch(:linked_dirs, []).push('portail/sites/default/files')

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
set :keep_releases, 5

# release id is just the commit hash used to create the tarball.
#set :project_release_id, #{release_name}
# the same path is used local and remote... just to make things simple for who wrote this.
# see http://hugopl.github.io/2014/07/29/Capistrano-3-copy-deploy.html
set :project_tarball_path, "/tmp/#{fetch(:application)}.tar.gz"

# We create a Git Strategy and tell Capistrano to use it, our Git Strategy has a simple rule: Don't use git.
module NoGitStrategy
  def check
    true
  end

  def test
    # Check if the tarball was uploaded.
    test! " [ -f #{fetch(:project_tarball_path)} ] "
  end

  def clone
    true
  end

  def update
    true
  end

  def release
    # Unpack the tarball uploaded by deploy:upload_tarball task.
    context.execute "tar -xf #{fetch(:project_tarball_path)} -C #{release_path}"
    # Remove it just to keep things clean.
    context.execute :rm, fetch(:project_tarball_path)
  end

  def fetch_revision
    # Return the tarball release id, we are using the git hash of HEAD.
    fetch(:release_name)
  end
end

# Capistrano will use the module in :git_strategy property to know what to do on some Capistrano operations.
set :git_strategy, NoGitStrategy

#namespace :deploy do

  #after :restart, :clear_cache do
    #on roles(:web), in: :groups, limit: 3, wait: 10 do
      # Here we can do anything such as:
      # within release_path do
      #   execute :rake, 'cache:clear'
      # end
    #end
  #end

#end

namespace :deploy do
   desc 'Create and upload project tarball'
   task :upload_tarball do |task, args|
    tarball_path = fetch(:project_tarball_path)
    # This will create a project tarball from HEAD, stashed and not committed changes wont be released.
   `git archive -o #{tarball_path} HEAD`
    raise 'Error creating tarball.'if $? != 0

    on roles(:all) do
      upload! tarball_path, tarball_path
    end
   end
   
   desc 'Run dev deployment on each dev server'
   task :deploy_dev do
    #system("cap dev dev_bo deploy")
    system("cap dev deploy")
    #system("cap dev_bo deploy")
    #run_locally "cap dev dev-bo deploy"
   end
	
   desc 'Run recette deployment on each recette server'
   task :deploy_recette do
    system("cap recette recette-bo deploy")
   end
	
   desc 'Delete unnecessary files'
   task :delete_unnecessary_files do
    on roles(:all) do
    execute :rm, "-rf #{release_path}/scripts"
     execute :rm, "-rf #{release_path}/config"
     execute :rm, "-rf #{release_path}/.git"
     execute :rm, "-rf #{release_path}/public"
     execute :rm, "-rf #{release_path}/tmp"
     execute :rm, "-rf #{release_path}/Capfile"
     execute :rm, "-rf #{release_path}/log"
     execute :rm, "-rf #{release_path}/REVISION"
     execute :rm, "-rf #{release_path}/.gitignore"
     execute :rm, "-rf #{release_path}/README.md"
    end
   end
   
   desc 'Save the archive file'
   task :save_archive_file do
    on roles(:all) do
     execute :mkdir, "-p #{deploy_to}/shared/saved_archives"
     execute :tar, 'cfzp', "#{deploy_to}/shared/saved_archives/#{release_timestamp}.tar.gz", "-C #{releases_path} #{release_timestamp}"
    end
   end
   
   desc 'Run update commands on server'
   task :drush_update do
    on roles(:all) do
     execute "drush oab:updb --yes --root=#{release_path}/portail"
	 #execute "drush updb --yes --root=#{release_path}/portail"
	 #execute "drush entity-updates --yes --root=#{release_path}/portail"
	 #execute "drush config-import oab --yes --root=#{release_path}/portail"
	 execute "drush cr --root=#{release_path}/portail"
	 execute "ln -sf /home/oab_web/drupal7 #{release_path}/portail/drupal7"
	 execute "ln -sf /var/www/DVI/current/portail /var/www/current/portail/DVI"
    end
   end
end

before 'deploy:updating', 'deploy:upload_tarball'
after 'deploy:updating', 'deploy:delete_unnecessary_files'
after 'deploy:updating', 'deploy:save_archive_file'
after 'deploy:updating', 'deploy:drush_update'