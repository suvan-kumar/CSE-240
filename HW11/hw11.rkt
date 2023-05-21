; Leave the test outputs in. 

; Q1 (5 points)
; Enter your code here
(- 8 (- (* 3 5) 2))                                                                       ; 1.1
(+ (* (/ 8 4) (* 3 2)) (+ 8 (* 2 3)))                                                     ; 1.2
(+ 4 (* 8 (- (+ 4 4) (* 3 (* 3 2)))))                                                     ; 1.3
(* (* 2 (- 10 9)) (+ 2 (/ (+ (- 3 2)(* 3 9)) (+ 1 3))))                                    ; 1.4
(+ (+ (* (- (/ (+ 1 (* 6 2) 5 8)  2) 8) 2) 6) (- (/ (+ (* 4 7) (* 2 4)) 4) (* 2 5)))      ; 1.5

; Q2 Multiply (5 points)
(define Multiply
  (lambda (x y)                     ; input parameters
    (* x y)                         ; multiplying x & y
  )
)

(Multiply 5 2)

; Q3 Exponent (5 points)
(define Exponent 
  (lambda (x y)
    (if (= y 0)                                           ; base case
        1                                                 ; return 1 if base case is met
        (Multiply x (Exponent x (- y 1)))                 ; recursive call for x * x^(y-1)
    )
  )
)
    
  
(Exponent 4 3)

; Q4 (5 points)
(define PerfectDivision
  (lambda (x y)
    (if (= 0 (remainder x y))                             ; check if remainder is produced                      
        (/ x y)                                           ; divide if there is no remainder
        (display "This has a remainder\n")                ; else display "this has a remainder"
    )
  )
)

(PerfectDivision 4 5)
(PerfectDivision 8 4)

; Q5 (5 points)
(define AddExponents
  (lambda (a b c d)
    (+ (Exponent a b) (Exponent c d))                     ; add together the two results of exponent function producing a^b + c^d
  )
)

(AddExponents 2 3 4 2)

; Q6 (5 points)
(define (MultiplyLet x y)
  (let (
        (first x)                                         ; first = x
        (second y)                                        ; second = y
       )
    (Multiply first second)                               ; first * second
  )
)  
(MultiplyLet 6 9)

; Q7 (5 points)
(define (Letexpression)
  (let
      (
       (three 3)                                         ; int three = 3
        (two 2)                                          ; int two = 2
        (five 5)                                         ; int five = 5
        (eight 8)                                        ; int eight = 8
      )
    (- eight (- (* three five) two))                     ; replicating 1.1 using the local vars
  )
)
(Letexpression)

; Q8 (5 points)
(define accumulator	; recursive
  (lambda (x y total count) 
    (if (> y count)                                      ; check if y > count
        (accumulator x y (+ total x) (+ count 1))        ; if true, recursive call to add x to total again and increment count
        (* 1 total)                                      ; else, return total
    )
  )
)

(accumulator 3 4 0 0)
