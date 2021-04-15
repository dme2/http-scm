;; need to add parameters for (serve) i.e. (port, address)
;; need to make the routing more modular

(import socket)
(import simple-loops)
(import (chicken format))
(import (chicken foreign))
(import (chicken file posix))
(import (chicken string))
(import (chicken io))
(import (chicken file))
(import (chicken process))
(import bind)
(require-extension srfi-13)
(import router)

(bind "size_t strlen(const char *);")
(define _200_ "HTTP/1.1 200 OK\r\n")
(define _404_ "HTTP/1.1 404 Not Found\r\n\n")
(define _405_ "HTTP/1.1 405 Method Not Allowed \r\n\r\n")
(define port 8080)
(define content-type "Content-Type: text/html\r\n")
(define content-length "Content-Length: % \r\n\r\n ")
(define not-allowed "Not allowed")
(define not-found "File Not Found!")

;;(printf "%s" (route "index.html"))

(define (get-header len)
  (let* ((s-len (number->string len)))
    (conc _200_ content-type
         (string-translate*
          content-length `(("%" . ,s-len )) ))))

;; GET -PATH -VERSION
;;return "route".html
;;need to replace this with proper router
(define (process-req s)
  ;;get the path and check that it's valid
  (let* ((path (parse-req-path s))
         (route (if (= 1 (string-length path))
                    "index.html"
                    (car(string-split path "/")))))
    (if (file-exists? route) (string-join (read-lines(open-input-file route)))
        (conc _404_ not-found))))

(define (parse-req-path s)
  (car (cdr (string-split s))))

(define (check-req s)
  (cond
   ((substring=? s "GET" 0 0 3) (process-req s))
    (else conc _405_ not-allowed)))

(define (init-connection addr port)
  (let ((sock (socket af/inet sock/stream)))
	(socket-bind sock (inet-address addr port))
	(socket-listen sock 1)
	sock))

(define (poll-recv csock)
  (let* ((received-data (socket-receive csock 1024)))
	(poll-reply csock received-data)))

;;send header and reply
(define (poll-reply csock data)
  (let* ((reply (route data)))
	(file-write (socket-fileno csock) reply))
  (socket-close csock))
;;close connection after this?

(define (poll-socket sock)
  (if (eq? (socket-receive-ready? sock) #t)
	   ;; receive the info
	  (let* ((c-sock (accept-connection sock)))
		(poll-recv c-sock))))

(define (accept-connection sock)
  (let* ((connected-socket (socket-accept sock)))
	connected-socket))

(define (http-serve addr port)
  ;;init connection
   (let* ((sock (init-connection addr port))
		 (loopvar 1))
	 (do-while (= loopvar 1)
	   (poll-socket sock))
   (socket-close sock)))

;; for testing
(define (serve)
  ;;init connection
   (let ((sock (socket af/inet sock/stream))
         (backlog 1)
	 (loopvar 1))
     (socket-bind sock (inet-address "127.0.0.1" port))
     (socket-listen sock backlog)

     (let* ((connected-socket (socket-accept sock))
            (message-len 1024))
	    (set! c-sock connected-socket))
            ;;receive
     	;;(do-while (= loopvar 1)
	;;(print (socket-fileno connected-socket))
       	;;(if (> (socket-fileno connected-socket) -1)
           ;;(cond ((> (process-fork) 0)
                  ;;(set! c-sock connected-socket)
                  ;;(set! loopvar 0)
                  ;;(set! msg-len message-len))
               ;;(else socket-close connected-socket)))))
     (set! received-data (socket-receive c-sock 1024))
     (printf "recvd:  ~a~%" received-data)
     (let* ((resp (route received-data)))
  	(printf "~a~%\n" resp)
       	(file-write (socket-fileno c-sock) resp))
     (socket-close sock)))

;start server
(http-serve "0.0.0.0" 80)
