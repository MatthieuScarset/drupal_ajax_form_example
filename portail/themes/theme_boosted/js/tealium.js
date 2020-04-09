(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {
    var mkt_version = drupalSettings.marketo.mkt_version;
    var mkt_sous_domaine = "market automation";
    var mkt_univers_affichage = drupalSettings.marketo.mkt_univers_affichage;
    var mkt_pdf_name = $('.merkato_mkt_pdf_name').data('name');
    //var sous_domaine = drupalSettings.tealium.sous_domaine;
    //var univers_affichage = drupalSettings.tealium.univers_affichage;
    var sous_univers = drupalSettings.tealium.sous_univers;
    var domaine_marketing = drupalSettings.tealium.domaine_marketing;
    var code_univers = drupalSettings.tealium.code_univers;
    var type_page = drupalSettings.tealium.type_page;
    var titre_page = drupalSettings.tealium.titre_page;
    var custom_variable_key = drupalSettings.tealium.custom_variable_key;
    var custom_variable_value = drupalSettings.tealium.custom_variable_value;
    var custom_variable_key2 = drupalSettings.tealium.custom_variable_key2;
    var custom_variable_value2 = drupalSettings.tealium.custom_variable_value2;
    var tealium_url = drupalSettings.tealium.tealium_url;
    var profil_compte = drupalSettings.tealium.profil_compte_navigation;
    var type_langue = drupalSettings.tealium.type_langue;
    var erreur_code = drupalSettings.tealium.erreur_code;
    var url_appelee = drupalSettings.tealium.url_appelee;
    var url_referente = drupalSettings.tealium.url_referente;

    if (drupalSettings.tealium.view_title) {
      titre_page = drupalSettings.tealium.view_title;
    }

    var utag_data={
      "version": mkt_version,
      "sous_domaine": mkt_sous_domaine,
      "univers_affichage": mkt_univers_affichage,
      "id_article": mkt_pdf_name,
      //"sous_domaine" : sous_domaine,
      //"univers_affichage" : univers_affichage,
      "sous_univers" : sous_univers,
      "domaine_marketing" : domaine_marketing ,
      "code_univers" : code_univers,
      "type_page" : type_page,
      "titre_page" : titre_page,
      "profil_compte_navigation" : profil_compte,
      "profil_client" : profil_compte, // au cas où profil compte navigation ne fonctionne pas
      "type_langue" : type_langue,
      "erreur_code" : erreur_code,
      "url_appelee" : url_appelee,
      "url_referente" : url_referente
    };
    if (typeof custom_variable_key !== 'undefined' && typeof custom_variable_value !== 'undefined'){
      utag_data[custom_variable_key] = custom_variable_value;
    }
    if (typeof custom_variable_key2 !== 'undefined' && typeof custom_variable_value2 !== 'undefined'){
      utag_data[custom_variable_key2] = custom_variable_value2;
    }

    window.utag_data = utag_data;

    (function(a,b,c,d){
      a=tealium_url;
      b=document;c="script";d=b.createElement(c);d.src=a;d.type="text/java"+c;d.async=true;
      a=b.getElementsByTagName(c)[0];a.parentNode.insertBefore(d,a);
    })();

  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

function utag_link(track_page, track_zone, track_nom, track_cible)
{
  return utag.link({
    "track_page": track_page,
    "track_zone": track_zone,
    "track_nom": track_nom,
    "track_cible": track_cible,
    "track_type_evt": "clic"
  });
}
