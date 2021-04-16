<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


taxonomy_rename_vocab("Format d'éclairage", 'Insight type', 'insight_types', 'fr');

/**
	* Taxo Général FR
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


// ==============================================================
// ==============================================================
// ==============================================================
// ==============================================================
// ==============================================================

/**
 * Taxo Général EN
 */

// Profession.

taxonomy_rename_taxo('CEO', 'CEO', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Communication', 'Communication', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Digital Officer', 'Digital Officer', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Engineering', 'Engineering', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Finance', 'Finance', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Human Resources', 'Human Resources', 'jobs_profiles', 'en');
taxonomy_rename_taxo('IT & Technical', 'IT & Technical', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Legal', 'Legal', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Marketing & Commercial', 'Marketing & Commercial', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Operation/Customer Service', 'Operation/Customer Service', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Purchasing', 'Purchasing', 'jobs_profiles', 'en');
taxonomy_rename_taxo('R&D and innovation', 'R&D and innovation', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Sales Director', 'Sales', 'jobs_profiles', 'en');
taxonomy_rename_taxo('Security', 'Security', 'jobs_profiles', 'en');

// Industry.

taxonomy_rename_taxo('Public sector', 'Public sector', 'industries', 'en');
taxonomy_rename_taxo('Healthcare', 'Health', 'industries', 'en');
taxonomy_rename_taxo('Oil, gaz, mines', 'Resources and energy', 'industries', 'en');
taxonomy_rename_taxo('Transport  and Logistic', 'Transport', 'industries', 'en');
taxonomy_rename_taxo('Bank & insurance', 'Bank & insurance', 'industries', 'en');
taxonomy_rename_taxo('Manufacturing', 'Manufacturing', 'industries', 'en');
taxonomy_rename_taxo('Retail', 'Retail', 'industries', 'en');
taxonomy_rename_taxo('Automotive', 'Automotive', 'industries', 'en');
taxonomy_rename_taxo('Technology and business', 'Technology and business', 'industries', 'en');
taxonomy_rename_taxo('Tourism and personal services', 'Tourism and personal services', 'industries', 'en');

//Solutions.
taxonomy_rename_taxo('Business Innovation', 'Business Innovation', 'solutions', 'en');
taxonomy_rename_taxo('Collaborative Workspace', 'Collaborative Workspace', 'solutions', 'en');
taxonomy_rename_taxo('Cyber Defense', 'Cyber Defense', 'solutions', 'en');
taxonomy_rename_taxo('Enriched connectivity', 'Enriched connectivity', 'solutions', 'en');
taxonomy_rename_taxo('Enriched Customer relationship', 'Enriched Customer relationship', 'solutions', 'en');
taxonomy_rename_taxo('Flexible IT', 'Flexible IT', 'solutions', 'en');
taxonomy_rename_taxo('Services', 'Services', 'solutions', 'en');

// Region.
taxonomy_rename_taxo('Middle East & Africa', 'Middle East & Africa', 'regions', 'en');
taxonomy_rename_taxo('Asia Pacific', 'Asia Pacific', 'regions', 'en');
taxonomy_rename_taxo('Europe', 'Europe', 'regions', 'en');
taxonomy_rename_taxo('Latin America', 'Latin America', 'regions', 'en');
taxonomy_rename_taxo('North America', 'North America', 'regions', 'en');

/**
 * Blogs
 */

// Blog thematic.
taxonomy_rename_taxo('Big Data Analytics', 'Big Data', 'blog_thematics', 'en');
taxonomy_rename_taxo('Cloud Computing', 'Cloud', 'blog_thematics', 'en');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'blog_thematics', 'en');
taxonomy_rename_taxo('Consulting', 'Connectivity', 'blog_thematics', 'en');
taxonomy_rename_taxo('Customer Experience', 'Customer Experience', 'blog_thematics', 'en');
taxonomy_rename_taxo('Digital Transformation', 'Digital Transformation', 'blog_thematics', 'en');
taxonomy_rename_taxo('IoT', 'IoT', 'blog_thematics', 'en');
taxonomy_rename_taxo('Mobility', 'Mobility', 'blog_thematics', 'en');
taxonomy_rename_taxo('Security', 'Security', 'blog_thematics', 'en');
taxonomy_rename_taxo('News', 'News', 'blog_thematics', 'en');

// Blog formats.
taxonomy_rename_taxo('Article', 'Article', 'blog_formats', 'en');
taxonomy_rename_taxo('Brochure', 'Brochure', 'blog_formats', 'en');
taxonomy_rename_taxo('Case study', 'Case study', 'blog_formats', 'en');
taxonomy_rename_taxo('Guide', 'Guide', 'blog_formats', 'en');
taxonomy_rename_taxo('Infographic', 'Infographic', 'blog_formats', 'en');
taxonomy_rename_taxo('paper', 'White paper', 'blog_formats', 'en');

// Eclairages.
taxonomy_rename_taxo('Home', 'Home', 'thematic', 'en');
taxonomy_rename_taxo('Big data', 'Big data', 'thematic', 'en');
taxonomy_rename_taxo('Cloud', 'Cloud', 'thematic', 'en');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'thematic', 'en');
taxonomy_rename_taxo('Connectivity', 'Connectivity', 'thematic', 'en');
taxonomy_rename_taxo('Customer Experience', 'Customer Experience', 'thematic', 'en');
taxonomy_rename_taxo('Digital transformation', 'Digital Transformation', 'thematic', 'en');
taxonomy_rename_taxo('IoT', 'IoT', 'thematic', 'en');
taxonomy_rename_taxo('Mobility', 'Mobility', 'thematic', 'en');
taxonomy_rename_taxo('Security', 'Security', 'thematic', 'en');


