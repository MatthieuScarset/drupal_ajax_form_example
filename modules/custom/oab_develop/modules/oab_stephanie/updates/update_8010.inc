<?php
/**
 * Ajout nouvelle vue Right Linked Content + placement du bloc
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.linked_content');
$config_group->setData(
	array (
		'uuid' => '2e4c7170-3e66-4f23-abe0-6147d7634f6d',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'node.type.country',
						2 => 'node.type.document',
						3 => 'node.type.full_html',
						4 => 'node.type.industry',
						5 => 'node.type.office',
						6 => 'node.type.partner',
						7 => 'node.type.product',
						8 => 'node.type.profile',
						9 => 'node.type.region',
						10 => 'node.type.webform',
					),
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
						2 => 'user',
					),
			),
		'id' => 'linked_content',
		'label' => 'Linked content',
		'module' => 'views',
		'description' => '',
		'tag' => '',
		'base_table' => 'node_field_data',
		'base_field' => 'nid',
		'core' => '8.x',
		'display' =>
			array (
				'default' =>
					array (
						'display_plugin' => 'default',
						'id' => 'default',
						'display_title' => 'Master',
						'position' => 0,
						'display_options' =>
							array (
								'access' =>
									array (
										'type' => 'perm',
										'options' =>
											array (
												'perm' => 'access content',
											),
									),
								'cache' =>
									array (
										'type' => 'tag',
										'options' =>
											array (
											),
									),
								'query' =>
									array (
										'type' => 'views_query',
										'options' =>
											array (
												'disable_sql_rewrite' => false,
												'distinct' => false,
												'replica' => false,
												'query_comment' => '',
												'query_tags' =>
													array (
													),
											),
									),
								'exposed_form' =>
									array (
										'type' => 'basic',
										'options' =>
											array (
												'submit_button' => 'Apply',
												'reset_button' => false,
												'reset_button_label' => 'Reset',
												'exposed_sorts_label' => 'Sort by',
												'expose_sort_order' => true,
												'sort_asc_label' => 'Asc',
												'sort_desc_label' => 'Desc',
											),
									),
								'pager' =>
									array (
										'type' => 'some',
										'options' =>
											array (
												'items_per_page' => 1,
												'offset' => 0,
											),
									),
								'style' =>
									array (
										'type' => 'default',
									),
								'row' =>
									array (
										'type' => 'entity:node',
										'options' =>
											array (
												'relationship' => 'none',
												'view_mode' => 'right_linked_content',
											),
									),
								'fields' =>
									array (
										'title' =>
											array (
												'id' => 'title',
												'table' => 'node_field_data',
												'field' => 'title',
												'settings' =>
													array (
														'link_to_entity' => true,
													),
												'plugin_id' => 'field',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'label' => '',
												'exclude' => false,
												'alter' =>
													array (
														'alter_text' => false,
														'text' => '',
														'make_link' => false,
														'path' => '',
														'absolute' => false,
														'external' => false,
														'replace_spaces' => false,
														'path_case' => 'none',
														'trim_whitespace' => false,
														'alt' => '',
														'rel' => '',
														'link_class' => '',
														'prefix' => '',
														'suffix' => '',
														'target' => '',
														'nl2br' => false,
														'max_length' => 0,
														'word_boundary' => true,
														'ellipsis' => true,
														'more_link' => false,
														'more_link_text' => '',
														'more_link_path' => '',
														'strip_tags' => false,
														'trim' => false,
														'preserve_tags' => '',
														'html' => false,
													),
												'element_type' => '',
												'element_class' => '',
												'element_label_type' => '',
												'element_label_class' => '',
												'element_label_colon' => true,
												'element_wrapper_type' => '',
												'element_wrapper_class' => '',
												'element_default_classes' => true,
												'empty' => '',
												'hide_empty' => false,
												'empty_zero' => false,
												'hide_alter_empty' => true,
												'click_sort_column' => 'value',
												'type' => 'string',
												'group_column' => 'value',
												'group_columns' =>
													array (
													),
												'group_rows' => true,
												'delta_limit' => 0,
												'delta_offset' => 0,
												'delta_reversed' => false,
												'delta_first_last' => false,
												'multi_type' => 'separator',
												'separator' => ', ',
												'field_api_classes' => false,
											),
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'type' =>
											array (
												'id' => 'type',
												'table' => 'node_field_data',
												'field' => 'type',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'not in',
												'value' =>
													array (
														'office' => 'office',
														'document' => 'document',
														'webform' => 'webform',
														'industry' => 'industry',
														'partner' => 'partner',
														'country' => 'country',
														'product' => 'product',
														'profile' => 'profile',
														'region' => 'region',
														'full_html' => 'full_html',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'type',
												'plugin_id' => 'bundle',
											),
									),
								'sorts' =>
									array (
										'changed' =>
											array (
												'id' => 'changed',
												'table' => 'node_field_data',
												'field' => 'changed',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'order' => 'DESC',
												'exposed' => false,
												'expose' =>
													array (
														'label' => '',
													),
												'granularity' => 'second',
												'entity_type' => 'node',
												'entity_field' => 'changed',
												'plugin_id' => 'date',
											),
									),
								'title' => 'Linked content',
								'header' =>
									array (
									),
								'footer' =>
									array (
									),
								'empty' =>
									array (
									),
								'relationships' =>
									array (
										'field_solution' =>
											array (
												'id' => 'field_solution',
												'table' => 'node__field_solution',
												'field' => 'field_solution',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => 'field_solution: Taxonomy term',
												'required' => true,
												'plugin_id' => 'standard',
											),
										'reverse__node__field_solution' =>
											array (
												'id' => 'reverse__node__field_solution',
												'table' => 'taxonomy_term_field_data',
												'field' => 'reverse__node__field_solution',
												'relationship' => 'field_solution',
												'group_type' => 'group',
												'admin_label' => 'field_solution',
												'required' => true,
												'entity_type' => 'taxonomy_term',
												'plugin_id' => 'entity_reverse',
											),
									),
								'arguments' =>
									array (
										'nid' =>
											array (
												'id' => 'nid',
												'table' => 'node_field_data',
												'field' => 'nid',
												'relationship' => 'reverse__node__field_solution',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'node',
												'default_argument_options' =>
													array (
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'entity_type' => 'node',
												'entity_field' => 'nid',
												'plugin_id' => 'node_nid',
											),
										'nid_1' =>
											array (
												'id' => 'nid_1',
												'table' => 'node_field_data',
												'field' => 'nid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'node',
												'default_argument_options' =>
													array (
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => true,
												'entity_type' => 'node',
												'entity_field' => 'nid',
												'plugin_id' => 'node_nid',
											),
									),
								'display_extenders' =>
									array (
									),
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'user.node_grants:view',
										4 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
					),
				'linked_content' =>
					array (
						'display_plugin' => 'block',
						'id' => 'linked_content',
						'display_title' => 'Block',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'block_description' => 'Linked content',
								'allow' =>
									array (
										'items_per_page' => false,
									),
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'user.node_grants:view',
										4 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
					),
			),
	)
);
$config_group->save(TRUE);

/**
 * config du block
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.views_block__linked_content_linked_content');
$config_group->setData(
	array (
		'uuid' => 'f3129188-2eb7-454f-a5fe-4fe95812ad37',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'views.view.linked_content',
					),
				'module' =>
					array (
						0 => 'ctools',
						1 => 'views',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'id' => 'views_block__linked_content_linked_content',
		'theme' => 'theme_boosted',
		'region' => 'sidebar',
		'weight' => 0,
		'provider' => NULL,
		'plugin' => 'views_block:linked_content-linked_content',
		'settings' =>
			array (
				'id' => 'views_block:linked_content-linked_content',
				'label' => '',
				'provider' => 'views',
				'label_display' => '0',
				'views_label' => '',
				'items_per_page' => 'none',
			),
		'visibility' =>
			array (
				'entity_bundle:node' =>
					array (
						'id' => 'entity_bundle:node',
						'bundles' =>
							array (
								'blog_post' => 'blog_post',
								'customer_story' => 'customer_story',
								'document' => 'document',
								'magazine' => 'magazine',
								'partner' => 'partner',
								'press_kit' => 'press_kit',
								'press_release' => 'press_release',
								'simple_page' => 'simple_page',
							),
						'negate' => false,
						'context_mapping' =>
							array (
								'node' => '@node.node_route_context:node',
							),
					),
			),
	)
);
$config_group->save(TRUE);