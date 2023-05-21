#include <stdio.h>
#pragma warning(disable : 4996)

#define subm(a, b) (a-b)
#define squared_addm(a, b) (a * a + b * b)
#define evenm(a) ((a % 2 == 0) ? 1 : 0)
#define square_negative_numberm(a) ((a < 0) ? a * a : a)

int subf(int a, int b) { 
  return a - b; 
} 
 
int squared_addf(int a, int b) { 
  return a * a + b * b; 
} 
 
int evenf(int a) { 
  if (a % 2 == 0) { 
    return 1; 
  } 
  else { 
    return 0; 
  } 
} 
 
int square_negative_numberf(int a) { 
  if (a < 0) { 
    return a * a; 
  } 
  else { 
    return a; 
  } 
} 

int main() {
    int a = -2, b = 5; 
    printf("subf(a, b) = %d\n", subf(a, b)); 
    printf("subm(a, b) = %d\n", subm(a, b)); 
    printf("subf(++a, b--) = %d\n", subf(++a, b--)); 
    a = -2, b = 5;    // reset a, b values; 
    printf("subm(++a, b--) = %d\n", subm(++a, b--)); 
    
    a = -2, b = 5; 
    printf("squared_addf(a, b) = %d\n", squared_addf(a, b)); 
    printf("squared_addm(a, b) = %d\n", squared_addm(a, b)); 
    printf("squared_addf(++a, b--) = %d\n", squared_addf(++a, b--)); 
    a = -2; b = 5; 
    printf("squared_addm(++a, b--) = %d\n", squared_addm(++a, b--)); 
 
    a = -2; b = 5; 
    printf("evenf(a) = %d\n", evenf(a)); 
    printf("evenm(a) = %d\n", evenm(a)); 
    printf("evenf(a--) = %d\n", evenf(a--)); 
    a = -2; b = 5; 
    printf("evenm(a--) = %d\n", evenm(a--)); 
    
    a = -2; b = 5; 
    printf("square_negative_numberf(a) = %d\n", square_negative_numberf(a)); 
    printf("square_negative_numberm(a) = %d\n", square_negative_numberm(a)); 
    printf("square_negative_numberf(--a) = %d\n", square_negative_numberf(--a));
    a = -2; b = 5; 
    printf("square_negative_numberm(--a) = %d\n", square_negative_numberm(--a));

}