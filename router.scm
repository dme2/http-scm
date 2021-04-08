(module router (route build-table) 
(import scheme (chicken base))
(import (chicken io))
(import (chicken string))
(import (chicken format))
(import (chicken foreign))
(import (chicken file))
(import list-utils)
(require-extension bind)
;;(use srfi-4)
(require-extension srfi-13) ;; string-join
(require-extension srfi-69) ;; hash tables

;;(bind* "#include \"getfiles.h\"")

(define filepath (->string "/home/dave/projects/stevie-scm/tests/www/"))

;;(define get-files
;;  (foreign-lambda*
;;   c-string ((c-string fp))
;;   "char* result = getDirList(fp);
;;    C_return(result);"
;;   ))

;; read from a folder - our routable files
(define (read-files fp) (let ((files (->string (directory fp))))
    (string-split files "\n")
    ))
;; our empty router set
(define route-table (make-hash-table))

(define (is-dotfile str)
  (substring=? str "." 0 0 1))

;; (define (null-list? l)
;;  ())
		

(define (iter-over ht li)
  (if (not(length=0? li))
	  (begin
		(if (is-dotfile (car li))
			(iter-over ht (cdr li))
			(hash-table-set! ht (car li) 1))
		(iter-over ht (cdr li)))))

(define (build-table ht path)
  (iter-over ht (directory path))
  	ht)

;; (build-table route-table filepath)

(define _200_ "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 155\r\nConnection: keep-alive\r\n\r\n")
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

;; todo: get the end of the path i.e. the actual file
(define (parse-req-path str)
  (car (cdr (string-split str))))

(define (process-req s ht)
  ;;get the path and check that it's valid
  (let* ((path (parse-req-path (->string s)))
         (f_route (if (= 1 (string-length path))
                    "index.html"
                    (car(string-split path "/")))))
    (if (hash-table-exists? ht f_route)
		(conc _200_ (string-join (read-lines(open-input-file (conc filepath f_route)))))
        (conc _404_ not-found))))

;; let header = if verify-req...
(define (route req)
  (if (not(verify-req req))
	  (let ((header _405_)
		(content not-allowed))
		conc header content)
	  (let ((ht (build-table route-table filepath) ))
	  	(process-req req ht))))
)
