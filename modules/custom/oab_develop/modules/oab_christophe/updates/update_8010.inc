<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('workbench_moderation.moderation_state_transition.unpublished_to_draft');
$config_group->setData(array(
  'uuid' => 'c312e466-e01b-4b90-9aae-1e258f193db8',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'workbench_moderation.moderation_state.draft',
          1 => 'workbench_moderation.moderation_state.unpublished',
        ),
    ),
  'id' => 'unpublished_to_draft',
  'label' => 'unpublished to draft',
  'stateFrom' => 'unpublished',
  'stateTo' => 'draft',
  'weight' => -11,
));
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('workbench_moderation.moderation_state_transition.unpublished_to_publish');
$config_group->setData(array(
  'uuid' => '24d727bb-e421-4217-8ba5-e78416315022',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'workbench_moderation.moderation_state.published',
          1 => 'workbench_moderation.moderation_state.unpublished',
        ),
    ),
  'id' => 'unpublished_to_publish',
  'label' => 'unpublished to publish',
  'stateFrom' => 'unpublished',
  'stateTo' => 'published',
  'weight' => -12,
));
$config_group->save();