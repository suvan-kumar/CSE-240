//CSE240 Spring 2023 HW4

// Suvan Kumar
// Visual Studio

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions 
// because you are supposed to use pointers for this homework. 
// DO NOT use arrays to store or to index the characters in the string

// Additional Note: Your output string WILL end up both uppercase and reversed when you match and concat. 
// This is expected behavior.

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]); 
void printStrings(char[NUM_STRINGS][STRING_LENGTH]); 
void toUppercase(char s[NUM_STRINGS][STRING_LENGTH]); 
char* reverseOneString(char s[STRING_LENGTH]); 
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH]); 
void wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH]); 
void concatStr(char strings[NUM_STRINGS][STRING_LENGTH], char result[NUM_STRINGS * STRING_LENGTH]); 



// Problem 1: initializeStrings (5 points)
// Use pointer 'ptr' to traverse the 2D array of characters variable 'strings' (input from user in main()) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];
	// Enter the code below
	for (int i = 0; i < NUM_STRINGS * STRING_LENGTH; i++) {			//iterate through the size of the array
		*ptr = '\0';												//setting element to a null terminator
		ptr++;														//increment pointer
	}
}

// Problem 2: printStrings (5 points)
// Use pointer 'ptr' to traverse the 2D character array 'strings' and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];
	// Enter the code below
	for (int i = 0; i < NUM_STRINGS; i++) {							//iterating through NUM_STRINGS
		for (int j = 0; j < STRING_LENGTH; j++) {					//iterating through STRING_LENGTH
			printf("%c", *ptr);										//printing character at ptr
			ptr++;													//increment pointer
		}
		printf("\n");												//print new line at the ned of each string
		
	}
}

// Problem 3: toUppercase (5 points)
// Convert the string in the array 's' to an uppercase string.
// Traverse the input using pointer 'p' and covert the character to an uppercase letter if it is lowercase.
// You need to write down the code to check whether or not the character is lowercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toUppercase(char strings[NUM_STRINGS][STRING_LENGTH]) {
	char* p = &strings[0][0];
	// enter code here
	for (int i = 0; i < NUM_STRINGS * STRING_LENGTH; i++) {			//iterating through size of strings
		if (*p <= 122 && *p >= 97) {								//checking ASCII value of character to see if it is lowercase
			*p -= 32;												//capitalizing lowercase character
		}
		p++;														//increment p
	}
}


// Problem 4: reverseOneString (5 points)
// Reverse the string s by using pointer.
// Use pointer 'ptr' and 'temp' char to swap 1st char with last, then 2nd char with (last-1) and so on..
// Finally return pointer 'ptr' which points to start of the reversed string.
// Hint: You might want to check if your logic works with even as well as odd length string.
//       You can write test code to print out the reversed string to check if your function works. (Don't include it in final submission)
char* reverseOneString(char s[STRING_LENGTH])
{
	char temp;						// not necessary to use this variable
	char* ptr = &s[0];					// pointer to start of string
	int len = strlen(s);
	// Enter the code below
	for (int i = 0; i < len / 2; i++) {								//iterating through half the size of s
		temp = *ptr;												//temp assigned to value at ptr
		*ptr = *&s[len - 1 - i];									//ptr assigned to char at s[len - 1 - i]
		*&s[len - 1 - i] = temp;									//s[len - 1 - i] assigned to value at temp
		ptr++;														//increment ptr
	}
	ptr = &s[0];													//reset ptr to start of reversed string
	return ptr;														//return ptr
}

// Problem 5: reverseStrings (5 points)
// Reverse all the strings in 'strings[][]'
// For each string in 'strings', use the reverseOneString() to reverse it.
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	// Enter the code below
	char* ptr = &strings[0][0];										//pointer to start of string
	for(int i = 0; i < NUM_STRINGS; i++) {							//iterating through NUM_STRINGS
		ptr = &strings[i][0];										//pointer to start of string at strings[i][0]
		reverseOneString(ptr);										//reverseOneString function call with ptr as an argument
	}
}

