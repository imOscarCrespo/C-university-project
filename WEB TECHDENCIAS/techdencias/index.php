<!DOCTYPE html>
<html <?php language_attributes(); ?>

  <!INFORMATION OF THE FILE>
  <head>
  	<title>Techdencias | El laboratorio de ideas e innovación de Pasiona Cousulting</title>
    <!-- Required meta tags always come first -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.4/css/bootstrap.min.css" crossorigin="anonymous">

    <!-- Google Fonts -->
    <link href="https://fonts.googleapis.com/css?family=Roboto:400,500,700" rel="stylesheet">

    <!-- Font Awesome CDN -->
    <!-- <script src="https://use.fontawesome.com/025d1f53df.js"></script> -->

    <!-- Main CSS -->
    <link rel="stylesheet" href="<?php bloginfo('stylesheet_url'); ?>" type="text/css">

    <?php wp_head(); ?>
  </head>


  <body>
    
    <header>
      <div class="container">
        <div class="row">
        	
        <! Container del logo>
	        <div class="col-md-3">
	        	<img src="<?php bloginfo('template_url'); ?>/img/favicon_techdencias.png" alt="techdencias_logo">
          </div>
          
        <!Container del menu de la barra principal>
          <div class="menu-bar col-md-9">
            <ul>
              <li><a href="#">Inicio</a></li>
              <li><a href="#">Que es Techdencias</a></li>
              <li><a href="#">4Sessions <span class=" fa fa-angle-down"></span></a>
                <ul>
                  <li><a href="#">2016</a></li>
                  <li><a href="#">2017</a></li> 
                </ul>
              </li>
              <li><a href="#">Blog</a></li>
              <li><a href="#">Eventos</a></li>  
            </ul>
      		</div>
       	</div>
      </div>


    </header>

   
    
    <!Main part>
    <div id="main">
      <div class="container">

        <!Carousel Start>
        <div id="slider-home" class="carousel slide" data-ride="carousel">
                <ol class="carousel-indicators">
                  <li data-target="#slider-home" data-slide-to="0" class="active"></li>
                  <li data-target="#slider-home" data-slide-to="1"></li>
                  <li data-target="#slider-home" data-slide-to="2"></li>
                </ol>

                <div class="carousel-inner" role="listbox">


                    <div class="carousel-item active">
                      <img src="<?php bloginfo('template_url'); ?>/img/4session_25_febrero.jpeg" alt="First slide">
                    </div>

                    <div class="carousel-item">
                      <img src="<?php bloginfo('template_url'); ?>/img/4session_25_febrero.jpeg" alt="First slide">
                    </div>

                    <div class="carousel-item">
                      <img src="<?php bloginfo('template_url'); ?>/img/4session_25_febrero.jpeg" alt="First slide">
                      
                      <div class="carousel-caption">
                        <h2>4Sessions</h2>
                        <img src="img/2x1.png">
                        <p class="h4">Sessión del 25 de Febrero</p>
                        <p>Consulta la información sobre esta sessioón informativa</p>
                        <a href="#" class="btn btn-secondary">Entrar!</a>
                      </div>
                    </div>
                </div>
        </div>
        <!Carousel End>



        <!Blocs Start>
          <div class="big_blocs row">
            <div class="blocs row">
          
              <div class="col-lg-3">
                <h3><strong>Title1</strong></h3>

                <div class="container_image">
                  <img src="<?php bloginfo('template_url'); ?>/img/symbol_image.png" alt="blocs_im1" class = "img-fluid">

                  <div class="opacity_element">
                    <div class ="opac_text">
                      <p>What's about 1</p> 
                    </div>
                  </div>
                </div>
              </div>


              <div class="col-lg-3">
                <h3><strong>Title2</strong></h3>

                <div class="container_image">
                  <img src="<?php bloginfo('template_url'); ?>/img/symbol_image.png" alt="blocs_im1" class = "img-fluid">

                  <div class="opacity_element">
                    <div class ="opac_text">
                      <p>What's about 2</p>  
                    </div>
                  </div>
                </div>
              </div>


              <div class="col-lg-3">
                <h3><strong>Title3</strong></h3>

                <div class="container_image">
                  <img src="<?php bloginfo('template_url'); ?>/img/symbol_image.png" alt="blocs_im1" class = "img-fluid">

                  <div class="opacity_element">
                    <div class ="opac_text">
                      <p>What's about 3</p>  
                    </div>
                  </div>
                </div>
              </div>

              <div class="col-lg-3">
                <h3><strong>Title4</strong></h3>

                <div class="container_image">
                  <img src="<?php bloginfo('template_url'); ?>/img/symbol_image.png" alt="blocs_im1" class = "img-fluid">

                  <div class="opacity_element">
                    <div class ="opac_text">
                      <p>What's about 4</p>  
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>

        <!Blocs End>

        <!Bottom Info Start>
          <div class="Info_Bottom">

            <div class="row">

              <div clase = "col-md-6">
                <h4><strong>Colaboradores</strong></h4>
                <ul class = "list_colaboradores">
                  <li>
                    <a href = "#"> Pasiona </a>
                  </li>
                  <li>
                    <a href = "#"> Mobile World Centre </a>
                  </li>
                  <li>
                    <a href = "#"> Mobile World Capital Barcelona </a>
                  </li>
                  <li>
                    <a href = "#"> Movistar </a>
                  </li>
                </ul>
              </div>

              <div clase = "col-md-6">
                <h4><strong>Social Network</strong></h4>
                <ul class = "list_colaboradores">
                  <li>
                    <a href = "#"> Facebook </a>
                  </li>
                  <li>
                    <a href = "#"> Twitter </a>
                  </li>
                  <li>
                    <a href = "#"> YouTube </a>
                  </li>
                  <li>
                    <a href = "#"> GitHub </a>
                  </li>
                </ul>
              </div>

            </div>
          </div>
        <!Bottom Info End>

      </div>
    </div>



    <footer>


      <?php wp_footer(); ?>
    </footer>




    <!-- Optional JavaScript -->

   


    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js" crossorigin="anonymous"></script>


    <script src = "<?php bloginfo('template_url'); ?>/js/general.js" type = "text/javascript"></script>

  </body>
</html>