;; the renderer is a macro based function render define
;; 	(render (html-xprs . html-xprs)) 
;; so for example
;; we have a string that defines our web page as so:
;; 	(define s "<h1> hello <\h1> <p> this is a web page <\p>) 
;; then we can pass it to our renderer
;; 	(render s) 
;; and it'll expand to a fully tagged html document
;; 
;; the main idea behind having the render function being a macro is that
;;	a. we can append multiple html strings into one html document
;;	b. we can evaluate functions inside of the html definitions
;; 		e.g
;;			(define html-xpr-list "<h1>" fetch_text "</h1>")
;;	will result in a string composed of whatever fetch_text returns inside of the h1 tags
;;

;; the macro will pass each html string to string-translate* where we can fill in 
;; our "unquotes"
;; for "unquoting" (not really unquoting technically) out of html strings
(define f-unquote '|')

