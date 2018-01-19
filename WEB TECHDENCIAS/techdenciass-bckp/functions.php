<!-- Templete for displaying all the global functions of our theme -->
<?php

//  Enable support for the Post Thumbnails on the posts and pages
     
        add_theme_support('post-thumbnails'); 
        
    
//  Enable support for the Thumbanils and Featured images, changing size
    add_image_size('techdencias-featured-image',2000,1200,true);
    add_image_size('techdencias-thumbnails-image',100,100,true);
//  Dinamic menus
    register_nav_menus( array(
        'top' => __('Top Menu','techdencias'),
        'footer' => __('Footer Menu','techdencias')
    ) );
    
//  Add classes to the main menu
    function techdencias_menu_classes($classes,$item,$args){
        if($args -> theme-location == 'top'){ $classes[] = 'list-inline-item';}
        return $classes;
    }
    add_filter('nav_menu_css_class','techdencias_menu_classes',1,3);


?>