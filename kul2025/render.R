rmarkdown::render('slides.Rmd', output_file="slides_handout.html", output_format="rmarkdown::html_document")

rmarkdown::run('slides.Rmd')

backgroundProcess <- callr::r_bg(function(){
rmarkdown::run('slides.Rmd', render_args=list(output_format="rmarkdown::html_document"), shiny_args = list(port=8069))
})
pagedown::chrome_print("http://localhost:8069/slides.Rmd", wait = 15, verbose = 2)
