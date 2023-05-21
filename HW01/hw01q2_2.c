/* This C program demonstrates the switch statement without using breaks. */  
#include <stdio.h>   
int main() {    
    double a = 10, b = 20;         
    double f; 
    for (int i = 0; i < 5; i++) {
        printf("Enter math operation: "); 
        char ch = getchar();
        printf("ch = %c\n", ch);   
        switch (ch) {    
            case '+': 
                f = a + b; 
                printf("f = %f\n", f);
                break;  
            case '-': 
                f = a - b; 
                printf("f = %f\n", f);  
                break;
            case '*': 
                f = a * b; 
                printf("f = %f\n", f); 
                break; 
            case '/': 
                f = a / b; 
                printf("f = %f\n", f); 
                break; 
            default: 
                printf("invalid operator\n");    
        }   
        ch = getchar(); 
    }
}  