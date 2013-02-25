<?php
/**
 * @file
 * Preprocess Page
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_page(&$vars) {

  /** NODES **/
  // get content type
  isset($vars['node']->type) ? $content_type = $vars['node']->type : $content_type = "";

  switch ($content_type) {
    case 'working_paper':
      $vars['title'] = "Working Paper<br /><span class='small'>" . $vars['node']->title . "</span>";
      break;
  }

  /** USERS **/
  if (arg(0) == 'user') {
    if (is_numeric(arg(1))) {
      $user = user_load(arg(1));
      $firstname_field = field_get_items('user', $user, 'field_user_firstname');
      $lastname_field = field_get_items('user', $user, 'field_user_lastname');

      $firstname = $firstname_field[0]['safe_value'];
      $lastname = $lastname_field[0]['safe_value'];

      $vars['title'] = $firstname . " " . $lastname;
    }
  }
}