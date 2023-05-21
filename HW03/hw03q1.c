// CSE240 Spring 2022 HW3

// Suvan Kumar
// Visual Studio
// Your code will be compiled and ran using GCC. Keep this in mind. 

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.

// Global Macro Values. They are used to define the size of 2D array of integers
#define NUM_ROWS 5
#define NUM_COLUMNS 5
#define NUM_STRINGS 5 
#define STRING_LENGTH 50

// Forward Declarations
void printMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void createMatrix();
void scalarMatrix(int[NUM_ROWS][NUM_COLUMNS], int);
void sumRowsDiv(int[NUM_ROWS][NUM_COLUMNS]);
void transposeMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH]);
void removeChar(char strings[NUM_STRINGS * STRING_LENGTH], char);
void splitAndPrintWords(char s[NUM_STRINGS*STRING_LENGTH]);

// Problem 1: printMatrix (5 points)
// Traverse the 2D array of the integers 'matrix' (input from main)
// and print the contents in the following format (actual contents may vary)
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Enter code below
	for(int i = 0; i < NUM_ROWS; i++) {				//iterating through the rows
		for(int j = 0; j < NUM_COLUMNS; j++) {	    //iterating through the columns
			printf("%d ", matrix[i][j]);			//printing each element
		}
		printf("\n");								//printing a new line
	}
}

// Problem 2: createMatrix (5 points)
// Create and return a 2D array of integers using a for loop
// to generate and print the following matrix:
// 0 1 2 3 4   
// 1 2 3 4 5
// 2 3 4 5 6
// 3 4 5 6 7
// 4 5 6 7 8
// Hint: Use printMatrix to print the result
void createMatrix(){
	// Enter code below
	int createdMatrix[NUM_ROWS][NUM_COLUMNS];		//declaring matrix
	for(int i = 0; i < NUM_ROWS; i++) {				//iterating through the rows
		for(int j = 0; j < 5; j++) {				//iterating through the columns
			createdMatrix[i][j] = i + j;			//filling the array element with value
		}
	}
	printMatrix(createdMatrix);						//function call to print the matrix
}

// Problem 3: scalarMatrix (5 points)
// Traverse the 2D array of integers 'matrix' and multiply each element of the matrix by a scalar value
// print the resulting matrix
// Hint: Use printMatrix to print the result

// e.g.
// 1 2 3	    2 4 6
// 4 5 6	=>  8 10 12
// 7 8 9        14 16 18
//
void scalarMatrix(int matrix[NUM_ROWS][NUM_COLUMNS], int multiple)
{
	// Enter code below
	for(int i = 0; i < NUM_ROWS; i++) {				//iterating through the rows
		for(int j = 0; j < NUM_COLUMNS; j++) {		//iterating through the columns
			matrix[i][j] *= multiple;				//multiplying element of the matrix by scalar value
		}
	}
	printMatrix(matrix);							//function call to print the matrix
}

// Problem 4: sumRowsDiv (5 points)
// Traverse the 2D array of the integers 'matrix' and print the sum of each row divided by 5 on its own line.
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15	=> 3 8 13 18 23
// 16 17 18 19 20
// 21 22 23 24 25
void sumRowsDiv(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Enter code below
	int sum = 0;									//initializing the sum variable
	for(int i = 0; i < NUM_ROWS; i++) {				//iterating through the rows
		for(int j = 0; j < NUM_COLUMNS; j++) {		//iterating through the columns
			sum+= matrix[i][j];						//adding value of element to sum			
		}
		sum /= 5;									//dividing the sum of the row by 5
		printf("%d ", sum);							//printing value of sum
		sum = 0;									//resetting sum
	}
}


// Problem 5: transposeMatrix (5 points)
// Take the 2D array of integers 'matrix' and print the tranpose matrix.
// You may assume that row and column counts are equal.
// Hint: Use printMatrix to print the result
// e.g.
// 1 2 3 4 5			1 6 11 16 21
// 6 7 8 9 10			2 7 12 17 22
// 11 12 13 14 15	=>	3 8 13 18 23
// 16 17 18 19 20		4 9 14 19 24
// 21 22 23 24 25		5 10 15 20 25
void transposeMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Use this matrix to store each element
	int matrix2[NUM_ROWS][NUM_COLUMNS];			
	// Enter code below
	for(int i = 0; i < NUM_ROWS; i++) {				//iterating through rows
		for(int j = 0; j < NUM_COLUMNS; j++) {		//iterating through columns			
			matrix2[i][j] = matrix[j][i];			//flipping the rows and columns to store the matrix transposed
		}
	}
	printMatrix(matrix2);							//function call to print matrix
}

