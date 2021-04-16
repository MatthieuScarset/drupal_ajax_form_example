<?php
use Drupal\locale\SourceString;

\Drupal::service('path.alias_storage')->save("/solutions", "/soluciones", "es");
\Drupal::service('path.alias_storage')->save("/solutions", "/solucoes", "pt-br");

\Drupal::service('path.alias_storage')->save("/subhome_blogs", "/blogs", "es");
\Drupal::service('path.alias_storage')->save("/subhome_blogs", "/blogs", "pt-br");

\Drupal::service('path.alias_storage')->save("/subhome_customers", "/nuestros-clientes", "es");
\Drupal::service('path.alias_storage')->save("/subhome_customers", "/nossos-clientes", "pt-br");

\Drupal::service('path.alias_storage')->save("/subhome_press", "/prensa", "es");
\Drupal::service('path.alias_storage')->save("/subhome_press", "/imprensa", "pt-br");

\Drupal::service('path.alias_storage')->save("/subhome_catalogue", "/producto", "es");
\Drupal::service('path.alias_storage')->save("/subhome_catalogue", "/produto", "pt-br");

\Drupal::service('path.alias_storage')->save("/subhome_documents", "/libreria", "es");
\Drupal::service('path.alias_storage')->save("/subhome_documents", "/mediateca", "pt-br");

####### Ajout des patterns
oabt_YmlImport('pathauto.pattern.blogs.yml');
oabt_YmlImport('pathauto.pattern.case_study_br.yml');
oabt_YmlImport('pathauto.pattern.case_study_es.yml');
oabt_YmlImport('pathauto.pattern.magazine_br.yml');
oabt_YmlImport('pathauto.pattern.magazine_es.yml');
oabt_YmlImport('pathauto.pattern.press_br.yml');
oabt_YmlImport('pathauto.pattern.press_es.yml');
oabt_YmlImport('pathauto.pattern.products_br.yml');
oabt_YmlImport('pathauto.pattern.products_es.yml');
oabt_YmlImport('pathauto.pattern.solution_br.yml');
oabt_YmlImport('pathauto.pattern.solution_es.yml');
oabt_YmlImport('pathauto.pattern.document_br.yml');
oabt_YmlImport('pathauto.pattern.document_es.yml');





$translations = array(
    array("source" => "distributors", "translation" => array("es" => "distribuidores", "pt-br" => "distribuidores")),
    array("source" => "partners", "translation" => array("es" => "Socios de negocio", "pt-br" => "parceiros")),
    array("source" => "magazine", "translation" => array("es" => "revista", "pt-br" => "revista")),
    array("source" => "Contact us", "translation" => array("es" => "Contáctenos", 'pt-br'=>"Contate-nos")),
    array("source" => "Our local offices", "translation" => array("es" => "Nuestras oficinas locales", 'pt-br'=>"Nossos escritórios")),

);


$storage = \Drupal::service('locale.storage');

foreach ($translations AS $translation) {
    $string = $storage->findString(array('source' => $translation['source']));
    if (is_null($string)) {
        $string = new SourceString();
        $string->setString($translation['source']);
        $string->setStorage($storage);
        $string->save();
    }

    foreach ($translation['translation'] AS $language => $translated_string) {
        // Create translation. If one already exists, it will be replaced.
        $translation = $storage->createTranslation(array(
            'lid' => $string->lid,
            'language' => $language,
            'translation' => $translated_string,
        ))->save();
    }
}