'use strict';

export const drupalSettings = window.drupalSettings;
export const Drupal = window.Drupal;

// Utilisation en function, car il est chargé par un script potentiellement après nous
export const Didomi = function () {
  return window.Didomi ?? [];
};

