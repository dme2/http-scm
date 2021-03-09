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
(define port 8000)
(define content-type "Content-Type: text/html\r\n")
(define content-length "Content-Length: % \r\n\r\n ")
(define not-allowed "Not allowed")
(define not-found "File Not Found!")

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

(define (serve addr port)
  (let ((sock (socket af/inet sock/stream))
        (backlog 1)
	(loopvar 1))
    (socket-bind sock (inet-address addr port))
    (socket-listen sock backlog) ;;do we need backlog?
    ;;connected-socket is our socket fd
    ;;put this named let in a do-while loop and fork the process
    (do-while (= loopvar 1)
     (let* ((connected-socket (socket-accept sock))
            (message-len 1024))
            ;;receive
       (if (= (socket-fileno connected-socket) -1)
           (printf "continuing\n")
           ;(set! received-data (socket-receive connected-socket
           ;       message-len)))
           (cond ((= (process-fork) 0)             
                  (set! c-sock connected-socket)
                  (set! loopvar 0)
                  (set! msg-len message-len)) 
               (else socket-close connected-socket)))))
     
     (set! received-data (socket-receive c-sock
            msg-len))
     (printf "recvd:  ~a~%" received-data)
     (let* ((content (check-req received-data))
            (header (if (substring=? content "404" 9 0 3) ""
                        (get-header (strlen content))))
            (resp (conc header content)))
              ;(printf content)
       (file-write (socket-fileno c-sock) resp))
       ;(socket-close connected-socket)
     (socket-close sock)))


(define (serve)
   (let ((sock (socket af/inet sock/stream))
         (backlog 1)
	 (loopvar 1))
     (socket-bind sock (inet-address "127.0.0.1" port))
     (socket-listen sock backlog)
     ;;connected-socket is our socket fd
     ;;put this named let in a do-while loop and fork the process
     (do-while (= loopvar 1)
     (let* ((connected-socket (socket-accept sock))
            (message-len 1024))
            ;;receive
       (if (= (socket-fileno connected-socket) -1)
           (printf "continuing\n")
           ;(set! received-data (socket-receive connected-socket
           ;       message-len)))
           (cond ((= (process-fork) 0)             
                  (set! c-sock connected-socket)
                  (set! loopvar 0)
                  (set! msg-len message-len)) 
               (else socket-close connected-socket)))))
     
     (set! received-data (socket-receive c-sock
            msg-len))
     (printf "recvd:  ~a~%" received-data)
     (let* ((content (check-req received-data))
            (header (if (substring=? content "404" 9 0 3)
                        (get-header (strlen content))))
            (resp (conc header content)))
              ;(printf content)
       (file-write (socket-fileno c-sock) resp))
       ;(socket-close connected-socket)
     (socket-close sock)))

;start server
(serve)
