pm-enable -y oab_orange_business_lounge
pm-enable -y oab_cedric
pm-enable -y oab_twitter

updb


# petit hack.... à supprimer le plus rapidement possible
ev drupal_set_installed_schema_version('oab_eddy','8005')
ev drupal_set_installed_schema_version('oab_riad','8004')
ev drupal_set_installed_schema_version('oab_cedric','8000')

cr
#entity-updates
