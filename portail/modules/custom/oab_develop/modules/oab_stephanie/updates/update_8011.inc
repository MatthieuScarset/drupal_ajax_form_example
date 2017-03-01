<?php
/**
 * Ajout permission changement URL au Chief Editor
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.chief_editor');
$config_group->setData(
	array (
		'uuid' => '624e70dc-aa4a-409a-97e5-509e9e5f4bfb',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'chief_editor',
		'label' => 'Chief editor',
		'weight' => 3,
		'is_admin' => NULL,
		'permissions' =>
			array (
				0 => 'administer comments',
				1 => 'edit own comments',
				2 => 'post comments',
				3 => 'skip comment approval',
				4 => 'access comments',
				5 => 'access browser_modal_for_medias entity browser pages',
				6 => 'access media overview',
				7 => 'administer media',
				9 => 'create media',
				10 => 'delete any media',
				11 => 'delete media',
				12 => 'update any media',
				13 => 'update media',
				14 => 'view media',
				16 => 'access content overview',
				17 => 'administer nodes',
				18 => 'bypass node access',
				19 => 'delete all revisions',
				20 => 'revert all revisions',
				21 => 'view all revisions',
				22 => 'view own unpublished content',
				23 => 'create blog_post content',
				24 => 'delete any blog_post content',
				25 => 'delete own blog_post content',
				26 => 'delete blog_post revisions',
				27 => 'edit any blog_post content',
				28 => 'edit own blog_post content',
				29 => 'revert blog_post revisions',
				30 => 'view blog_post revisions',
				31 => 'create office content',
				32 => 'delete any office content',
				33 => 'delete own office content',
				34 => 'delete office revisions',
				35 => 'edit any office content',
				36 => 'edit own office content',
				37 => 'revert office revisions',
				38 => 'view office revisions',
				39 => 'create customer_story content',
				40 => 'delete any customer_story content',
				41 => 'delete own customer_story content',
				42 => 'delete customer_story revisions',
				43 => 'edit any customer_story content',
				44 => 'edit own customer_story content',
				45 => 'revert customer_story revisions',
				46 => 'view customer_story revisions',
				47 => 'create press_release content',
				48 => 'delete any press_release content',
				49 => 'delete own press_release content',
				50 => 'delete press_release revisions',
				51 => 'edit any press_release content',
				52 => 'edit own press_release content',
				53 => 'revert press_release revisions',
				54 => 'view press_release revisions',
				55 => 'create document content',
				56 => 'delete any document content',
				57 => 'delete own document content',
				58 => 'delete document revisions',
				59 => 'edit any document content',
				60 => 'edit own document content',
				61 => 'revert document revisions',
				62 => 'view document revisions',
				63 => 'create press_kit content',
				64 => 'delete any press_kit content',
				65 => 'delete own press_kit content',
				66 => 'delete press_kit revisions',
				67 => 'edit any press_kit content',
				68 => 'edit own press_kit content',
				69 => 'revert press_kit revisions',
				70 => 'view press_kit revisions',
				79 => 'create industry content',
				80 => 'delete any industry content',
				81 => 'delete own industry content',
				82 => 'delete industry revisions',
				83 => 'edit any industry content',
				84 => 'edit own industry content',
				85 => 'revert industry revisions',
				86 => 'view industry revisions',
				87 => 'create magazine content',
				88 => 'delete any magazine content',
				89 => 'delete own magazine content',
				90 => 'delete magazine revisions',
				91 => 'edit any magazine content',
				92 => 'edit own magazine content',
				93 => 'revert magazine revisions',
				94 => 'view magazine revisions',
				95 => 'create simple_page content',
				96 => 'delete any simple_page content',
				97 => 'delete own simple_page content',
				98 => 'delete simple_page revisions',
				99 => 'edit any simple_page content',
				100 => 'edit own simple_page content',
				101 => 'revert simple_page revisions',
				102 => 'view simple_page revisions',
				103 => 'create partner content',
				104 => 'delete any partner content',
				105 => 'delete own partner content',
				106 => 'delete partner revisions',
				107 => 'edit any partner content',
				108 => 'edit own partner content',
				109 => 'revert partner revisions',
				110 => 'view partner revisions',
				111 => 'create country content',
				112 => 'delete any country content',
				113 => 'delete own country content',
				114 => 'delete country revisions',
				115 => 'edit any country content',
				116 => 'edit own country content',
				117 => 'revert country revisions',
				118 => 'view country revisions',
				119 => 'create product content',
				120 => 'delete any product content',
				121 => 'delete own product content',
				122 => 'delete product revisions',
				123 => 'edit any product content',
				124 => 'edit own product content',
				125 => 'revert product revisions',
				126 => 'view product revisions',
				127 => 'create profile content',
				128 => 'delete any profile content',
				129 => 'delete own profile content',
				130 => 'delete profile revisions',
				131 => 'edit any profile content',
				132 => 'edit own profile content',
				133 => 'revert profile revisions',
				134 => 'view profile revisions',
				135 => 'create region content',
				136 => 'delete any region content',
				137 => 'delete own region content',
				138 => 'delete region revisions',
				139 => 'edit any region content',
				140 => 'edit own region content',
				141 => 'revert region revisions',
				142 => 'view region revisions',
				143 => 'create solution content',
				144 => 'delete any solution content',
				145 => 'delete own solution content',
				146 => 'delete solution revisions',
				147 => 'edit any solution content',
				148 => 'edit own solution content',
				149 => 'revert solution revisions',
				150 => 'view solution revisions',
				151 => 'access in-place editing',
				152 => 'replicate entities',
				154 => 'view scheduled update entities',
				155 => 'access administration pages',
				156 => 'view the administration theme',
				157 => 'access toolbar',
				158 => 'access tour',
				175 => 'access workbench',
				176 => 'view any unpublished content',
				177 => 'view moderation states',
				178 => 'view latest version',
				179 => 'use draft_draft transition',
				180 => 'use published_draft transition',
				181 => 'use needs_review_needs_review transition',
				182 => 'use published_published transition',
				183 => 'use needs_review_published transition',
				184 => 'use draft_published transition',
				185 => 'use draft_needs_review transition',
				186 => 'use needs_review_draft transition',
				187 => 'access files overview',
				188 => 'access shortcuts',
				189 => 'administer menu',
				190 => 'access user profiles',
				191 => 'use published_archived transition',
				192 => 'use archived_published transition',
				193 => 'access browse_medias_iframe entity browser pages',
				194 => 'access browser_file_modal entity browser pages',
				195 => 'access browse_media_modal entity browser pages',
				196 => 'use text format full_html',
				197 => 'assign chief_editor role',
				198 => 'assign webform_manager role',
				199 => 'assign roles',
				200 => 'administer url aliases',
				201 => 'create url aliases',
			),
	)
);
$config_group->save(TRUE);
