(import socket)
(import (chicken format))
(import (chicken string))

(define _200_ "HTTP/1.0 200 OK\r\n")
(define _404_ "HTTP/1.0 404 Not Found\r\n\notfound\n")
(define _405_ "HTTP/1.0 405 Method Not Allowed \r\n\r\not allowed\n")
(define port 2020)

|# todo: define a function that determines if the path is valid
         if the path exists, write the file into the buffer
         if it doesn't, return a 404  
         
         write a more robust request parser
         add processes

#|

;; GET -PATH -VERSION
|#
(define (process-get s)
  ;;get the path and check that it's valid
  ())
#|

(define (check_req s)
  (cond
   ((substring=? s "GET" 0 0 3)
    process-get s)
    (else _404_)))

(let ((sock (socket af/inet sock/stream))
      (backlog 1))
  (socket-bind sock (inet-address "127.0.0.1" port))
  (socket-listen sock backlog)
  ;;connected-socket is or socket fd
  (let* ((connected-socket (socket-accept sock))
         (message-len 1024)
         ;;receive
         (received-data (socket-receive connected-socket
                                        message-len)))
    ;;respond
    (let* ((resp (check_req received-data)))
      (socket-send connected-socket resp))
    (socket-close connected-socket)
    (socket-close sock)))