/**
 * Documents
 */

// Documents format.
taxonomy_rename_taxo('Advice sheet', 'Advice sheet', 'document_types', 'en');
taxonomy_rename_taxo('Blog book', 'Blog book', 'document_types', 'en');
taxonomy_rename_taxo('Brochure', 'Brochure', 'document_types', 'en');
taxonomy_rename_taxo('Case study', 'Case study', 'document_types', 'en');
taxonomy_rename_taxo('Fact sheet', 'Fact sheet', 'document_types', 'en');
taxonomy_rename_taxo('eBook', 'eBook', 'document_types', 'en');
taxonomy_rename_taxo('Magazine', 'Magazine', 'document_types', 'en');
taxonomy_rename_taxo('Publication', 'Publication', 'document_types', 'en');
taxonomy_rename_taxo('White paper', 'White paper', 'document_types', 'en');
taxonomy_rename_taxo('Position paper', 'Position paper', 'document_types', 'en');

// Documents thematics.
taxonomy_rename_taxo('Big Data', 'Big Data', 'document_thematics', 'en');
taxonomy_rename_taxo('Cloud', 'Cloud', 'document_thematics', 'en');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'document_thematics', 'en');
taxonomy_rename_taxo('Customer Experience', 'Customer Experience', 'document_thematics', 'en');
taxonomy_rename_taxo('Digital Transformation', 'Digital Transformation', 'document_thematics', 'en');
taxonomy_rename_taxo('IoT', 'IoT', 'document_thematics', 'en');
taxonomy_rename_taxo('Mobility', 'Mobility', 'document_thematics', 'en');
taxonomy_rename_taxo('Security', 'Security', 'document_thematics', 'en');

/**
 * Magazine
 */
