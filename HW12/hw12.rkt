;Your Name: Suvan Kumar
;Course: CSE 240
; Use the template for your programming assignment

;Q1 (3 points)
(define OR-GATE
  (lambda (a b)
    (if (= 1 a)             ;check if a is 1
        1                   ;return 1
        (if (= 1 b)         ;else check if b is 1
            1               ;return 1
            0               ;else return 0
        )
    )    
  )
)
            
(define AND-GATE
  (lambda (a b)
    (if (= 2 (+ a b))       ;check if a+b = 2
        1                   ;return 1
        0                   ;else return 0
    )
  )
)  
              
(define NOT-GATE
  (lambda (a)
    (if (= a 1)             ;check if a = 1
        0                   ;if true, return 0
        1                   ;else, return 1
    )   
  )
)
                   
; Test cases
(AND-GATE 0 0)
(AND-GATE 0 1)
(AND-GATE 1 0)
(AND-GATE 1 1)
;0
;0
;0
;1
(newline)
(OR-GATE 0 0)
(OR-GATE 0 1)
(OR-GATE 1 0)
(OR-GATE 1 1)
;0
;1
;1
;1
(newline)
(NOT-GATE 0)
(NOT-GATE 1)
;1
;0

;Q2 (3 points)
(define XOR-GATE
  (lambda (a b)
    (OR-GATE (AND-GATE b (NOT-GATE a)) (AND-GATE a (NOT-GATE b)))        ;((NOT a) AND b) OR (a AND (NOT b)))
  )  
)

; Test cases
(newline)
(XOR-GATE 0 0)
(XOR-GATE 0 1)
(XOR-GATE 1 0)
(XOR-GATE 1 1)
;0
;1
;1
;0

;Q3
;Q3.1 (3 points)
(define halfAdder
  (lambda (x a b)
    (XOR-GATE (XOR-GATE a b) x)                                            ;half adder returns the sum bit s: (x XOR (a XOR b))
  )
)
                  
;Q3.2 (3 points)
(define carry-out
  (lambda (x a b)
    (OR-GATE (AND-GATE (XOR-GATE a b) x) (AND-GATE a b))                   ;carry out returns the carryOut bit c: ((a AND b) OR (x AND (a XOR b)))
  )
)
                  
;Q3.3 (3 points)
(define fullAdder
  (lambda (x a b)
    (cons (halfAdder x a b) (carry-out x a b))                             ;formatting the outputs of carry-out and halfAdder for output: (halfAdder . carry-out)
  )
)
                  
; Test cases
(newline)
(fullAdder 0 0 0) 	
(fullAdder 0 0 1) 	
(fullAdder 0 1 0) 	
(fullAdder 0 1 1)	
(fullAdder 1 0 0) 	
(fullAdder 1 0 1)	
(fullAdder 1 1 0) 	
(fullAdder 1 1 1) 
;(0 . 0)
;(1 . 0)
;(1 . 0)
;(0 . 1)
;(1 . 0)
;(0 . 1)
;(0 . 1)
;(1 . 1)


;Q4
;Q4.1 (5 points)
(define tail
  (lambda (lst)
    (list-ref lst (- (length lst) 1))                                 ;using list ref to get the element at location (len lst - 1)
  )
)
;Q4.2 (5 points)
(define rmtail
  (lambda (lst)
    (reverse (cdr (reverse lst)))                                     ;reversing the list, removing the first element, and then reversing once again
  )
)  
                
;Q4.4 (15 points)
(define X1 '(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0) )	
(define X2 '(1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1) )	
(define X3 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1) )	
(define X4 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0) )
(define X5 '(0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1) )	
(define X6 '(1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1) )

(define n-bit-adder
  (lambda (L1 L2 n)
    (n-bit-adderhelper L1 L2 n (cons '() 0))                 ;calling n-bit-adderhelper                                                                          
  )
)  

(define n-bit-adderhelper
  (lambda (L1 L2 n resulti)
    (if (= n 0)                                             ;base case (stopping condition)
        (n-bit-adder-carry-out L1 L2 n resulti)             ;corresponding return value function call
        (let ((sum-carry (fullAdder (cdr resulti) (tail L1) (tail L2) )))    ;formulating size m problem
          (let ((sum (car sum-carry)) (carry (cdr sum-carry)))                  ;formulating size m problem pt 2
            (n-bit-adderhelper (rmtail L1) (rmtail L2) (- n 1) (cons (append (list sum) (car resulti)) carry))       ;recursive call of n-bit-adderhelper
          )
        )
    )
  )
)  

(define n-bit-adder-carry-out
  (lambda (L1 L2 n resulti)
    (append (list (list (cdr resulti))) (car resulti))                    ;return value at the end of recursion
  )
)  

;Test cases
(newline)
(n-bit-adder  X1 X2 32)
(n-bit-adder  X3 X4 32)
(n-bit-adder  X5 X6 32)
(n-bit-adder  X2 X3 32)
(n-bit-adder  X4 X5 32)
(n-bit-adder  X1 X6 32)
(newline)
(n-bit-adder  X1 X3 32)
(n-bit-adder  X1 X4 32)
(n-bit-adder  X1 X5 32)
(n-bit-adder  X2 X4 32)
(n-bit-adder  X2 X5 32)
(n-bit-adder  X2 X6 32)

;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((0) 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0)
;((1) 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1)

;((0) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1)
;((0) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0)
;((0) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1)
;((1) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 1)
;((1) 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 0)
;((1) 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0)
