/**
 * @file metadata.js
 */
(function ($, Drupal) {
    /**
     * Registers behaviours related to view widget.

    Drupal.behaviors.Metadata = {
        attach: function (context) {
            var $previewMetaTitle = $("#edit-field-meta-title-0-value");
            $("#edit-title-0-value").keyup(function() {
                var maxTitleChar = $previewMetaTitle.attr("maxlength");
                if($previewMetaTitle.val().length < maxTitleChar)
                {
                    $previewMetaTitle.val( this.value )
                    $previewMetaTitle.attr("value" , this.value );
                }else{
                    $previewMetaTitle.val( this.value.substr(0, maxTitleChar) );
                }
            });

            var $previewMetaDesc = $("#edit-field-meta-description-0-value");
            $("#edit-field-highlight-0-value").keyup(function() {
                var maxDescChar = $previewMetaDesc.attr("maxlength");
                if($previewMetaDesc.val().length < (maxDescChar-1))
                {
                    $previewMetaDesc.val( this.value )
                    $previewMetaDesc.attr("value" , this.value );
                }else{
                    $previewMetaDesc.val( this.value.substr(0, maxDescChar) );
                }

            });
        }
    }; RUBYPORTAILOBS-3179 : désactivation de la fonctionnalité d'autocomplétion des champs metas */

}(jQuery, Drupal));
