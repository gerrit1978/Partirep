<?php

/**
 * @file
 * Preprocess Fields
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_field(&$variables) {

  // preprocess download link for Working Paper document
  if ($variables['element']['#field_name'] == 'field_work_paper_document') {
    $path = $variables['items'][0]['#markup'];
    $variables['items'][0]['#prefix'] = "<div class='download-file'>";
    $variables['items'][0]['#suffix'] = "</div>";
    $variables['items'][0]['#markup'] = t('<a href="@url" target="_blank"><div class="hidden">download file</div><i class="icon-download icon-4x"></i></a>', array('@url' => $path));
  }

  // preprocess author(s) for Working Paper document
  if ($variables['element']['#field_name'] == 'field_work_paper_user') {
    
    $authors_output = array();
    
    // put all authors ("users") in one row
    $user_links = array();
    foreach ($variables['items'] as $item) {
      $href = $item['#href'];
      $user = $item['#options']['entity'];
      $firstname_field = field_get_items('user', $user, 'field_user_firstname');
      $lastname_field = field_get_items('user', $user, 'field_user_lastname');
      $firstname = $firstname_field[0]['safe_value'];
      $lastname = $lastname_field[0]['safe_value'];
      $user_links[] = l($lastname . " " . $firstname, $href);
    }
    
    $authors_output[] = implode(', ', $user_links);
    
    // put extra authors in one row - if available
    $node = $variables['element']['#object'];
    $extra_authors_field = field_get_items('node', $node, 'field_work_paper_user_extra');
    
    if (is_array($extra_authors_field) && count($extra_authors_field)) {
      $extra_authors = array();
      foreach ($extra_authors_field as $extra_author) {
        $extra_authors[] = $extra_author['safe_value'];
      }
      $authors_output[] = implode(', ', $extra_authors);
    }
    $final_output = implode(', ', $authors_output);
    unset($variables['items']);
    $variables['items'][0]['#markup'] = $final_output;
  }

  // preprocess google maps location
  if ($variables['element']['#field_name'] == 'field_event_location') {
    $items = $variables['items'];
    $variables['latitude'] = $items[0]['#location']['latitude'];
    $variables['longitude'] = $items[0]['#location']['longitude'];
    $variables['map_title'] = $variables['element']['#object']->title;
  }
  
  // preprocess authors for publication
  if ($variables['element']['#field_name'] == 'field_pub_authors') {
    $node = $variables['element']['#object'];
    $pub_extra_authors_field = field_get_items('node', $node, 'field_pub_extra_authors');
    if (is_array($pub_extra_authors_field) && count($pub_extra_authors_field)) {
      $extra_authors = array();
      foreach ($pub_extra_authors_field as $extra_author) {
        $extra_authors[] = $extra_author['safe_value'];
      }
      $output_extra_authors = implode(' ', $extra_authors);
      $variables['items'][] = array('#markup' => $output_extra_authors);
    }
  }
  
  // preprocess editors for publication
  if ($variables['element']['#field_name'] == 'field_pub_editors') {
    $node = $variables['element']['#object'];
    $pub_extra_editors_field = field_get_items('node', $node, 'field_pub_extra_editors');
    if (is_array($pub_extra_editors_field) && count($pub_extra_editors_field)) {
      $extra_editors = array();
      foreach ($pub_extra_editors_field as $extra_editor) {
        $extra_editors[] = $extra_editor['safe_value'];
      }
      $output_extra_editors = implode(' ', $extra_editors);
      $variables['items'][] = array('#markup' => $output_extra_editors);
    }
  }
  
}