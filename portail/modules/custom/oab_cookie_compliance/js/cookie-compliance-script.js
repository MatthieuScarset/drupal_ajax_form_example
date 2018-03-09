/**
 * Requête AJAX pour créer un cookie disant que l'utilisateur a validé le message
 */


jQuery(document).ready(function($) {

    $("#cookie-compliance-hide").click(function(){
        $.ajax({
            url: "/admin/oab-cookie-compliance/accept-cookie"
        }).done(function(data) {
            $("#cookie-compliance-block").hide();
            $("#cookie-compliance-block").html("");

            return false;
        }).fail(function() {

            return false;
        })
        ;

        //Return false => Evite d'aller vers le lien ('#') mise dans le href de la balise a
        // ie. -> Evite que le lien de la page ait un "#" à la fin après avoir cliqué sur ce bouton
        return false;
    });
});