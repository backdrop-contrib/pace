<?php

/**
 * @file
 * Provide administration of PACE module.
 */

// Get the full config object

function pace_settings_form() {
  $config = config('pace.settings');

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
    '#default_value' => $config->get('pace_theme'),
  );

  $form['pace_load_on_admin_enabled'] = array(
    '#title' => t('Load in administration pages.'),
    '#description' => t('PACE is disabled by default on administration pages. Check to enable'),
    '#type' => 'checkbox',
    '#default_value' => $config->get('pace_load_on_admin_enabled'),
  );

  $form['pace_custom_color_enabled'] = array(
    '#title' => t('EXPERIMENTAL: Select custom color for PACE.'),
    '#description' => t('Override default PACE color. This setting will be outputted as CSS in your html head.<br>
      It will not be aggregated. NOT compatible with all PACE themes.'),
    '#type' => 'checkbox',
    '#default_value' => $config->get('pace_custom_color_enabled'),
  );

  $form['pace_custom_color_value'] = array(
    '#title' => t('Set your color using HEX notation.'),
    '#description' => t('Do not include the # sign.'),
    '#type' => 'textfield',
    '#default_value' => $config->get('pace_custom_color_value'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save PACE configuration'),
  );

  return $form;
}

/**
 * Submit handler for pace_settings_form().
 */
function pace_settings_form_submit($form, &$form_state) {
  $config = config('pace.settings');
  $config->set('pace_theme', $form_state['values']['pace_theme']);
  $config->set('pace_load_on_admin_enabled', $form_state['values']['pace_load_on_admin_enabled']);
  $config->set('pace_custom_color_enabled', $form_state['values']['pace_custom_color_enabled']);
  $config->set('pace_custom_color_value', $form_state['values']['pace_custom_color_value']);
  $config->save();
  backdrop_set_message(t('PACE configuration has been saved.'));
}
