(assert (ite (<= (- (+ 0 (* 1 a)) (* 1 b)) 0) (= out (+ (+ 0 (* 1 b)) (* 1 k2))) (ite (> (- (+ 0 (* 1 a)) (* 1 b)) 0) (= out (+ (+ 0 (* 1 a)) (* 1 k1))) (= 1 1))))