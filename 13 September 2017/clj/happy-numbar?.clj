(defn number-digits [x]
  (let [str-digits (str (if (< x 0) (- x) x))]
       (map #(Integer. %) (clojure.string/split str-digits #""))))

(defn happy-numbar?
  ([x] (happy-numbar? x #{}))
  ([x visited]
      (or (= x 1)
          (and (not (contains? visited x))
               (let [squared-digits (map #(* % %) (number-digits x))]
                    (let [next-x (apply + squared-digits)]
                         (happy-numbar? next-x (conj visited x))))))))

(let [candidates (range 1001)]
     (filter happy-numbar? candidates))
