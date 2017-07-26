<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


taxonomy_rename_vocab("Format d'éclairage", 'Insight type', 'insight_types', 'fr');

/**
	* Taxo Général
 */

// Metier

taxonomy_rename_taxo('Achat', 'Achat', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('CDO / Innovation', 'CDO / Innovation', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Communication', 'Communication', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Direction générale', 'Direction générale', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Finance', 'Finance', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Marketing', 'Marketing', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Opération / Intervention / Service client', 'Opération / Intervention / Service client', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Ressources humaines', 'Ressources humaines', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Sécurité', 'Sécurité', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Services généraux', 'Services généraux', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('SI / IT', 'SI / IT', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Tous métiers', 'Tous métiers', 'jobs_profiles', 'fr');
taxonomy_rename_taxo('Vente / Commercial', 'Vente / Commercial', 'jobs_profiles', 'fr');

// Secteur d'activité

taxonomy_rename_taxo('Automobile', 'Automobile', 'industries', 'fr');
taxonomy_rename_taxo('Banque et assurance', 'Banque et assurance', 'industries', 'fr');
taxonomy_rename_taxo('Collectivités locales', 'Collectivités locales', 'industries', 'fr');
taxonomy_rename_taxo('Commerce et distribution', 'Commerce et distribution', 'industries', 'fr');
taxonomy_rename_taxo('Education', 'Education', 'industries', 'fr');
taxonomy_rename_taxo('Industrie', 'Industrie', 'industries', 'fr');
taxonomy_rename_taxo('Ressources et énergie', 'Ressources et énergie', 'industries', 'fr');
taxonomy_rename_taxo('Santé', 'Santé', 'industries', 'fr');
taxonomy_rename_taxo('Secteur public', 'Secteur public', 'industries', 'fr');
taxonomy_rename_taxo('Services et technologies de l\'information', 'Services et technologies de l\'information', 'industries', 'fr');
taxonomy_rename_taxo('Smart Cities', 'Smart Cities', 'industries', 'fr');
taxonomy_rename_taxo('Tourisme et services aux particuliers', 'Tourisme et services aux particuliers', 'industries', 'fr');
taxonomy_rename_taxo('Transport', 'Transport', 'industries', 'fr');
taxonomy_rename_taxo('Tous secteurs', 'Tous secteurs', 'industries', 'fr');

//Solutions
taxonomy_rename_taxo('Connectivité enrichie', 'Connectivité enrichie', 'solutions', 'fr');
taxonomy_rename_taxo('Cyberdefense', 'Cyberdefense', 'solutions', 'fr');
taxonomy_rename_taxo('Espaces collaboratifs', 'Espaces collaboratifs', 'solutions', 'fr');
taxonomy_rename_taxo('Innovation au service du business', 'Innovation au service du business', 'solutions', 'fr');
taxonomy_rename_taxo('IT Flexible Mobile Workspace', 'IT Flexible Mobile Workspace', 'solutions', 'fr');
taxonomy_rename_taxo('Relation client enrichie', 'Relation client enrichie', 'solutions', 'fr');
taxonomy_rename_taxo('Service', 'Service', 'solutions', 'fr');

/**
 * Blogs
 */

// Blog thematic
taxonomy_rename_taxo('Big Data Analytics', 'IoT et Data Analytics', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Cloud Computing', 'Cloud Computing', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Consulting', 'Consulting', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Innovation', 'Innovation', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Mobilité ou Mobile', 'Mobile', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Relation Client', 'Relation Client', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Réseaux', 'Réseaux', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Santé', 'E-santé', 'blog_thematics', 'fr');
taxonomy_rename_taxo('Sécurité', 'Sécurité', 'blog_thematics', 'fr');
taxonomy_delete_taxo('IoT', 'blog_thematics', 'fr');

// Blog formats
taxonomy_rename_taxo('Actualités', 'Actualités', 'blog_formats', 'fr');
taxonomy_rename_taxo('Analyses (études)', 'Analyses - études', 'blog_formats', 'fr');
taxonomy_rename_taxo('Bonnes pratiques', 'Bonnes pratiques', 'blog_formats', 'fr');
taxonomy_rename_taxo('Experts', 'Experts', 'blog_formats', 'fr');
taxonomy_rename_taxo('Solutions', 'Solutions', 'blog_formats', 'fr');
taxonomy_rename_taxo('Témoignages', 'Témoignages', 'blog_formats', 'fr');
taxonomy_rename_taxo('Tendances', 'Tendances', 'blog_formats', 'fr');

// Eclairages
taxonomy_rename_taxo('Home', 'Home', 'thematic', 'fr');
taxonomy_rename_taxo('Big data - IoT', 'Big data - IoT', 'thematic', 'fr');
taxonomy_rename_taxo('Cloud', 'Cloud', 'thematic', 'fr');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'thematic', 'fr');
taxonomy_rename_taxo('Cybersecurité', 'Cybersecurité', 'thematic', 'fr');
taxonomy_rename_taxo('Expérience client', 'Expérience client', 'thematic', 'fr');
taxonomy_rename_taxo('Mobile', 'Mobile', 'thematic', 'fr');
taxonomy_rename_taxo('Réseaux', 'Réseaux', 'thematic', 'fr');
taxonomy_delete_taxo('Digital transformation', 'thematic', 'en');
taxonomy_delete_taxo('Transformation digitale', 'thematic', 'fr');


/**
 * Documents
 */

// Documents format
taxonomy_rename_taxo('Blog book', 'Blog book', 'document_types', 'fr');
taxonomy_rename_taxo('Brochure', 'Brochure', 'document_types', 'fr');
taxonomy_rename_taxo('Catalogue', 'Catalogue', 'document_types', 'fr');
taxonomy_rename_taxo('Document', 'Document', 'document_types', 'fr');
taxonomy_rename_taxo('E-book', 'E-book', 'document_types', 'fr');
taxonomy_rename_taxo('Livre blanc', 'Livre blanc', 'document_types', 'fr');
taxonomy_rename_taxo('Magazine', 'Magazine', 'document_types', 'fr');

// Documents thematics
taxonomy_rename_taxo('IoT et Data Analytics', 'IoT et Data Analytics', 'document_thematics', 'fr');
taxonomy_rename_taxo('Cloud Computing', 'Cloud Computing', 'document_thematics', 'fr');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'document_thematics', 'fr');
taxonomy_rename_taxo('Consulting', 'Consulting', 'document_thematics', 'fr');
taxonomy_rename_taxo('Innovation', 'Innovation', 'document_thematics', 'fr');
taxonomy_rename_taxo('Mobile', 'Mobile', 'document_thematics', 'fr');
taxonomy_rename_taxo('Relation Client', 'Relation Client', 'document_thematics', 'fr');
taxonomy_rename_taxo('Réseaux', 'Réseaux', 'document_thematics', 'fr');
taxonomy_rename_taxo('E-santé', 'E-santé', 'document_thematics', 'fr');
taxonomy_rename_taxo('Sécurité', 'Sécurité', 'document_thematics', 'fr');

/**
 * Magazine
 */
// Magazine thematics
taxonomy_rename_taxo('IoT et Data Analytics', 'IoT et Data Analytics', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Cloud Computing', 'Cloud Computing', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Consulting', 'Consulting', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Innovation', 'Innovation', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Mobile', 'Mobile', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Relation Client', 'Relation Client', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Réseaux', 'Réseaux', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('E-santé', 'E-santé', 'magazine_thematics', 'fr');
taxonomy_rename_taxo('Sécurité', 'Sécurité', 'magazine_thematics', 'fr');

// Magazine types
taxonomy_rename_taxo('Actualités', 'Actualités', 'magazine_types', 'fr');
taxonomy_rename_taxo('Analyses (études)', 'Analyses - études', 'magazine_types', 'fr');
taxonomy_rename_taxo('Bonnes pratiques', 'Bonnes pratiques', 'magazine_types', 'fr');
taxonomy_rename_taxo('Experts', 'Experts', 'magazine_types', 'fr');
taxonomy_rename_taxo('Solutions', 'Solutions', 'magazine_types', 'fr');
taxonomy_rename_taxo('Témoignages', 'Témoignages', 'magazine_types', 'fr');
taxonomy_rename_taxo('Tendances', 'Tendances', 'magazine_types', 'fr');


/**
 * Presse
 */
// Presse format
taxonomy_rename_taxo('Communiqué de presse', 'Communiqué de presse', 'press_formats', 'fr');
taxonomy_rename_taxo('Dossier de presse', 'Dossier de presse', 'press_formats', 'fr');

/**
 * Eclairage
 */
// Eclairage format
taxonomy_rename_taxo("Paroles d'experts", "Paroles d'experts", 'insight_types', 'fr');
taxonomy_rename_taxo("Interviews", "Interviews", 'insight_types', 'fr');
taxonomy_rename_taxo("Médiathèque", "Médiathèque", 'insight_types', 'fr');
taxonomy_rename_taxo("Paroles d'experts", "Paroles d'experts", 'insight_types', 'fr');
taxonomy_rename_taxo("Regards croisés", "Regards croisés", 'insight_types', 'fr');


/**
 * Partners
 */
// Partner categories
taxonomy_rename_taxo("Intégrateurs de systèmes", "Intégrateurs de systèmes", 'partner_types', 'fr');
taxonomy_rename_taxo("Solutions", "Solutions", 'partner_types', 'fr');
taxonomy_rename_taxo("Telco", "Telco", 'partner_types', 'fr');
taxonomy_rename_taxo("Verticaux", "Verticaux", 'partner_types', 'fr');

// Partner categories
taxonomy_rename_taxo("France Corporate", "France Corporate", 'geographics', 'fr');
taxonomy_rename_taxo("France MidMarket", "France MidMarket", 'geographics', 'fr');
taxonomy_rename_taxo("Europe", "Europe", 'geographics', 'fr');
taxonomy_rename_taxo("Amérique", "Amérique", 'geographics', 'fr');
taxonomy_rename_taxo("Moyen Orient", "Moyen Orient", 'geographics', 'fr');
taxonomy_rename_taxo("Asie Pacifique", "Asie Pacifique", 'geographics', 'fr');

/**
 * Market segments
 */
// Subhomes format
taxonomy_rename_taxo("PME", "PME", 'market_segments', 'fr');
taxonomy_rename_taxo("Milieu de marché", "Milieu de marché", 'market_segments', 'fr');
taxonomy_rename_taxo("Haut de marché", "Haut de marché", 'market_segments', 'fr');
taxonomy_rename_taxo("Grands comptes", "Grands comptes", 'market_segments', 'fr');
taxonomy_rename_taxo("Multinationale", "Multinationale", 'market_segments', 'fr');

/**
 * Subhomes
 */
// Subhomes format
taxonomy_rename_taxo("Blogs", "Blogs", 'subhomes', 'fr');
taxonomy_rename_taxo("Témoignages clients", "Témoignages clients", 'subhomes', 'fr');
taxonomy_rename_taxo("Médiathèque", "Médiathèque", 'subhomes', 'fr');
taxonomy_rename_taxo("Magazine", "Magazine", 'subhomes', 'fr');
taxonomy_rename_taxo("Partenaires", "Partenaires", 'subhomes', 'fr');
taxonomy_rename_taxo("Catalogue des offres", "Catalogue des offres", 'subhomes', 'fr');
taxonomy_rename_taxo("Presse", "Presse", 'subhomes', 'fr');

//throw new \Drupal\Core\Utility\UpdateException();