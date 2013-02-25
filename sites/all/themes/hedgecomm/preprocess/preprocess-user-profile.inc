<?php

/**
 * @file
 * Preprocess User Profile Page
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];
  $email = $account->mail;
  $email_text = check_markup($email);
  $variables['user_profile']['mail'] = array(
    '#prefix' => "<div class='field email field-label-inline'>"
      . "<div class='field-label'>" . t('E-mail') . ":</div>",
    '#markup' => $email_text,
    '#suffix' => "</div>",
    '#weight' => 100,
  );
}

