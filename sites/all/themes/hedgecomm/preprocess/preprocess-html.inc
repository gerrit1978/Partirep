<?php

/**
 * @file
 * Preprocess Fields
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_html(&$vars) {

  /** USERS **/
  if (arg(0) == 'user') {
    if (is_numeric(arg(1))) {
      $user = user_load(arg(1));
      $firstname_field = field_get_items('user', $user, 'field_user_firstname');
      $lastname_field = field_get_items('user', $user, 'field_user_lastname');

      $firstname = $firstname_field[0]['safe_value'];
      $lastname = $lastname_field[0]['safe_value'];

      $vars['head_title'] = $firstname . " " . $lastname . " | Team PartiRep";
    }
  }

}