// Magazine thematics.
taxonomy_rename_taxo('Big Data', 'Big Data', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Cloud', 'Cloud', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Collaboration', 'Collaboration', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Connectivity', 'Connectivity', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Customer Experience', 'Customer Experience', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Digital Transformation', 'Digital Transformation', 'magazine_thematics', 'en');
taxonomy_rename_taxo('IoT', 'IoT', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Mobility', 'Mobility', 'magazine_thematics', 'en');
taxonomy_rename_taxo('Security', 'Security', 'magazine_thematics', 'en');

// Magazine types.
taxonomy_rename_taxo('Article', 'Article', 'magazine_types', 'en');
taxonomy_rename_taxo('Brochure', 'Brochure', 'magazine_types', 'en');
taxonomy_rename_taxo('Case study', 'Case study', 'magazine_types', 'en');
taxonomy_rename_taxo('Guide', 'Guide', 'magazine_types', 'en');
taxonomy_rename_taxo('Infographic', 'Infographic', 'magazine_types', 'en');
taxonomy_rename_taxo('White paper', 'White paper', 'magazine_types', 'en');


/**
 * Presse
 */
// Presse format.
taxonomy_rename_taxo('Press release', 'Press release', 'press_formats', 'en');
taxonomy_rename_taxo('Press kit', 'Press kit', 'press_formats', 'en');

/**
 * Eclairage
 */
// Eclairage format.
taxonomy_rename_taxo("Article", "Article", 'insight_types', 'en');
taxonomy_rename_taxo("Brochure", "Brochure", 'insight_types', 'en');
taxonomy_rename_taxo("Case study", "Case study", 'insight_types', 'en');
taxonomy_rename_taxo("Guide", "Guide", 'insight_types', 'en');
taxonomy_rename_taxo("Infographic", "Infographic", 'insight_types', 'en');
taxonomy_rename_taxo("White paper", "White paper", 'insight_types', 'en');


/**
 * Partners
 */
// Partner categories.
taxonomy_rename_taxo("System Integrators Partners", "System Integrators Partners", 'partner_types', 'en');
taxonomy_rename_taxo("Solutions Partners", "Solutions Partners", 'partner_types', 'en');
taxonomy_rename_taxo("Telco Partners", "Telco Partners", 'partner_types', 'en');
taxonomy_rename_taxo("Vertical Partners", "Vertical Partners", 'partner_types', 'en');

// Partner categories
taxonomy_rename_taxo("Asia Pacific", "Asia Pacific", 'geographics', 'en');
taxonomy_rename_taxo("Americas", "Americas", 'geographics', 'en');
taxonomy_rename_taxo("France Corporate", "France Corporate", 'geographics', 'en');
taxonomy_rename_taxo("France Mid-market", "France Mid-market", 'geographics', 'en');
taxonomy_rename_taxo("Europe", "Europe", 'geographics', 'en');
taxonomy_rename_taxo("Russia", "Russia", 'geographics', 'en');
taxonomy_rename_taxo("Middle-East & Africa", "Middle-East & Africa", 'geographics', 'en');

/**
 * Market segments.
 */
taxonomy_rename_taxo("SME", "SME", 'market_segments', 'en');
taxonomy_rename_taxo("mid market", "mid market", 'market_segments', 'en');
taxonomy_rename_taxo("high end market", "high end market", 'market_segments', 'en');
taxonomy_rename_taxo("key accounts", "key accounts", 'market_segments', 'en');
taxonomy_rename_taxo("Multinational", "Multinational", 'market_segments', 'en');

/**
 * Subhomes
 */
// Subhomes format.
taxonomy_rename_taxo("Blogs", "Blogs", 'subhomes', 'en');
taxonomy_rename_taxo("Case study", "Case study", 'subhomes', 'en');
taxonomy_rename_taxo("Library", "Library", 'subhomes', 'en');
taxonomy_rename_taxo("Magazine", "Magazine", 'subhomes', 'en');
taxonomy_rename_taxo("Partners", "Partners", 'subhomes', 'en');
taxonomy_rename_taxo("Products", "Products", 'subhomes', 'en');
taxonomy_rename_taxo("Newsroom", "Newsroom", 'subhomes', 'en');