// Problem 6: reverseString (5 points)
// Reverse each string of strings[]. 
// Consider one string at a time and reverse the characters. For instance, "hi hello" should reverse to "olleh ih".
// begin with swapping first and last letter.
// We have 2 indices: i begins from start and increments, len begins from end and decrements
// run the swapping logic length/2 times
// return the string at the end.
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH])
{
	// Enter code below
	int len = 0;							//initializing len at 0
	while (strings[len] != '\0') {			//looping until null terminator is found
		len++;								//incrementing len	
	}
	len--;									//decrementing len 1
	for (int i = 0; i <= len; i++) {		//iterating through the length of strings
		char swap = strings[i];				//swap step 1
		strings[i] = strings[len];			//swap step 2
		strings[len] = swap;				//swap step 3
		len--;								//decrement len since element at len has been swapped
	}
}



// Problem 7: removeChar (5 points)
// "Remove" all occurrences of the specified character 'remove' from s[].
// To accomplish this, you will copy the contents of s into the provided removed[] array while ignoring
// the specified character. Print the resulting array.
// Hint: You will want to keep track of the size of removed[] for printing.
void removeChar(char s[NUM_STRINGS * STRING_LENGTH], char remove)
{
	// Use this array and integer to store the new string
	char removed[NUM_STRINGS*STRING_LENGTH];
	int removed_size = 0;
	// Enter code below
	int len = 0;										//initailizing len at 0
	while (s[len] != '\0') {							//looping until null terminator is found
		len++;											//incrementing len
	}
	for (int i = 0; i <= len; i++) {					//iterating though the length of s
		if (s[i] == remove) {							//checking if element value equals specified character 'remove'
			removed_size++;								//increasing removed_size
		}
		else {
			removed[i-removed_size] = s[i];				//adding element to array removed if not equal to specified character
		}
	}
	for (int i = 0; i < len - removed_size; i++){		//looping through removed
		printf("%c", removed[i]);						//printing character at i
	}
	
}

// Problem 8: splitAndPrintWords (5 points)
// Split s[] into individual words and store them in str[][].
// Read s[] character by character and copy into str[][], such that word 1 is in str[0][], 
// word 2 is in str[1][], and so on. Print the char array str[][], so that the separated words are 
// printed on their own line. Finally return the number of words using the variable 'count'.
// Don't forget to initialize str[][] with the null terminator character '\0'.
// Hint: Words are separated by whitespace characters
// e.g. 
// "The quick brown fox jumped over the lazy dog"
// The
// quick
// brown
// fox
// jumped
// over
// the
// lazy
// dog
//
// *** IMPORTANT NOTE: Test Problems 7 under GCC. VS has been known to cause some minor character trimming issues, 
// if you experience these, try with GCC. ***
void splitAndPrintWords(char s[NUM_STRINGS*STRING_LENGTH]){
	char str[NUM_STRINGS][STRING_LENGTH];
	// Enter code below
	int len = 0;												//initializing len at 0
	while (s[len] != '\0') {									//looping until null terminator
		len++;													//incrementing len
	}
	for (int i = 0; i < NUM_STRINGS; i++) {						//iterating through the rows
		for (int j = 0; j < STRING_LENGTH; j++) {				//iterating through the columns
			str[i][j] = '\0';									//initializing with null terminator
		}
	}
	int row = 0;												//row = 0
	int column = 0;												//column = 0
	for (int i = 0; i < len; i++) {								//iterating through length of s
		if (s[i] == ' ') {										//checking value to see if it is a space
			row++;												//move to next row
			column = 0;											//reset column count
		}
		else {
			str[row][column] = s[i];							//copy element to specified row and column in str
			column++;											//move to next column
		}
	}

	for (int i = 0; i <= row; i++) {
		printf("%s\n", str[i]);									//print row in str
	}
	
}	

// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
// *** Modifying this code will disrupt the autograder ***
int main()
{
	printf("CSE240 HW3: 2D Integer Arrays\n\n");

	int matrix[NUM_ROWS][NUM_COLUMNS] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	printMatrix(matrix);
	printf("\n\n");
	createMatrix();
	printf("\n\n");
	scalarMatrix(matrix, 4);
	printf("\n");
	sumRowsDiv(matrix);
	printf("\n\n");
	transposeMatrix(matrix);
	printf("\n");

	printf("\nCSE240 HW3: 2D Character Arrays\n\n");

	char words[NUM_STRINGS * STRING_LENGTH];
	printf("\nEnter sentence with max 5 words: ");
	fgets(words, sizeof(words), stdin);
	reverseStrings(words);
	printf("\nReversed string: %s\n\n", words);
	printf("String with \'b\' removed:");
	removeChar(words, 'b');
	printf("\n\nSplit String: ");
	splitAndPrintWords(words);
	return 0;
}