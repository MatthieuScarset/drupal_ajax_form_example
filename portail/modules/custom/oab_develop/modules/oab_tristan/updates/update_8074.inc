<?php
use Symfony\Component\Yaml\Yaml;

$form = \Drupal\webform\Entity\Webform::load('contact_commercial');

if (null !== $form) {
    #Recuperation de l'array des élements du formulaire.
    $elements = Yaml::parse($form->get('elements'));

    if (!isset($elements['origin_product_name'])) {
        $origin_product = array(
            "#type" => "hidden",
            "#title" => "Page de provenance"
        );

        $elements['origin_product_name'] = $origin_product;


        $form->set('elements', $elements);
        $form->save();
    }
}