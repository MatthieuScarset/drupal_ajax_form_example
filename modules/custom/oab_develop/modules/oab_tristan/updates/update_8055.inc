<?php
$form = \Drupal\webform\Entity\Webform::load('telechargement_documents');

if ($form === null ) {
  include_once("update_8054.inc");
  $form = \Drupal\webform\Entity\Webform::load('telechargement_documents');
}


$newConfMess = "<p>Bonjour,</p>

<p>Nous avons le plaisir de vous communiquer le lien du document que vous venez de s&eacute;lectionner :<br />
<a href=\"[webform_submission:values:url_du_fichier]\" onmousedown=\"utag_link(utag_data.type_page, ‘Texte', ‘lien vers le PDF', '');\" target=\"_blank\">cliquez-ici.</a></p>

<p>Merci de votre visite sur notre site&nbsp;<a href=\"http://www.orange-business.com\" onmousedown=\"utag_link(utag_data.type_page, ‘Texte', ‘lien vers www.orange-business.com', '');\" style=\"line-height: 1.538em;\">www.orange-business.com</a></p>

<p>A tr&egrave;s bient&ocirc;t.<br />
L&#39;&eacute;quipe digitale</p>

<p>&nbsp;</p>

<p>Si vous souhaitez vous d&eacute;sincrire, <a href=\"http://marketing-content.orange-business.com/preferencecentreFR\" target=\"_blank\">cliquez ici</a> pour modifier vos pr&eacute;f&eacute;rences.</p>
";

$form->setSetting('confirmation_message', $newConfMess);
$form->save();

