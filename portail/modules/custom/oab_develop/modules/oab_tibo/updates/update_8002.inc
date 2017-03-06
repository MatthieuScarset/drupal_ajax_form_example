<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.directaccessblock');
$config_group->set('settings.direct_access_custom_text.value', '
<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 bg bg_blue">
    <div class="col-lg-2 col-md-2 col-sm-1 col-xs-1"></div>
    <div id="slider_direct_access" class="col-lg-8 col-md-8 col-sm-10 col-xs-10">
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-wifi link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Blogs</a> 
              </i>
          </div>
      </div>
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-Collective_class_training link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Newsroom</a> 
              </i>
          </div>
      </div>
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-playmode_random link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Document</a> 
              </i>
          </div>
      </div>
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-hotel link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> News</a> 
              </i>
          </div>
      </div>
    </div>
    <div class="col-lg-2 col-md-2 col-sm-1 col-xs-1"></div>
  </div>
</div>');
$config_group->save(TRUE);
