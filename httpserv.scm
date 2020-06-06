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
(define (process-get s)
  (printf "processing\n")
  ;;get the path and check that it's valid
  (let* ((path (parse-req-path s))
         (route (if (= 1 (string-length path))
                    "index.html"
                    (car(string-split path "/")))))
    (if (file-exists? route) (string-join (read-lines(open-input-file route)))
        (conc _404_ not-found))))

(define (parse-req-path s)
  (car (cdr (string-split s))))

(define (check_req s)
  (cond
   ((substring=? s "GET" 0 0 3) (process-get s))
    (else conc _405_ not-allowed)))

(define (serve)
   (let ((sock (socket af/inet sock/stream))
         (backlog 1))
     (socket-bind sock (inet-address "127.0.0.1" port))
     (socket-listen sock backlog)
     ;;connected-socket is our socket fd
     ;;put this named let in a do-while loop and fork the process
     (let* ((connected-socket (socket-accept sock))
            (message-len 1024)
            ;;receive
            (received-data (socket-receive connected-socket
                                        message-len)))
       ;;respond
       ;;should do a filewrite here
       (printf "recvd:  ~A~%" received-data)
       (let* ((content (check_req received-data))
              (header (if (substring=? content "404" 9 0 3) ""
                          (get-header (strlen content))))
              (resp (conc header content)))
              ;(printf content)
         (file-write (socket-fileno connected-socket) content))
       (socket-close connected-socket)
       (socket-close sock))))
;start server
(serve)
