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
     (let* ((content (check_req received-data))
            (header (if (substring=? content "404" 9 0 3) ""
                        (get-header (strlen content))))
            (resp (conc header content)))
              ;(printf content)
       (file-write (socket-fileno c-sock) resp))
       ;(socket-close connected-socket)
     (socket-close sock)))
