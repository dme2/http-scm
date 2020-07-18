;; todo
;; needs to read the request and determine the correct response
;; bad request gets 405, if the file does not exist, 404, etc...

;; essentially we need a set of strings, if the given string is in the set, then return the route, otherwise, 404

(import (chicken string))
(require-extension srfi-13)
(require-extension srfi-113) ;; for sets
(require-extension srfi-128) ;; comparitors for the set

;; comparitor
(make-comparitor string? string=? string<? string-hash)

;; our empty router set
(define route-set (set string? ))

;; build and return a router (a function that looks up routes using a set) 
;; e.g. usage (let* ((router (build-router set routes))))
;; then we query the router given valid html strings
(define (build-router router-set (valid-routes))
  ())
