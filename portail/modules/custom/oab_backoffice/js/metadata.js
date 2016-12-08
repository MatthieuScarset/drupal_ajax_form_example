/**
 * @file metadata.js
 */
(function ($, Drupal) {
    /**
     * Registers behaviours related to view widget.
     */
    Drupal.behaviors.Metadata = {
        attach: function (context) {
            var $previewMetaTitle = $("#edit-field-meta-titre-0-value");
            $("#edit-title-0-value").keyup(function() {

                var maxTitleChar = $previewMetaTitle.attr("maxlength");
                if($previewMetaTitle.val().length < maxTitleChar)
                {
                    $previewMetaTitle.val( this.value )
                    $previewMetaTitle.attr("value" , this.value );
                }

            });

            var $previewMetaDesc = $("#edit-field-meta-descriptif-court-0-value");
            $("#edit-field-short-description-0-value").keyup(function() {

                var maxDescChar = $previewMetaDesc.attr("maxlength");
                if($previewMetaDesc.val().length < maxDescChar)
                {
                    $previewMetaDesc.val( this.value )
                    $previewMetaDesc.attr("value" , this.value );
                }

            });
        }
    };

}(jQuery, Drupal));
