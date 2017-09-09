(define (make-st) `())

(define (st-get st key)
  (if (null? st) `()
      (let ((kv-pair (car st)))
           (let ((cur-key (car kv-pair))
                 (cur-val (cdr kv-pair)))
              (if (eq? key cur-key) cur-val
                  (st-get (cdr st) key))))))

(define (st-add st key val)
  (cons (cons key val) st)) ; Please note, no check for duplicate keys.

(let ((st (make-st)))
     (begin (set! st (st-add st "a" 65))  ; Symbol table is molecular/immutable, i.e.
            (set! st (st-add st "b" 66))  ; returns a new symbol table on each operation
            (set! st (st-add st "c" 67))) ; meant to change its state.
      (print (st-get st "a"))
      (print (st-get st "b"))
      (print (st-get st "c"))
      (print (st-get st "d"))
      st)
