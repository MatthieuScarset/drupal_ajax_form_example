# config valid only for current version of Capistrano
lock '3.4.0'

set :application, 'obs'
set :repo_url, 'git@gitlab.aql.fr:obs-com/Sources.git'
set :stages, fetch(:stages, []).push('dev', 'recette')
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
#set :project_release_id, #{fetch(:release_name)}
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
  
    after :restart, :clear_cache do
	  #on roles(:web), in: :groups, limit: 3, wait: 10 do
	  #invoke_command "sh -c 'touch #{latest_release}/index.php'"
	  #invoke_command "sh -c 'ln -s /var/www/shared/sites/default/settings.php #{latest_release}/portail/sites/default/settings.php'"
	  #invoke_command "sh -c 'ln -s /var/www/shared/sites/default/files #{latest_release}/portail/sites/default/files'"
	  
	  #invoke_command "sh -c 'chmod 755 #{latest_release}/portail/sites/default/'"
    end
end

before 'deploy:updating', 'deploy:upload_tarball'
