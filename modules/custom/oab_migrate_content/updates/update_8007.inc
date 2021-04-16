<?php

//BLOGS
\Drupal::state()->delete('correspondence_cat_blog_to_thematic_blog');
$categBlog_to_thematic = get_correspondances_categoriesBlogD7_to_BlogThematicsD8();
\Drupal::state()->set('correspondence_cat_blog_to_thematic_blog', $categBlog_to_thematic);

//subhomes
$subhomes = get_correspondances_subhomes();
\Drupal::state()->set('subhomes_ids_for_migration', $subhomes);