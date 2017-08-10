<?php

//on supprime les valeurs actuelles
\Drupal::state()->delete('correspondence_taxo_solution');
\Drupal::state()->delete('correspondence_taxo_industry');
\Drupal::state()->delete('correspondence_taxo_region');
\Drupal::state()->delete('correspondence_taxo_solution_to_thematic');


$solutions = get_correspondances_soltutionD7_to_solutionD8();
\Drupal::state()->set('correspondence_taxo_solution', $solutions);

//BLOGS
$categBlog_to_thematic = get_correspondances_categoriesBlogD7_to_BlogThematicsD8();
\Drupal::state()->set('correspondence_cat_blog_to_thematic_blog', $categBlog_to_thematic);

$categBlog_to_type = get_correspondances_categoriesBlogD7_to_BlogTypeD8();
\Drupal::state()->set('correspondence_cat_blog_to_type_blog', $categBlog_to_type);

// INDUSTRIES
$industries = get_correspondances_industriesD7_to_industriesD8();
\Drupal::state()->set('correspondence_taxo_industry', $industries);

//REGIONS
$regions = get_correspondances_regionsD7_to_regionsD8();
\Drupal::state()->set('correspondence_taxo_region', $regions);

$solution_to_thematic = get_correspondances_soltutionD7_to_thematicD8();
\Drupal::state()->set('correspondence_taxo_solution_to_thematic', $solution_to_thematic);

//MAG CATEG TO MAG FORMAT
$categMag_to_formatMag = get_correspondances_categoriesMagazineD7_to_MagazineFormatD8();
\Drupal::state()->set('correspondence_cat_mag_to_format_mag', $categMag_to_formatMag);

//Solution to mag theme
$solution_to_themeMag = get_correspondances_solutionsD7_to_MagazineThematicD8();
\Drupal::state()->set('correspondence_solution_to_theme_mag', $solution_to_themeMag);

//solution to doc theme
$solution_to_themeDoc = get_correspondances_solutionsD7_to_DocumentThematicD8();
\Drupal::state()->set('correspondence_solution_to_theme_doc', $solution_to_themeDoc);

//format doc to doc format
$formatDoc_to_formatDoc = get_correspondances_formatDocumentD7_to_formatDocumentD8();
\Drupal::state()->set('correspondence_format_document', $formatDoc_to_formatDoc);

$press_formats = get_correspondances_press_formats();
\Drupal::state()->set('press_format_for_migration', $press_formats);
