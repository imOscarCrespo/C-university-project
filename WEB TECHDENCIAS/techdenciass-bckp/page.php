<!-- Templete for displaying pages -->

<?php get_header();?>

    <div class = "page_container row">
        <div class = "page_col col-md-12">

            <?php while (have_posts() ) : the_post(); ?> 
                <article <?php post_class();?>>
                    <div class = "entry_header_wrapper">

                        <!-- <?php the_title('<h1 class = "entry-title">','</h1>');?> -->
                        <h1 class = "entry_title"><?php the_title('','');?> </h1>

                    </div>

                    <div class = "entry_content">
                        <?php the_content();?>
                    </div>

                </article>

            <?php endwhile; ?>

            
            
            <!-- Comented -->
            <!-- <?php while ( have_posts() ) : the_post();

				get_template_part( 'template-parts/page/content', 'page' );

				// If comments are open or we have at least one comment, load up the comment template.
				if ( comments_open() || get_comments_number() ) :
					comments_template();
				endif;

			endwhile; // End of the loop.
			?>  -->
            <!-- End Comented -->

        </div>
    </div>

<?php get_footer();?>