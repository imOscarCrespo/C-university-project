<!DOCTYPE html>
<html <?php language_attributes(); ?>

  <!INFORMATION OF THE FILE>

  <head>
  	<title>Techdencias | El laboratorio de ideas e innovación de Pasiona Cousulting</title>
    <!-- Required meta tags always come first -->
    <meta charset="utf-8">
    <!-- <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"> -->
    <meta http-equiv="x-ua-compatible" content="ie=edge">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.4/css/bootstrap.min.css" crossorigin="anonymous">

    <!-- Google Fonts -->
    <link href="https://fonts.googleapis.com/css?family=Roboto:400,500,700" rel="stylesheet">

    <!-- Font Awesome CDN -->
    <script src="https://use.fontawesome.com/025d1f53df.js"></script>

    <!-- Main CSS -->
    <link rel="stylesheet" href="<?php bloginfo('stylesheet_url'); ?>" type="text/css">
    <?php wp_head(); ?>
  </head>

  <body>

    <header class="header">
      <div class="container_header container">
        <div class="logo_wrapper">
          <div class="logo">
            <img src="<?php bloginfo('template_url'); ?>/img/favicon_techdencias.png">
          </div>
        </div>

        <?php
            wp_nav_menu( array (
                'theme_localitation' => 'top',
                'container' => 'nav',
                'container_class' => 'menu_container',
                'menu_class'=>'menu_list_ul',
            ) );

        ?>


        <!-- <nav class="menu_container">
          <ul class ="menu_list_ul list-inline">
            <li class = "list-inline-item" ><a href="">INICIO</a></li>
            <li  class = "list-inline-item" ><a href="">QUE ES TECHDENCIAS</a></li>

            <li  class = "list-inline-item" >
              <div class="flexbox-container">
                  <a href="">4SESSIONS</a>
                  <i class='icon-arrow'>
                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="120.6 59.5 612 359.1">
                      <path fill="#fff" d="M715.7,163.2c-21.1,22.2-248,237.4-248,237.4c-11.6,11.6-26.3,18-41.2,18s-30.6-6.3-41.2-18
                                          c0,0-225.9-215.2-248-237.4c-21.1-22.2-23.2-61.2,0-85.5c23.2-23.2,54.8-25.3,83.3,0l205.8,198.5l206-198.4
                                          c28.5-25.3,60.1-23.2,83.3,0C738.8,102.1,737.8,141.1,715.7,163.2z"/>
                    </svg>
                  </i>
              </div>
                <ul class="submenu">
                  <li class="subOption"><a href="">2017</a></li>
                  <li class="subOption"><a href="">2016</a></li>
                  <li class="subOption"><a href="">2015</a></li>
                </ul>
            </li>

            <li  class = "list-inline-item" ><a href="">BLOG</a></li>

            <li  class = "list-inline-item" ><a href="">EVENTOS</a></li>
          </ul>
          <div class="hamburger"><span></span></div>
          <div class="dimmer"></div>
        </nav> -->


      </div>

    </header>

    <!Main part>
    <div id="main">
      <div class="main_container container">