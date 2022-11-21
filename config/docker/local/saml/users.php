<?php

$config = array(

  'admin' => array(
    'core:AdminPassword',
  ),

  'example-userpass' => array(
    'exampleauth:UserPass',
    'user1:user1pass' => array(
      'uid' => array('1'),
      'eduPersonAffiliation' => array('group1'),
      'mail' => 'user1@example.com',
      'LastName' => 'User 1',
      'FirstName' => 'User_firstname',
    ),
    'user2:user2pass' => array(
      'uid' => array('2'),
      'eduPersonAffiliation' => array('group2'),
      'mail' => 'user2@example.com',
      'LastName' => 'User 2',
      'FirstName' => 'User2_firstname',
    ),
    'stephanie:user1pass' => array(
      'uid' => array('3'),
      'eduPersonAffiliation' => array('group1'),
      'mail' => 'stephanie.jourdan@orange.com',
      'LastName' => 'JOURDAN',
      'FirstName' => 'Stéphanie',
    ),
    'test:test' => array(
      'uid' => array('4'),
      'eduPersonAffiliation' => array('group1'),
      'mail' => 'test@orange.com',
      'LastnLastNameame' => 'TEST',
      'FirstName' => 'Toto',
    ),
    'test1:test1' => array(
      'uid' => array('4'),
      'eduPersonAffiliation' => array('group1'),
      'mail' => 'test@orange.com',
      'LastName' => 'TEST1',
      'FirstName' => 'Toto1',
    ),
  ),

);
