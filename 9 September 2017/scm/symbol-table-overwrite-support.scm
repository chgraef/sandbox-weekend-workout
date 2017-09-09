(define (make-st) `())

(define (make-pair key val) (cons key val))
(define (pair-key pair) (car pair))
(define (pair-val pair) (cdr pair))

(define (st-get st key)
  (if (null? st) `()
      (let ((kv-pair (car st)))
           (let ((cur-key (pair-key kv-pair))
                 (cur-val (pair-val kv-pair)))
              (if (eq? key cur-key) cur-val
                  (st-get (cdr st) key))))))

(define (st-add st key val)
  (let ((new-pair (make-pair key val)))
       (cond [(null? st) (list new-pair)]
             [(eq? (pair-key (car st)) key) (st-add (cdr st) key val)]
             [else (cons (car st) (st-add (cdr st) key val))])))

(let ((st (make-st)))
     (begin (set! st (st-add st "a" 65))  ; Symbol table is molecular/immutable, i.e.
            (set! st (st-add st "b" 66))  ; returns a new symbol table on each operation
            (set! st (st-add st "a" 67))) ; meant to change its state.
      (print (st-get st "a"))
      (print (st-get st "b"))
      (print (st-get st "c"))
      (print (st-get st "d"))
      st)
