(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {
    var sous_domaine = drupalSettings.tealium.sous_domaine;
    var univers_affichage = drupalSettings.tealium.univers_affichage;
    var sous_univers = drupalSettings.tealium.sous_univers;
    var domaine_marketing = drupalSettings.tealium.domaine_marketing;
    var code_univers = drupalSettings.tealium.code_univers;
    var type_page = drupalSettings.tealium.type_page;
    var titre_page = drupalSettings.tealium.titre_page;
    var tealium_url = drupalSettings.tealium.tealium_url;

    var utag_data={
      "sous_domaine" : sous_domaine,
      "univers_affichage" : univers_affichage,
      "sous_univers" : sous_univers,
      "domaine_marketing" : domaine_marketing ,
      "code_univers" : code_univers,
      "type_page" : type_page,
      "titre_page" : titre_page
    };

    (function(a,b,c,d){
      a=tealium_url;
      b=document;c="script";d=b.createElement(c);d.src=a;d.type="text/java"+c;d.async=true;
      a=b.getElementsByTagName(c)[0];a.parentNode.insertBefore(d,a);
    })();

    function utag_link(track_page, track_zone, track_nom, track_cible)
    {
      utag.link({
        "track_page": track_page,
        "track_zone": track_zone,
        "track_nom": track_nom,
        "track_cible": track_cible,
        "track_type_evt": "clic"
      });
    }
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);