#Avoid my updates to be executed

ev drupal_set_installed_schema_version('oab_tristan','8092')



#ev drupal_set_installed_schema_version('oab_tristan','8999')

#Enable modules
#pm-enable -y oab_orange_business_lounge
#pm-enable -y oab_cedric
#pm-enable -y oab_twitter


#Run updates
updb

#Import config to recreate hub fields
#cim -y

#Rerun my update to refill hub data
#ev drupal_set_installed_schema_version('oab_tristan','8092')
#updb

#Just clear cache to end the script
cr
#entity-updates
