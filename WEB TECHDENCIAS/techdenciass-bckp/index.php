<?php get_header();?>

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
                          <p class="h4">Sessión del 25 de Febrero</p>
                          <p>Consulta la información sobre esta sessioón informativa</p>
                          <a href="#" class="btn btn-secondary">Entrar!</a>
                        </div>
                      </div>
                  </div>
          </div>
        <!Carousel End>

        <!Blocs Start>
          <div class="blocs_container row">
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
      
        <!Tweets Area Start>
          <div class = "tweetArea_container row">
            <div class = "tweetArea row">
                <!-- <a class="twitter-grid" href="https://twitter.com/TwitterDev/timelines/539487832448843776?ref_src=twsrc%5Etfw">National Park Tweets</a>  -->
                
              <!-- <div class = "tweetArea_title_wrapper">
                <h3>Last Tweets</h3>
              </div> -->

                  <link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">

                            <div class="panel panel-danger">
                              <div class="panel-heading">
                                 <h3 class="panel-title"><i class="fa fa-twitter-square" aria-hidden="true"></i>
                                    Techdencias Live
                                 </h3>
                                 
                              </div>
                              <div class="panel-body">
                                 <a class="twitter-timeline" data-width="100%" href="https://twitter.com/techdencias">Tweets by @Techdencias</a>
                                 <!-- <a class="twitter-timeline" href="https://twitter.com/Techdencias?ref_src=twsrc%5Etfw">Tweets by Techdencias</a> -->
                                 <div class= "tweets_col col-lg-4">
                                  </div>
                    
                                  <div class= "tweets_col col-lg-4">             
                                  </div>
                    
                                  <div class= "tweets_col col-lg-4">                
                                  </div> 
                              </div>
                            </div>
            </div>

          </div>
        <!Tweets Area End>

        <!Bottom Info Start>
          <div class="info_container row">
            <div class="info row">

              <div class = "patrocinadores_container col-lg-5">
                <div>
                  <h4><strong>Patrocinadores</strong></h4>
                </div>

                <div class="patro_col_container">
                  <div class = "patro_col">
                    <div>
                        <a href ="https://www.mobileworldcentre.com"><img src="<?php bloginfo('template_url'); ?>/img/logo-MWC_solo.jpg" ></a>
                    </div>

                    <div>
                        <a href ="http://pasiona.com"><img src="<?php bloginfo('template_url'); ?>/img/logopasiona_transparent.png"></a>
                    </div>
                  </div>

                  <div class = "patro_col">
                      <div>
                          <a href ="http://mobileworldcapital.com/es/"><img src="<?php bloginfo('template_url'); ?>/img/Logo_CAPITAL.jpg"></a>
                      </div>
                      <a href ="http://www.movistar.es"><img src="<?php bloginfo('template_url'); ?>/img/Logo_movistar.png"></a>
                      <div>
                      </div>                     
                  </div>
                </div>
              </div>

              <div class = "colaboradores_container col-lg-5">
                  <div>
                    <h4><strong>Colaboradores</strong></h4>
                  </div>
  
                  <div class="colabo_col_container">
                    <div class = "colabo_col">
                      <div>
                          <a href ="http://ajuntament.barcelona.cat/es/"><img src="<?php bloginfo('template_url'); ?>/img/ajuntament_bcn1.png"></a>
                      </div>
  
                      <div>
                          <a href ="https://obrasociallacaixa.org/es/"><img src="<?php bloginfo('template_url'); ?>/img/ObraSocial2.jpg"></a>
                      </div>
                    </div>
  
                    <div class = "colabo_col">
                        <div>
                          <a href = "https://www.microsoft.com/" ><img src="<?php bloginfo('template_url'); ?>/img/microsoft1.png"></a>
                        </div>
                          <a href = "http://www.zyncsocial.com"><img src="<?php bloginfo('template_url'); ?>/img/ZyncSocial_logo.png"></a>
                        <div>
                        </div>                     
                    </div>
                  </div>
              </div>

              <div class="SN_container col-lg-2">
                <div>
                      <h4><strong>Redes</strong></h4>
                </div>
                <div class="SN_col_container">

                    <div class="SN_col">
                        <div>
                          <!-- <i class="fa fa-facebook-f"></i> -->
                          <i class="fa fa-facebook fa-4x"></i>
                        </div>
                        <div>
                          <i class="fa fa-twitter fa-4x"></i>
                        </div>
                      </div>

                      <div class="SN_col">
                          <div>
                            <i class="fa fa-youtube fa-4x"></i>
                          </div>
                            <i class="fa fa-github fa-4x"></i>
                          <div>
                          </div>
                      </div>
                </div>
              </div>

            </div> 
          </div>
        <!Bottom Info End>

<?php get_footer();?>