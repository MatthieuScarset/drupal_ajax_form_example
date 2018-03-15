/**
 * Requête AJAX pour créer un cookie disant que l'utilisateur a validé le message
 */


(function ($, Drupal, drupalSettings) {


    //Au chargement de la page, je regarde si le cookie existe.
    // S'il existe, je cache le block affiché (Au cas ou il ait été affiché alors que
    // le cookie existe --- 2nde verif)


    if (document.cookie.indexOf(drupalSettings.cookie_compliance.cookie_name_first_visit) > -1) {
        $('#' + drupalSettings.cookie_compliance.block_id).removeClass('hidden');
    }


    $("#cookie-compliance-hide").click(function(){
        $('#' + drupalSettings.cookie_compliance.block_id).hide();
        $('#' + drupalSettings.cookie_compliance.block_id).html("");

        //Return false => Evite d'aller vers le lien ('#') mise dans le href de la balise a
        // ie. -> Evite que le lien de la page ait un "#" à la fin après avoir cliqué sur ce bouton
        return false;
    });
})(window.jQuery, window.Drupal, drupalSettings);