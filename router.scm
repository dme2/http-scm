;; needs to read the request and determine the correct response
;; bad request gets 405, if the file does not exist, 404, etc...

;; if the given string is in the set, then return the route, otherwise, 404

(import (chicken string))
(import (chicken foreign))
(require-extension bind)
;;(use srfi-4)
(require-extension srfi-13)
(require-extension srfi-69) ;; hash tables

(foreign-declare "#include \"getfiles.h\"")

(define filepath (->string "/home/dave/projects/stevie-scm"))

(define get-files
  (foreign-lambda*
   c-string ((c-string fp))
   "char* result = getDirList(fp);
    C_return(result);"
   ))

;; read from a folder - our routable files
(define (read-files fp)
  (let ((files (->string (get-files fp))))
    (string-split files "\n")
    ))
;; our empty router set
(define route-table (make-hash-table))

(define (is-dotfile str)
  (substring=? str "." 0 0 1))

(define (iter-over ht li)
  (if (not(eq? '() li))
	  (begin
		(if (is-dotfile (car li))
			(iter-over ht (cdr li))
			(hash-table-set! ht (car li) 1))
		(iter-over ht (cdr li)))))

(define (build-table ht path)
  (iter-over ht (read-files path)))

(build-table route-table filepath)

;; gives us a (header content) tuple

(define verify-req (req)
  ())

(define (route r-table)
  ())
