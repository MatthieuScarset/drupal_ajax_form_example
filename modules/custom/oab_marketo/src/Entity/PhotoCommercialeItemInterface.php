<?php


namespace Drupal\oab_marketo\Entity;

use Drupal\Core\Entity\ContentEntityInterface;

/**
 * Provides an interface for defining Playlist entities.
 *
 * @ingroup oab_marketo
 */
interface PhotoCommercialeItemInterface extends ContentEntityInterface {

    public function getFieldsAsArray(): array;

    public function getRaisonSociale(): string;

    public function getSirenHq(): string;

    public function getIdent(): string;

    public function getSiren(): string;

    public function getStatutInsee(): bool;

    public function getDivisionCompte(): string;

    public function getDivisionSiren(): string;

    public function getCanal(): string;

    public function getSegmentation(): string;

    public function getSegmentMacro(): string;

    public function getAeEntreprise(): string;

    public function getAe(): string;
}
