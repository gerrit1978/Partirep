<?php

function hedgecomm_alpha_preprocess_field(&$variables) {
	if ($variables['element']['#field_name'] == 'field_work_paper_document') {
	  $path = $variables['items'][0]['#markup'];
	  $variables['items'][0]['#prefix'] = "<div class='download-file'>";
 	  $variables['items'][0]['#suffix'] = "</div>";
 	  $variables['items'][0]['#markup'] = t('<a href="@url" target="_blank"><div class="hidden">download file</div><i class="icon-download icon-4x"></i></a>', array('@url' => $path));
	}
}