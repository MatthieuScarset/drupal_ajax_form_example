<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


/**
 * Taxo Général RU
 */

// Metier/Jobs profiles.

taxonomy_delete_taxo('Directeur Commercial ou des ventes', 'jobs_profiles', 'fr');
taxonomy_delete_taxo('Directeur de la Communication', 'jobs_profiles', 'fr');
taxonomy_delete_taxo('Directeur Général (DG)', 'jobs_profiles', 'fr');
taxonomy_delete_taxo('Directeur Marketing', 'jobs_profiles', 'fr');
taxonomy_delete_taxo('DRH', 'jobs_profiles', 'fr');
taxonomy_delete_taxo('DSI', 'jobs_profiles', 'fr');

taxonomy_delete_taxo('CEO', 'jobs_profiles', 'en');
taxonomy_delete_taxo('Chief Marketing Officer (CMO)', 'jobs_profiles', 'en');
taxonomy_delete_taxo('HR Director or VP', 'jobs_profiles', 'en');
taxonomy_delete_taxo('Sales Director', 'jobs_profiles', 'en');


taxonomy_rename_taxo('R&D and innovation', 'R&D and Innovation', 'jobs_profiles', 'en');


//Solutions.
taxonomy_rename_taxo('Cyber défense', 'Cyberdefense', 'solutions', 'fr');

taxonomy_rename_taxo('Business innovation', 'Business Innovation', 'solutions', 'en');
taxonomy_rename_taxo('Cyber defense', 'Cyber Defense', 'solutions', 'en');
taxonomy_rename_taxo('Enriched customer relationships', 'Enriched Customer relationships', 'solutions', 'en');

// Industries.
taxonomy_delete_taxo('Commerce', 'industries', 'fr');
taxonomy_delete_taxo('Financial Services', 'industries', 'en');

taxonomy_delete_taxo('Industrie', 'industries', 'fr');
taxonomy_rename_taxo('Industrie / Campus numérique', 'Industrie', 'industries', 'fr');

taxonomy_delete_taxo('Transport', 'industries', 'fr');
taxonomy_rename_taxo('Transport logistique', 'Transport', 'industries', 'fr');

taxonomy_delete_taxo('Transport', 'industries', 'en');
taxonomy_rename_taxo('Transport  and Logistic', 'Transport', 'industries', 'en');

taxonomy_delete_taxo('Oil, gaz, mines', 'industries', 'en');
taxonomy_delete_taxo('MOFA’s', 'industries', 'en');

taxonomy_rename_taxo('Technology and business', 'Technology and business services', 'industries', 'en');


// Partners
taxonomy_delete_taxo('Telco', 'partner_types', 'en');
taxonomy_delete_taxo('Solutions', 'partner_types', 'en');

taxonomy_delete_taxo('Intégrateurs de systèmes', 'industries', 'fr');
taxonomy_rename_taxo('Inégrateurs de Systèmes', 'Intégrateurs de systèmes', 'partner_types', 'fr');

taxonomy_delete_taxo('Vertical', 'partner_types', 'en');

//Subhomes
taxonomy_delete_taxo('Témoignages clients', 'subhomes', 'fr');
taxonomy_rename_taxo('Cas clients', 'Témoignages clients', 'subhomes', 'fr');
taxonomy_delete_taxo('Case study', 'subhomes', 'en');
taxonomy_delete_taxo('Case studies', 'subhomes', 'en');
taxonomy_rename_taxo('Customer Stories', 'Case studies', 'subhomes', 'en');

taxonomy_delete_taxo('Catalogue des offres', 'subhomes', 'fr');
taxonomy_rename_taxo('Catalogue', 'Catalogue des offres', 'subhomes', 'fr');

taxonomy_delete_taxo('Newsroom', 'subhomes', 'en');
taxonomy_rename_taxo('Press', 'Newsroom', 'subhomes', 'en');

taxonomy_delete_taxo('Portfolio', 'subhomes', 'en');

taxonomy_rename_taxo('Témoignages', 'Témoignages',  'insight_types', 'fr');

// Regions
taxonomy_delete_taxo('Africa', 'regions', 'en');

taxonomy_delete_taxo('Middle East & Africa', 'regions', 'en');
taxonomy_rename_taxo('Middle East', 'Middle East & Africa',  'regions', 'en');
taxonomy_delete_taxo('Russia', 'regions', 'en');


taxonomy_delete_taxo('Afrique', 'regions', 'fr');
taxonomy_delete_taxo('Amerique du Nord', 'regions', 'fr');
taxonomy_delete_taxo('Amerique Latine', 'regions', 'fr');
taxonomy_delete_taxo('Asie Pacifique', 'regions', 'fr');
taxonomy_delete_taxo('Europe', 'regions', 'fr');
taxonomy_delete_taxo('Moyen Orient', 'regions', 'fr');
taxonomy_delete_taxo('Russie', 'regions', 'fr');

