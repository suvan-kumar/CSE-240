; Name: Suvan Kumar
; CSE 240 Spring 2023
; Encryption

(define encrypt
	(lambda (str)
          (list->string (map encrypt-vowels (string->list str))) ; call encrypt-vowels for each character of str as a list using map function
        )
)  


(define encrypt-vowels
  (lambda (c)  
    (if (char=? c #\a)   ;checking for a
        #\?
        (if (char=? c #\A) ;checking for A
            #\?
            (if (char=? c #\e) ;checking for e
                #\!
                (if (char=? c #\E) ;checking for E
                    #\!
                    (if (char=? c #\o) ;checking for o
                        #\+
                        (if (char=? c #\O) ;checking for O
                            #\+
                            (if (char=? c #\u) ;checking for u
                                #\-
                                (if (char=? c #\U) ;checking for U
                                    #\-
                                    (if (char=? c #\i) ;checking for i
                                        #\*
                                        (if (char=? c #\I) ;checking for I
                                            #\*
                                            c)))))))))) ;return c is not a vowel
  )
)


; Decryption

(define decrypt
	(lambda (str)
          (list->string (map decrypt-vowels (string->list str))) ;call decrypt-vowels for each character of str as a list using map function
        )
)

(define decrypt-vowels
  (lambda (c)
    (if (char=? c #\?) ;check for ?
        #\a
        (if (char=? c #\!) ;check for !
            #\e
            (if (char=? c #\+) ;check for +
                #\o
                (if (char=? c #\-) ;check for -
                    #\u
                    (if (char=? c #\*) ;check for *
                        #\i
                        c))))) ;return c if not an encrypted char
  )
)

; Tests
(encrypt "Zebra is a horse")
(decrypt (encrypt "Zebra is a horse"))
(encrypt "COMPUTER science")
(decrypt (encrypt "COMPUTER science"))

