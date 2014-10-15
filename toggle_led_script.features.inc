<?php
/**
 * @file
 * toggle_led_script.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function toggle_led_script_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function toggle_led_script_flag_default_flags() {
  $flags = array();
  // Exported flag: "Toggle Script".
  $flags['toggle_script'] = array(
    'entity_type' => 'node',
    'title' => 'Toggle Script',
    'global' => 1,
    'types' => array(
      0 => 'beaglebone_action',
    ),
    'flag_short' => 'Toggle On',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Toggle Off',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'toggle_led_script',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function toggle_led_script_node_info() {
  $items = array(
    'beaglebone_action' => array(
      'name' => t('Beaglebone Action'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
