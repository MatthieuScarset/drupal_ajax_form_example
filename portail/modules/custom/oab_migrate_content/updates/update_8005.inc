<?php

//on supprime les valeurs actuelles
\Drupal::state()->delete('correspondence_taxo_solution');
\Drupal::state()->delete('correspondence_taxo_industry');
\Drupal::state()->delete('correspondence_taxo_region');
\Drupal::state()->delete('correspondence_taxo_solution_to_thematic');

$solutions = get_correspondances_soltutionD7_to_solutionD8();
//correspondances des taxos Solution
\Drupal::state()->set('correspondence_taxo_solution', $solutions);

//BLOGS
$categBlog_to_thematic = get_correspondances_categoriesBlogD7_to_BlogThematicsD8();
//correspondances des taxos Solution
\Drupal::state()->set('correspondence_cat_blog_to_thematic_blog', $categBlog_to_thematic);

$categBlog_to_type = get_correspondances_categoriesBlogD7_to_BlogTypeD8();
//correspondances des taxos Solution
\Drupal::state()->set('correspondence_cat_blog_to_type_blog', $categBlog_to_type);

// INDUSTRIES
$industries = get_correspondances_industriesD7_to_industriesD8();
\Drupal::state()->set('correspondence_taxo_industry', $industries);

//REGIONS
$regions = get_correspondances_regionsD7_to_regionsD8();
\Drupal::state()->set('correspondence_taxo_region', $regions);

$solution_to_thematic = get_correspondances_soltutionD7_to_thematicD8();
\Drupal::state()->set('correspondence_taxo_solution_to_thematic', $solution_to_thematic);