<?php

namespace Drupal\oab_pdf\Exception;

class SnappyGeneratorException extends SnappyException {
  public function __construct(?\Throwable $previous = NULL) {
    $message = "There was a problem generating PDF with Snappy";

    parent::__construct($message, previous: $previous);
  }

}

