<?php

function get_correspondances_industriesD7_to_industriesD8 () {
    $industries = array(
        //industries EN
        '16384' => array('tid_d7' => '16384', 'label_d7' => 'air transport', 'langcode' => 'en', 'label_d8' => 'Transport and Logistic', 'tid_D8' => ''),
        '16385' => array('tid_d7' => '16385', 'label_d7' => 'eGovernment', 'langcode' => 'en', 'label_d8' => 'Public sector', 'tid_D8' => ''),
        '16792' => array('tid_d7' => '16792', 'label_d7' => 'finance', 'langcode' => 'en', 'label_d8' => 'Bank & Insurance', 'tid_D8' => ''),
        '16355' => array('tid_d7' => '16355', 'label_d7' => 'health', 'langcode' => 'en', 'label_d8' => 'Healthcare', 'tid_D8' => ''),
        '16386' => array('tid_d7' => '16386', 'label_d7' => 'oil & gas', 'langcode' => 'en', 'label_d8' => 'Resources and energy', 'tid_D8' => ''),
        '16383' => array('tid_d7' => '16383', 'label_d7' => 'shipping', 'langcode' => 'en', 'label_d8' => 'Transport and Logistic', 'tid_D8' => ''),
        '16791' => array('tid_d7' => '16791', 'label_d7' => 'trading solutions', 'langcode' => 'en', 'label_d8' => 'Bank & Insurance', 'tid_D8' => ''),
        //industries FR
        '30442' => array('tid_d7' => '30442', 'label_d7' => 'banque et assurance', 'langcode' => 'fr', 'label_d8' => 'Banque et Assurance', 'tid_D8' => ''),
        '35324' => array('tid_d7' => '35324', 'label_d7' => 'Collectivités locales', 'langcode' => 'fr', 'label_d8' => 'Collectivités locales', 'tid_D8' => ''),
        '29947' => array('tid_d7' => '29947', 'label_d7' => 'Commerce et distribution', 'langcode' => 'fr', 'label_d8' => 'Commerce et distribution', 'tid_D8' => ''),
        '18337' => array('tid_d7' => '18337', 'label_d7' => 'e-santé', 'langcode' => 'fr', 'label_d8' => 'Santé', 'tid_D8' => ''),
        '18339' => array('tid_d7' => '18339', 'label_d7' => 'éducation', 'langcode' => 'fr', 'label_d8' => 'Education', 'tid_D8' => ''),
        '35118' => array('tid_d7' => '35118', 'label_d7' => "L'Industrie 4.0, l'usine connectée", 'langcode' => 'fr', 'label_d8' => 'Industrie', 'tid_D8' => ''),
        '35172' => array('tid_d7' => '35172', 'label_d7' => 'POWERPAGE FR for digitrans', 'langcode' => 'fr', 'label_d8' => '', 'tid_D8' => ''),
        '18342' => array('tid_d7' => '18342', 'label_d7' => 'secteur public', 'langcode' => 'fr', 'label_d8' => 'Secteur public', 'tid_D8' => ''),
        '31854' => array('tid_d7' => '31854', 'label_d7' => 'Smart Cities', 'langcode' => 'fr', 'label_d8' => 'Smart Cities', 'tid_D8' => ''),
        '20201' => array('tid_d7' => '20201', 'label_d7' => 'trading', 'langcode' => 'fr', 'label_d8' => 'Banque et assurance', 'tid_D8' => ''),
        '17712' => array('tid_d7' => '17712', 'label_d7' => 'transport', 'langcode' => 'fr', 'label_d8' => 'Transport logistique', 'tid_D8' => ''),
        //industries RU
        '25426' => array('tid_d7' => '25426', 'label_d7' => 'решения для здравоохранения', 'langcode' => 'ru', 'label_d8' => '', 'tid_D8' => ''),
        '25746' => array('tid_d7' => '25746', 'label_d7' => 'решения для нефтегазовых организаций', 'langcode' => 'ru', 'label_d8' => '', 'tid_D8' => ''),
        '25428' => array('tid_d7' => '25428', 'label_d7' => 'решения для финансовых организаций', 'langcode' => 'ru', 'label_d8' => '', 'tid_D8' => ''),
        //industries RU-EN
        '26742' => array('tid_d7' => '26742', 'label_d7' => 'finance', 'langcode' => 'ru-en', 'label_d8' => '', 'tid_D8' => ''),
        '25776' => array('tid_d7' => '25776', 'label_d7' => 'oil & gas', 'langcode' => 'ru-en', 'label_d8' => '', 'tid_D8' => ''),
    );
    return $industries;
}
