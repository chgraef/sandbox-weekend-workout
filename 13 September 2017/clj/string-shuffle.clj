(defn string-shuffle [s]
  (clojure.string/join "" (shuffle (clojure.string/split s #""))))
