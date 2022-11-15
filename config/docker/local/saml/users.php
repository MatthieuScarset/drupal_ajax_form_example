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
      'email' => 'user1@example.com',
    ),
    'user2:user2pass' => array(
      'uid' => array('2'),
      'eduPersonAffiliation' => array('group2'),
      'email' => 'user2@example.com',
    ),
    'stephanie:user1pass' => array(
      'uid' => array('3'),
      'eduPersonAffiliation' => array('group1'),
      'Mail' => 'stephanie.jourdan@orange.com',
      'Lastname' => 'JOURDAN',
      'Firstname' => 'Stéphanie',
    ),
    'test:test' => array(
      'uid' => array('4'),
      'eduPersonAffiliation' => array('group1'),
      'Mail' => 'test@orange.com',
      'Lastname' => 'TEST',
      'Firstname' => 'Toto',
    ),
    'test1:test1' => array(
      'uid' => array('4'),
      'eduPersonAffiliation' => array('group1'),
      'Mail' => 'test@orange.com',
      'Lastname' => 'TEST1',
      'Firstname' => 'Toto1',
    ),
  ),

);
