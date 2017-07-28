<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


taxonomy_rename_vocab("Thème de blog", 'Blog thematic', 'blog_thematics', 'fr');
taxonomy_rename_vocab("Format de blog", 'Blog type', 'blog_formats', 'fr');

taxonomy_rename_vocab("Type de document", 'Documents types', 'document_types', 'fr');
taxonomy_rename_vocab("Thème de document", 'Documents thematics', 'document_thematics', 'fr');

taxonomy_rename_vocab("Secteur d'activité", 'Industry', 'industries', 'fr');
taxonomy_rename_vocab("Eclairage", 'Insight', 'thematic', 'fr');
taxonomy_rename_vocab("Métier", 'Profession', 'jobs_profiles', 'fr');

taxonomy_rename_vocab("Segment de marché", 'Market segment', 'market_segments', 'fr');

taxonomy_rename_vocab("Catégorie", 'Category', 'partner_types', 'fr');
taxonomy_rename_vocab("Région", 'Region', 'regions', 'fr');
taxonomy_rename_vocab("Produits", 'Product', 'products', 'fr');
taxonomy_rename_vocab("Subhome", 'Subhome', 'subhomes', 'fr');
taxonomy_rename_vocab("Sous-familles", 'Sub-families', 'sub_families', 'fr');

taxonomy_rename_vocab("Format de magazine", 'Magazine type', 'magazine_types', 'fr');
taxonomy_rename_vocab("Thème de magazine", 'Magazine thematic', 'magazine_thematics', 'fr');

taxonomy_rename_vocab("Géographique", 'Geographic', 'geographics', 'fr');
taxonomy_rename_vocab("Pays", 'Country', 'countries', 'fr');

taxonomy_rename_vocab("Format de presse", 'Press type', 'press_formats', 'fr');

//throw new \Drupal\Core\Utility\UpdateException();