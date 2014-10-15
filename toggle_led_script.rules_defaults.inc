<?php
/**
 * @file
 * toggle_led_script.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function toggle_led_script_default_rules_configuration() {
  $items = array();
  $items['rules_toggle_led_off'] = entity_import('rules_config', '{ "rules_toggle_led_off" : {
      "LABEL" : "Toggle LED Off",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "flag" ],
      "ON" : { "flag_unflagged_toggle_script" : [] },
      "DO" : [
        { "php_eval" : { "code" : "exec(\\u0022sudo \\/bin\\/echo 0 \\u003E \\/sys\\/class\\/gpio\\/gpio67\\/value\\u0022);" } }
      ]
    }
  }');
  $items['rules_toggle_led_on'] = entity_import('rules_config', '{ "rules_toggle_led_on" : {
      "LABEL" : "Toggle LED On",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules", "flag" ],
      "ON" : { "flag_flagged_toggle_script" : [] },
      "DO" : [
        { "php_eval" : { "code" : "exec(\\u0022sudo \\/bin\\/echo 1 \\u003E \\/sys\\/class\\/gpio\\/gpio67\\/value\\u0022);" } }
      ]
    }
  }');
  return $items;
}
