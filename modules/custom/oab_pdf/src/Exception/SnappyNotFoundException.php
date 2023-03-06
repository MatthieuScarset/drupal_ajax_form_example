<?php

namespace Drupal\oab_pdf\Exception;

class SnappyNotFoundException extends SnappyException {
  public function __construct(string $path, ?\Throwable $previous = NULL) {
    $message = "Cannot found Snappy executable at $path";

    parent::__construct($message, 500, $previous);
  }

}

