<?php

namespace Drupal\oab_develop\Helpers;

use Drupal\locale\StringDatabaseStorage;


/**
 * Helper class pour ajouter des traductions via les updates
 */
class TranslationsHelper {

  public function __construct(
    private StringDatabaseStorage $storage
  ) {}


  /**
   * @param array $translations
   * @param string|null $context
   * @param string|null $type
   *
   * @code
   * $translations = [
   *   "source" => [
   *      "fr" => "traduction",
   *      "es" => "traducion"
   *    ]
   * ];
   * @endcode
   *
   * @throws \Drupal\locale\StringStorageException
   */
  public function translateMultiple(array $translations, ?string $context = null, ?string $type = null) {
    foreach ($translations as $source => $translations_per_language) {
      $this->translate($source, $translations_per_language, $context, $type);
    }
  }


  /**
   * @param string $lang
   * @param array $translations
   * @param string|null $context
   * @param string|null $type
   *
   * @code
   *
   * $translations = [
   *  "source_en" => "source_fr",
   *  "word" => "mot"
   * ];
   *
   * @endcode
   *
   * @throws \Drupal\locale\StringStorageException
   */
  public function translateOneLangue(string $lang, array $translations, ?string $context = null, ?string $type = null) {
    foreach ($translations as $source => $translation) {
      $this->translate($source, [$lang => $translation], $context, $type);
    }
  }

  /** Permet de sauvegarder les chaines de traduction
   *
   * @param string $source
   * @param array $translations
   * @param string|null $context
   * @param string|null $type
   *
   * @code
   * $translations = [
   *  "fr" => "traduction",
   *  "es" => "traducion"
   * ];
   *
   * @endcode
   *
   * @throws \Drupal\locale\StringStorageException
   */
  public function translate(string $source, array $translations, ?string $context = null, ?string $type = null) {

    $source_params = [
      'source' => $source
    ];

    if ($context) {
      $source_params += ['context' => $context];
    }

    $string = $this->storage->findString($source_params);
    if (is_null($string)) {
      $string = $this->storage->createString($source_params);
    }

    if ($type && ($string->isNew() || !in_array($type, array_keys($string->getLocations())))) {
      $string->addLocation($type, __DIR__);
    }

    $this->storage->save($string);

    foreach ($translations as $language => $translated_string) {
      // Create translation. If one already exists, it will be replaced.
      $this->storage->createTranslation([
        'lid' => $string->lid,
        'language' => $language,
        'translation' => $translated_string,
      ])->save();
    }
  }

}

