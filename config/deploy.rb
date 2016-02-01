set :stages,        %w(dev recette)
set :default_stage, "dev"
set :stage_dir,     "config/staging"
require 'capistrano/ext/multistage'

set :application, "obs"
set :repository,  "git@gitlab.aql.fr:obs-com/Sources.git"


# The domain and the path to your app directory
set :domain,    ""
set :deploy_to, "/var/www"

set :deploy_via,    :copy
set :copy_dir,      "/tmp"

set  :keep_releases,  5
set  :shared_files,      ["sites/default/settings.php"]
set  :shared_children,   ["sites/default/files"]

# USER
set :use_sudo,        false
set :user,            "oab_web"
set :group,           "www-data"
set :runner_group,    "www-data"


after "deploy:restart", "oab:create_index_file"

namespace :oab do
    desc 'Run oab tasks'
	task :create_index_file do
	  invoke_command "sh -c 'touch #{latest_release}/index.php'"
	  invoke_command "sh -c 'ln -s /var/www/shared/sites/default/settings.php #{latest_release}/portail/sites/default/settings.php'"
	  invoke_command "sh -c 'ln -s /var/www/shared/sites/default/files #{latest_release}/portail/sites/default/files'"
	  
	  invoke_command "sh -c 'chmod 755 #{latest_release}/portail/sites/default/'"
    end
end