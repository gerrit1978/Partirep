<?php

function hedgecomm_alpha_preprocess_page(&$vars) {
  // get content type
  isset($vars['node']->type) ? $content_type = $vars['node']->type : $content_type = "";

	switch ($content_type) {
	  case 'working_paper':
	    $vars['title'] = "Working Paper<br /><span class='small'>" . $vars['node']->title . "</span>";
	    break;
	}
}