<?php

/*
 * Setting up du field related_display_view pour la taxo "Blogs" qui avait été oublié
 * dans l'update tristan_8004
 */

##on cherche l'Objet
$termsArray = taxonomy_term_load_multiple_by_name('Blogs', "subhomes");

##On boucle sur tous les termes trouvés (Magazine par exemple..)
foreach ($termsArray as $term_id => $termObject) {
  #related_display_view
  $termObject->set('field_related_display_view', 'page_blog');

  $termObject->save();

}