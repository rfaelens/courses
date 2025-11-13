rmarkdown::render('slides.Rmd', output_file="slides_ioslides.html", output_format="rmarkdown::ioslides_presentation")
rmarkdown::render('slides.Rmd', output_file="slides_handout.html", output_format="rmarkdown::html_document")
pagedown::chrome_print("slides_ioslides.html", output="slides_ioslides.pdf")
