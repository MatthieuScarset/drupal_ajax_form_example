(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {
    var sous_domaine = Drupal.settings.tealium.sous_domaine;
    var univers_affichage = Drupal.settings.tealium.univers_affichage;
    var sous_univers = Drupal.settings.tealium.sous_univers;
    var domaine_marketing = Drupal.settings.tealium.domaine_marketing;
    var code_univers = Drupal.settings.tealium.code_univers;
    var type_page = Drupal.settings.tealium.type_page;
    var titre_page = Drupal.settings.tealium.titre_page;
    var tealium_url = Drupal.settings.tealium.tealium_url;

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