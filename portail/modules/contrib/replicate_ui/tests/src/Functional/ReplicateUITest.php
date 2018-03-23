<?php

namespace Drupal\Tests\replicate_ui\Functional;

use Drupal\Core\Cache\Cache;
use Drupal\node\Entity\Node;
use Drupal\node\Entity\NodeType;
use Drupal\Tests\AssertHelperTrait;
use Drupal\Tests\BrowserTestBase;

/**
 * Tests the UI functionality.
 *
 * @group replicate
 */
class ReplicateUITest extends BrowserTestBase {

  use AssertHelperTrait;

  /**
   * {@inheritdoc}
   */
  public static $modules = ['replicate', 'replicate_ui', 'node', 'block'];

  /**
   * @var \Drupal\user\UserInterface
   */
  protected $user;

  /**
   * @var \Drupal\node\NodeInterface
   */
  protected $node;

  /**
   * {@inheritdoc}
   */
  protected function setUp() {
    parent::setUp();

    $this->user = $this->drupalCreateUser(['bypass node access', 'administer nodes', 'replicate entities']);
    $node_type = NodeType::create([
      'type' => 'page',
    ]);
    $node_type->save();
    $this->node = Node::create([
      'title' => 'test title',
      'type' => 'page',
    ]);
    $this->node->save();

    $this->placeBlock('local_tasks_block');
    $this->placeBlock('system_messages_block');
    $this->config('replicate_ui.settings')->set('entity_types', ['node'])->save();
    \Drupal::service('router.builder')->rebuild();
    Cache::invalidateTags(['entity_types']);
  }

  public function testFunctionality() {
    $this->drupalGet($this->node->toUrl());
    $this->assertSession()->pageTextNotContains('Replicate');

    $this->drupalLogin($this->user);
    $this->drupalGet($this->node->toUrl());
    $this->assertSession()->pageTextContains('Replicate');
    $this->assertSession()->statusCodeEquals(200);

    $this->getSession()->getPage()->clickLink('Replicate');
    $this->assertSession()->statusCodeEquals(200);

    $this->getSession()->getPage()->pressButton('Replicate');
    $this->getSession()->getPage()->getContent();
    $this->assertSession()->responseContains('<em class="placeholder">node</em> (<em class="placeholder">1</em>) has been replicated to id <em class="placeholder">2</em>!');
  }

}
