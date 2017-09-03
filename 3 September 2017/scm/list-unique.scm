(define (list-include? lst x)
  (and (not (null? lst))
       (or (eq? (car lst) x)
           (list-include? (cdr lst) x))))

(define (list-slice lst start end)
  (map (lambda (i) (list-ref lst i)) (iota (- end start) start)))

(define (list-unique lst)
  (map (lambda (x-lookup-pair) (car x-lookup-pair))
     (filter (lambda (x-lookup-pair)
               (not (list-include? (cadr x-lookup-pair) (car x-lookup-pair))))
             (map (lambda (last-index)
                    (list (list-ref lst last-index)
                    (list-slice lst 0 last-index)))
                  (iota (length lst))))))

(define values `("roflcopter" 2 2 "heli" "copter" "copter"))
(list-unique values)
