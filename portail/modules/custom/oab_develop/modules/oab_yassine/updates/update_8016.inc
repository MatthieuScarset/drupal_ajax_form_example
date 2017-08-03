<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


/**
 * Taxo Général RU
 */

// Industry. OK

taxonomy_rename_taxo('здравоохранениe', 'здравоохранениe', 'industries', 'ru');
taxonomy_rename_taxo('нефтегазовыe организации', 'нефтегазовыe организации', 'industries', 'ru');
taxonomy_rename_taxo('финансовыe организации', 'финансовыe организации', 'industries', 'ru');

//Solutions. OK
taxonomy_rename_vocab("Решения", 'Solutions', 'solutions', 'ru');

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
