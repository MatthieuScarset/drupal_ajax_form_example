<?php
/**
 * Création du role "Webform Business Analyst"
 * Rechargement des autres roles specifiques Webform pour ajout de droits
 */

## Webform SPOC Security
$role_spoc = \Drupal\user\Entity\Role::load('webform_business_analyst');
if ($role_spoc === null) {
    $role_spoc = \Drupal\user\Entity\Role::create(array('id' => 'webform_business_analyst', 'label' => 'Webform Business Analyst'));
    $role_spoc->save();
}

oabt_YmlImport('user.role.webform_business_analyst.yml');


# Je recharge qques config de roles pour ajouter des permissions
oabt_YmlImport('user.role.webform_manager.yml');
oabt_YmlImport('user.role.webform_business_owner.yml');
oabt_YmlImport('user.role.webform_admin.yml');
oabt_YmlImport('user.role.webform_spoc_securite.yml');

# Gestion des rôles qui peuvent être attribués à la création d'un nouvel utilisateur
oabt_YmlImport('roleassign.settings.yml');
