;; the renderer is a function which takes html-xprs and converts it to an html document 
;; 	(render (html-xprs . html-xprs)) 
;; so for example
;; we have a string that defines our web page as so:
;; 	(define s "<h1> hello <\h1> <p> this is a web page <\p>) 
;; then we can pass it to our renderer
;; 	(render s "hello.html") 
;; 

(require-extension srfi-13)
(import (chicken string))
(import (chicken io))
(import (chicken file))

(define (parse (html-strings))
  ())

;;write to html file
(define (print-html html-str file-str)
  ())

;; the renderer takes a list of "html expressiosn and creates an html file" 
;; do we need a macro?
;(define-er-macro (render filename (html-xprs))
;  %
;  `(,%let* ((,%html-str (,%parse ,html-xprs)))
;          (,%print-html ,%html-str ,filename)))

(define (render filename (html-xprs))
  (let* ((html-str (parse (html-xprs))))
    (print-html html-str filename)))
