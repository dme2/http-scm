(import socket)
(import (chicken format))
(import (chicken string))
(import (chicken io))
(require-extension srfi-13)

(define _200_ "HTTP/1.1 200 OK\r\n")
(define _404_ "HTTP/1.1 404 Not Found\r\n\notfound\n")
(define _405_ "HTTP/1.1 405 Method Not Allowed \r\n\r\not allowed\n")
(define port 8000)

;;needs to send a file (using connected-socket(file-descriptor)) instead of just plain text - although that works for now.

;; GET -PATH -VERSION
;;return "route".html
(define (process-get s)
  (printf "processing\n")
  ;;get the path and check that it's valid
  (let* ((path (parse-req-path s))
         (route (if (= 1 (string-length path))
                    "index"
                    (car(string-split path "/"))))
	 (file (conc route ".html"))
	 ;(ctype ())
	 ;(clen  ())
	 )
    (string-append (string-join (read-lines(open-input-file file)))_200_)))

(define (parse-req-path s)
  (car (cdr (string-split s))))

(define (check_req s)
  (cond
   ((substring=? s "GET" 0 0 3) (process-get s))
    (else _404_)))

;(define (set-header)
  ;())

(let ((sock (socket af/inet sock/stream))
      (backlog 1))
  (socket-bind sock (inet-address "127.0.0.1" port))
  (socket-listen sock backlog)
  ;;connected-socket is our socket fd
  (let* ((connected-socket (socket-accept sock))
         (message-len 1024)
         ;;receive
         (received-data (socket-receive connected-socket
                                        message-len)))
    ;;respond
    ;;should do a filewrite here
    (printf "recvd:  ~A~%" received-data)
    (let* ((content (check_req received-data))
           (header (set-resp-header))
           (resp (conc header content)))
      (printf resp)
      ;(file-write connected-socket resp))
      (socket-send connected-socket resp))

    (socket-close connected-socket)
    (socket-close sock)))
