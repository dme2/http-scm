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

;;;;;; main server functions

(define (init-connection addr port)
  (let ((sock (socket af/inet sock/stream)))
	(socket-bind sock (inet-address addr port))
	(socket-listen sock 1)
	sock))

(define (poll-recv csock)
  (let* ((received-data (socket-receive csock 32768)))
        (printf "recvd:  ~a~%" received-data)
	(if (> (string-length received-data) 0)
		(poll-reply csock received-data)
		(socket-close csock))))

;;send header and reply
(define (poll-reply csock data)
  (let* ((reply (route data)))
     	(printf "reply:  ~a~%" reply)
	(file-write (socket-fileno csock) reply))
  (socket-close csock))

(define (poll-socket sock)
  (if (eq? (socket-receive-ready? sock) #t)
	   ;; receive the info
	  (let* ((c-sock (accept-connection sock)))
  		(poll-recv c-sock)
		(let ((pid (process-fork)))
		  (printf "\nFORKED\n")
		  (printf "pid: ~a~%" pid)
		  (if (> pid 0)
			  ;(process-signal pid 9))))))
			  (exit 0))))))

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
;(http-serve "127.0.0.1" 8080)