// Problem 6: wordMatch (5 points)
// This function must be working as follows:
// 1. Compare the strings in the 2D array with input string
// 2. If one of them matches with input string, print "Match found"
// 3. Else print "Match not found"
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Sun"  => print "Match found"
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Hello"  => print "Match not found"
void wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH])
{
	char* p = &strings[0][0];
	char* ip = input;
	int flag = 0;
	// enter code here
	int count = 0;													//count = 0
	for (int i = 0; i < NUM_STRINGS; i++) {							//iterate through NUM_STRINGS
		count = 0;													//reset count
		ip = input;													//reset ip to start of input
		p = &strings[i][0];											//set p to start of string[i][0]
		while (*p == *ip) {											//satisfies that char at p = char at ip
			count++;												//increment count
			p++;													//increment p
			ip++;													//increment ip
		}
		if (count == 50) {											//check to see if all characters in strings[i] were the same as input
			flag = 1;												//flag = 1
		}
	}

	if (flag == 1) {												//if flag = 1
		printf("Match found");										//print "Match found"
	}
	else {															//else
		printf("Match not found");									//print "Match not found"
	}
}

// Problem 7: concatStr (10 points)
// This function must be working as follows:
// 1. Concatenate the string in the array 'strings' together in a sentence.
// 2. Store the string to the array 'result'.
// 3. Print the string in the array 'result'.
// The sample output is shown in document
// NOTE: This is the function partially containing what you have implemented so far.
// Initialize the array 'result' first before you store a string to it.
// You may declare and use more pointers if needed.
// Hint: You'll want to pay special attention '\0' characters
void concatStr(char strings[NUM_STRINGS][STRING_LENGTH], char result[NUM_STRINGS * STRING_LENGTH]) {
	char* p_result = result;
	char* p_input = &strings[0][0];
	// enter code here
	// 1. Initialize result
	// 2. Append characters in strings array to result using pointers
	// 3. Print the string in the variable 'result' using pointer.
	for (int i = 0; i < NUM_STRINGS * STRING_LENGTH; i++) {			//iterate through size of result
		*p_result = '\0';											//initialize with null terminator
		p_result++;													//increment p_result
	}
	p_result = &result[0];											//reset p_result to start of result
	for (int i = 0; i < NUM_STRINGS; i++) {							//iterate through NUM_STRINGS
		p_input = &strings[i][0];									//set p_input to start of strings[i][0]
		while (*p_input != 0) {										//satisfying char at p_input isn't null terminator
			*p_result = *p_input;									//p_result = p_input
			p_input++;												//increment p_input
			p_result++;												//increment p_result
		}
		*p_result = ' ';											//add a space at the end of string
		p_result++;													//increment p_result
	}
	p_result = &result[0];											//reset p_result to the start of result
	while (*p_result != 0) {										//while char isn't null terminator
		printf("%c", *p_result);									//print char at p_result
		p_result++;													//increment p_result
	}
}
// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	char strings_Copy[NUM_STRINGS][STRING_LENGTH];
	int i;
	char input[STRING_LENGTH];
	char result[NUM_STRINGS * STRING_LENGTH];

	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);			// store input string
		input[strlen(input) - 1] = '\0';			// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}

	//Question 2
	printf("\nStandard Print:\n");
	printStrings(strings);

	//Question 3
	printf("\nChecking conversion to uppercase.\n");
	toUppercase(strings);
	printStrings(strings);
	
	//Question 4/5
	printf("\nChecking Reversing of Strings.\n");
	reverseStrings(strings);
	printStrings(strings);

	//Question 6
	printf("\nEnter a string to find a match: "); // prompt for string
	fgets(input, sizeof(input), stdin); // store input string
	input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)
	// Word match function call
	wordMatch(strings, input);

	//Question 7
	printf("\nThe concatenated string is: \n");
	concatStr(strings, result);
	printf("\n");

	return 0;
}