//Insight Thematic

taxonomy_delete_taxo('Home', 'thematic', 'fr');
taxonomy_delete_taxo('Home', 'thematic', 'en');



taxonomy_rename_taxo('Аудио- и видеоконференции', 'Аудио- и видеоконференции', 'solutions', 'ru');
taxonomy_rename_taxo('Облачные вычисления', 'Облачные вычисления', 'solutions', 'ru');
taxonomy_rename_taxo('Безопасность', 'Безопасность', 'solutions', 'ru');
taxonomy_rename_taxo('Голосовые услуги', 'Голосовые услуги', 'solutions', 'ru');
taxonomy_rename_taxo('Контакт-центр', 'Контакт-центр', 'solutions', 'ru');
taxonomy_rename_taxo('Корпоративные сети', 'Корпоративные сети', 'solutions', 'ru');
taxonomy_rename_taxo('Унифицированные коммуникации', 'Унифицированные коммуникации', 'solutions', 'ru');
taxonomy_rename_taxo('Мобильность', 'Мобильность', 'solutions', 'ru');

// Solutions RU-EN
taxonomy_rename_taxo('Cloud Computing', 'Cloud Computing', 'solutions', 'ru-en');
taxonomy_rename_taxo('Conferencing', 'Conferencing', 'solutions', 'ru-en');
taxonomy_rename_taxo('Connectivity', 'Connectivity', 'solutions', 'ru-en');
taxonomy_rename_taxo('Contact Centers', 'Contact Centers', 'solutions', 'ru-en');
taxonomy_rename_taxo('Mobility', 'Mobility', 'solutions', 'ru-en');
taxonomy_rename_taxo('Security', 'Security', 'solutions', 'ru-en');
taxonomy_rename_taxo('Unified Communications', 'Unified Communications', 'solutions', 'ru-en');


// Region - ccrrection de l'update 8015
taxonomy_rename_taxo('Middle East & Africa', 'Middle East & Africa', 'regions', 'en');
taxonomy_rename_taxo('Asia Pacific', 'Asia Pacific', 'regions', 'en');
taxonomy_rename_taxo('Europe', 'Europe', 'regions', 'en');
taxonomy_rename_taxo('Latin America', 'Latin America', 'regions', 'en');
taxonomy_rename_taxo('North America', 'North America', 'regions', 'en');

/**
 * Blogs
 */

// Blog thematic.
taxonomy_rename_taxo('Безопасность', 'Безопасность', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Голосовые услуги', 'Голосовые услуги', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Индустрия', 'Индустрия', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Корпоративные сети', 'Корпоративные сети', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Мобильность', 'Мобильность', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Облачные вычисления', 'Облачные вычисления', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Унифицированные коммуникации', 'Унифицированные коммуникации', 'blog_thematics', 'ru');
taxonomy_rename_taxo('Управление ИТ', 'Управление ИТ', 'blog_thematics', 'ru');

/**
 * Presse
 */
// Presse format.

taxonomy_rename_vocab("Новости", 'Press type', 'press_formats', 'ru');

taxonomy_rename_taxo('Пресс-релиз', 'Пресс-релиз', 'press_formats', 'ru');
taxonomy_rename_taxo('Press release', 'Press release', 'press_formats', 'ru-en');

/**
 * Countries EN
 */
taxonomy_rename_taxo('Australia & New Zealand', 'Australia & New Zealand', 'countries', 'en');
taxonomy_rename_taxo('Austria', 'Austria', 'countries', 'en');
taxonomy_rename_taxo('Benelux', 'Benelux', 'countries', 'en');
taxonomy_rename_taxo('China', 'China', 'countries', 'en');
taxonomy_rename_taxo('France', 'France', 'countries', 'en');
taxonomy_rename_taxo('Germany', 'Germany', 'countries', 'en');
taxonomy_rename_taxo('Hong Kong', 'Hong Kong', 'countries', 'en');
taxonomy_rename_taxo('India', 'India', 'countries', 'en');
taxonomy_rename_taxo('Italy', 'Italy', 'countries', 'en');
taxonomy_rename_taxo('Japan', 'Japan', 'countries', 'en');
taxonomy_rename_taxo('Korea', 'Korea', 'countries', 'en');
taxonomy_rename_taxo('Russia', 'Russia', 'countries', 'en');
taxonomy_rename_taxo('South Asia', 'South Asia', 'countries', 'en');
taxonomy_rename_taxo('Switzerland', 'Switzerland', 'countries', 'en');
taxonomy_rename_taxo('UK', 'UK', 'countries', 'en');
