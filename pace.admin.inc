<?php

/**
 * @file
 * Provide administration of PACE module.
 */

function pace_admin_settings_form() {
  $form = array();
  $form['pace_theme'] = array(
    '#title' => t('Select the theme that PACE should use'),
    '#description' => t('Pace comes with a lot of themes for the progress loader. Please select the one that you prefer. You can see them all here: http://github.hubspot.com/pace/docs/welcome/'),
    '#type' => 'radios',
    '#options' => array(
      'pace-theme-minimal.css' => 'minimal',
      'pace-theme-barber-shop.css' => 'barber',
      'pace-theme-big-counter.css' => 'big counter',
      'pace-theme-bounce.css' => 'bounce',
      'pace-theme-center-atom.css' => 'center atom',
      'pace-theme-center-circle.css' => 'center circle',
      'pace-theme-center-radar.css' => 'center radar',
      'pace-theme-center-simple.css' => 'center simple',
      'pace-theme-corner-indicator.css' => 'corner indicator',
      'pace-theme-fill-left.css' => 'fill left',
      'pace-theme-flash.css' => 'flash',
      'pace-theme-flat-top.css' => 'flat top',
      'pace-theme-loading-bar.css' => 'loading bar',
      'pace-theme-mac-osx.css' => 'mac osx',
    ),
    '#default_value' => variable_get('pace_theme',array()),
  );
  return system_settings_form($form);
}
