/**
 * @file
 * Javascript handling
 */
jQuery(document).ready(function($) {

  // jquery uniform
  $("select, input[type=submit]").uniform();
  
  // submit views exposed filters form (work packages)
  $(".view-working-papers .views-exposed-form .views-submit-button").hide();
  $(".view-working-papers .views-exposed-form select").change(function() {
    $(".view-working-papers .view-content").css("opacity", "0.4");
    $("#views-exposed-form-working-papers-page").css("opacity", "0.4").submit();
  });
  
  // submit views exposed filters form (publications)
  $(".view-publications .views-exposed-form .views-submit-button").hide();
  $(".view-publications .views-exposed-form select").change(function() {
    $(".view-publications .view-content").css("opacity", "0.4");
    $("#views-exposed-form-publications-page").css("opacity", "0.4").submit();
  });
  
});
