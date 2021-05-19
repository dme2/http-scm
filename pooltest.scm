(import simple-loops)
(import (chicken memory))
(import (chicken format))
(import (chicken foreign))
(import (chicken file posix))
(import (chicken string))
(import (chicken io))
(import (chicken file))
(import (chicken process))
(import bind)
(require-extension srfi-13)

;;;;;;;  foreign functions for the threadpool ;;;;;;;
(foreign-declare "#include \"tj.h\"")

(define (test-func)
  printf "hello!\n")

(set! threadcount 2)

(define init-thread-pool
  (foreign-lambda*
    (c-pointer (struct "pool"))
	((int threadcount))
	"pool* p = initPool(threadcount); C_return(p);"))

(define build-job-node
  (foreign-lambda*
    (c-pointer (struct "job_node"))
    	((c-pointer  func)
	    (c-pointer  args))
	"job_node* job = buildJobNode((void*)func, args); C_return(job);"))

(define build-job-node-np
  (foreign-lambda*
    (c-pointer (struct "job_node"))
    	(((function void ()) func))
	"job_node* job = buildJobNode((void*)func, NULL); C_return(job);"))

(define enqueue-job
  (foreign-lambda*
    int
    (((c-pointer (struct "job_queue")) q)
     ((c-pointer (struct "job_node")) jn ))
    "int err = enqueueJob(q,jn); C_return(err);"))

(define get-queue
  (foreign-lambda*
    (c-pointer (struct "job_queue"))
    (((c-pointer (struct "pool")) p))
	"C_return(p->queue);"))

(define drain-pool
  (foreign-lambda*
    void
    (((c-pointer (struct "pool")) p))
	"drainPool(p);"))

(define pool-wait
  (foreign-lambda*
    void
    (((c-pointer (struct "pool")) p))
	"poolWait(p);"))

(define (test-pool)
  (let*
    ((p (init-thread-pool threadcount))
     (test-func-ptr (object->pointer test-func)))
    (printf "pool started\n")
     p))

(set! pool
  (test-pool))

(define (test-queue p)
    (let*
	    ((loopvar 0))
	 (do-while (< loopvar 1)
		(printf "loop\n")
        (set! loopvar (+ loopvar 1))
        (let*
          ((test-func-ptr (object->pointer test-func))
            (job (build-job-node-np test-func)))
		  (printf "queuing job\n")
          (enqueue-job (get-queue p) job)))))

(test-queue pool)
;pool-wait pool
drain-pool pool
