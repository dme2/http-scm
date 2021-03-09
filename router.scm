(import (chicken string))
(import (chicken foreign))
(require-extension bind)
;;(use srfi-4)
(require-extension srfi-13) ;; string-join
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

(define _200_ "HTTP/1.1 200 OK\r\n")
(define _404_ "HTTP/1.1 404 Not Found\r\n\n")
(define _405_ "HTTP/1.1 405 Method Not Allowed \r\n\r\n")
(define content-type "Content-Type: text/html\r\n")
(define content-length "Content-Length: % \r\n\r\n ")
(define not-allowed "Not allowed")
(define not-found "File Not Found!")

;; only GET's
(define (verify-req req)
  (if (substring=? req "GET" 0 0 3)
	  #t
	  #f))

(define (parse-req-path s)
  (car (cdr (string-split s))))

(define (process-req s ht)
  ;;get the path and check that it's valid
  (let* ((path (parse-req-path s))
         (route (if (= 1 (string-length path))
                    "index.html"
                    (car(string-split path "/")))))
    (if (hash-table-exists? ht route)
		(conc (_200_) (string-join (read-lines(open-input-file route))))
        (conc _404_ not-found))))

;; let header = if verify-req...
(define (route r-table req)
  (if (not(verify-req req))
	  (let ((header (_405_))
			(content not-allowed))
		conc header content)
	  (process-req r-table req)))
