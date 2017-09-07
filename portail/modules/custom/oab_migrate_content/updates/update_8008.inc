<?php

//MAG CATEG TO MAG FORMAT
$categMag_to_formatMag = get_correspondances_categoriesMagazineD7_to_MagazineFormatD8();
\Drupal::state()->set('correspondence_cat_mag_to_format_mag', $categMag_to_formatMag);

//format doc to doc format
$formatDoc_to_formatDoc = get_correspondances_formatDocumentD7_to_formatDocumentD8();
\Drupal::state()->set('correspondence_format_document', $formatDoc_to_formatDoc);

//BLOGS
$categBlog_to_thematic = get_correspondances_categoriesBlogD7_to_BlogThematicsD8();
\Drupal::state()->set('correspondence_cat_blog_to_thematic_blog', $categBlog_to_thematic);

$categBlog_to_type = get_correspondances_categoriesBlogD7_to_BlogTypeD8();
\Drupal::state()->set('correspondence_cat_blog_to_type_blog', $categBlog_to_type);