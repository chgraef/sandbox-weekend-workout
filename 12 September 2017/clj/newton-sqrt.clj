(defn abs [x]
  (if (< x 0) (- x)
      x))

(defn good-enough? [x g]
  (let [eps 0.001]
       (< (abs (- (* g g)
                  x))
          eps)))

(defn improve-guess [x g]
  (/ (+ g (double (/ x g))) 2.0))

(defn my-sqrt
  ([x]    (my-sqrt x 1))
  ([x, g] (if (good-enough? x g) g
              (my-sqrt x (improve-guess x g)))))

(let [x 2]
     (let [root (my-sqrt x)]
          (println root)
          root))
