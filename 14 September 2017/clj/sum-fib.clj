(defn sum-even-fib
  ([lim] (sum-even-fib lim 1 2 0))
  ([lim x y sum]
        (if (>= x lim) sum
            (let [new-sum (if (even? x)
                              (+ sum x)
                              sum)
                  z (+ x y)] (sum-even-fib lim y z new-sum)))))

(let [x 4000000]
     (sum-even-fib x))
