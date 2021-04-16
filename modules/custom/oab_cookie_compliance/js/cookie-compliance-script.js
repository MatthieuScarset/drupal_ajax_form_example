/**
 * Requête AJAX pour créer un cookie disant que l'utilisateur a validé le message
 */


(function ($, Drupal, drupalSettings) {


    //Au chargement de la page, je regarde si le cookie existe.
    // S'il n'existe pas, j'affiche le block (qui est en hidden au chargement de la page)
    var cookieExiste = true;

    // Si le cookie n'existe pas, j'affiche le bandeau
    if (document.cookie.indexOf(drupalSettings.cookie_compliance.cookie_name) === -1) {
        $('#' + drupalSettings.cookie_compliance.block_id).removeClass('hidden');
        cookieExiste = false;
    }

    //Si le cookie n'existe pas, je le crée
    if (!cookieExiste) {
        var today = new Date();
        var expire = new Date(today.getFullYear(),today.getMonth()+drupalSettings.cookie_compliance.expiration_nb_month+1, today.getDay());

        var expires_string = "expires="+ expire.toUTCString();
        document.cookie = drupalSettings.cookie_compliance.cookie_name + "=0" + ";" + expires_string + ";path=/";

    }


    $("#cookie-compliance-hide").click(function(){
        $('#' + drupalSettings.cookie_compliance.block_id).hide();
        $('#' + drupalSettings.cookie_compliance.block_id).html("");

        //Return false => Evite d'aller vers le lien ('#') mis dans le href de la balise a
        // ie. -> Evite que le lien de la page ait un "#" à la fin après avoir cliqué sur ce bouton
        return false;
    });
})(window.jQuery, window.Drupal, drupalSettings);