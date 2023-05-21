// CSE240 Spring 2023 HW5
// Suvan Kumar
// Visual Studio

// Reminder that your file name is incredibly important. Please do not change it. 
// Reminder that we are compiling on Gradescope using GCC. 

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of game items like you'd see in a folder.
// Each item has this information: item's name, game's name, type of item, item ID.
// The struct 'itemRecord' holds information of one item. Variety is an enum.
// An array of structs called 'list' is made to hold the list of items.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters. Otherwise, you risk getting compilation errors.
// You are not allowed to modify main().
// You can use string library functions.

// WRITE COMMENTS FOR IMPORANT STEPS IN YOUR CODE.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) 					// for Visual Studio Only

#define MAX_ITEMS 15
#define MAX_NAME_LENGTH 25

typedef enum { Health = 0, Equip, Etc } itemType;		// enum type 

struct itemRecord {						// struct for item details
	char itemName[MAX_NAME_LENGTH];
	char gameName[MAX_NAME_LENGTH];
	itemType variety;
	unsigned int itemID;
};

struct itemRecord list[MAX_ITEMS];				// declare list of items
int count = 0;							// the number of items currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);
void display();	

// functions that need implementation:
int add(char* itemName_input, 
		char* gameName_input, 
		char* variety_input, 
		unsigned int idNumber_input);			// 10 points
void sort();							// 10 points
int delete(unsigned int idNumber_input);			// 10 points
void load(char* fileName);					// 10 points


int main()
{
	char* fileName = "Item_List.txt";
	load(fileName);						// load list of items from file (if it exists). Initially there will be no file.
	char choice = 'i';					// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new item\n");
		printf("\t d: display item list\n");
		printf("\t r: remove an item from list\n");
		printf("\t s: sort item list by ID\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName);						// save list of items to file (overwrites file, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char itemName_input[MAX_NAME_LENGTH], gameName_input[MAX_NAME_LENGTH];
	unsigned int idNumber_input, add_result = 0;
	char variety_input[20];
	switch (c)
	{
	case 'a':
		// input item record from user
		printf("\nEnter item name: ");
		fgets(itemName_input, sizeof(itemName_input), stdin);
		itemName_input[strlen(itemName_input) - 1] = '\0';				// discard the trailing '\n' char
		printf("Enter game name: ");
		fgets(gameName_input, sizeof(gameName_input), stdin);
		gameName_input[strlen(gameName_input) - 1] = '\0';				// discard the trailing '\n' char
		printf("Enter whether item is a 'Health' or 'Equip' or 'Etc' item: ");
		fgets(variety_input, sizeof(variety_input), stdin);
		variety_input[strlen(variety_input) - 1] = '\0';				// discard the trailing '\n' char
		printf("Please enter item ID number: ");
		scanf("%d", &idNumber_input);
		flushStdIn();

		// add the item to the list
		add_result = add(itemName_input, gameName_input, variety_input, idNumber_input);
		if (add_result == 0)
			printf("\nItem is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nItem successfully added to the list! \n\n");
		else
			printf("\nUnable to add. Item list is full! \n\n");

		break;
	case 'r':
		printf("Please enter ID number of item to be deleted: ");
		scanf("%d", &idNumber_input);
		flushStdIn();
		int delete_result = delete(idNumber_input);
		if (delete_result == 0)
			printf("\nItem not found in the list! \n\n");
		else
			printf("\nItem deleted successfully! \n\n");
		break;
	case 'd': display();	break;
	case 's': sort();	break;
	case 'q': 		break;
	default: printf("%c is invalid input!\n", c);
	}
}

// This function displays the employee list with the details (struct elements) of each employee. 
void display()
{
	char* varietyString = "Health";							// dummy init

	for (int i = 0; i < count; i++)							// iterate through the list
	{
		printf("\nItem name: %s", list[i].itemName);				// display item's name
		printf("\nGame name: %s", list[i].gameName);				// display game's name

		if (list[i].variety == Health)						// find what to display for item type
			varietyString = "Health";
		else if (list[i].variety == Equip)
			varietyString = "Equip";
		else
			varietyString = "Etc";
		printf("\nItem Type: %s", varietyString);				// display item type
		printf("\nID Number: %d", list[i].itemID);				// display item's ID
		printf("\n");
	}

}

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the item list to a file.
// The file is saved at the same place as your C file. 
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	FILE* file;
	int i, varietyValue = 0;
	file = fopen(fileName, "wb");			// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of employees in the list

	// Parse the list and write employee record to file
	for (i = 0; i < count; i++)
	{
		fwrite(list[i].itemName, sizeof(list[i].itemName), 1, file);
		fwrite(list[i].gameName, sizeof(list[i].gameName), 1, file);
		// convert enum to a number for storing
		if (list[i].variety == Health)
			varietyValue = 0;		// 0 for HR
		else if (list[i].variety == Equip)
			varietyValue = 1;		// 1 for Marketing
		else
			varietyValue = 2;		// 2 for ITs

		fwrite(&varietyValue, sizeof(varietyValue), 1, file);
		fwrite(&list[i].itemID, sizeof(list[i].itemID), 1, file);
	}

	fclose(file);					// close the file after writing
}

// Q1 : add (10 points)
// This function is used to add an item into the list. You can simply add the new item to the end of list (array of structs).
// Do not allow the item to be added to the list if it already exists in the list. You can do that by checking item names OR IDs already in the list.
// If the item already exists then return 0 without adding it to the list. If the item does not exist in the list, then add the item at the end of the list and return 1.
// If the item list is full, then do not add new item to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of the executeAction() function.
// NOTE: You must convert the string 'variety_input' to an enum type and store it in the list because the item type has enum type (not string type).
// The list should be case sensitive. For instance, 'Mega Death Sword' and 'mega death sword' should be considered two different names.
// Hint: the global variable 'count' holds the number of items currently in the list
int add(char* itemName_input, char* gameName_input, char* variety_input, unsigned int idNumber_input)
{
	itemType item_enum;
	if (count == MAX_ITEMS) {								//checking if list is full
		return 2;											//return 2 if list is full
	}

	for (int i = 0; i < count; i++) {						//iterate through elements of list that are filled
		if (list[i].itemID == idNumber_input) {				//check to see in inputted id already exists
			return 0;										//return 0 if a match is found
		}
	}

	if (strcasecmp(variety_input, "Health") == 0) {			//comparing variety_input to "Health", returns 0 if equal
		item_enum = Health;									//set item_enum to Health
	}
	else if (strcasecmp(variety_input, "Equip") == 0) {		//comparing variety_input to "Equip", returns 0 if equal
		item_enum = Equip;									//set item_enum to Equip
	}
	else {
		item_enum = Etc;									//set item_enum to Etc
	}
	
	strcpy(list[count].itemName, itemName_input);			//Set list[count].itemName equal to itemName_input with null terminator
	strcpy(list[count].gameName, gameName_input);			//Set list[count].gameName equal to gameName_input with null terminator
	list[count].variety = item_enum;						//Set variety of list[count] to item_enum
	list[count].itemID = idNumber_input;					//Set itemID of list[count] to inputted idNumber
	count++;												//increment count
	return 1;												//return 1 to indicate that item has been added

}

// Q2 : sort (10 points)
// This function is used to sort the list (array of structs) numerically by the item's ID.
// Parse the list and compare the item IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new list of structs having sorted items.
// Hint: Use a temp struct (already declared) if you need to swap two structs in your logic
void sort()
{
	struct itemRecord itemTemp;								// needed for swapping structs. Not absolutely necessary to use.
	// Write the code below.
	// display message for user to check the result of sorting. Do not touch this
	for (int i = 0; i < count; i++) {										//iterate count number of times
		for (int j = 0; j < count - 1; j++) {								//iterate through the list - 1
			if (list[j].itemID > list[j + 1].itemID) {						//check if list[j] has a greated itemID than list[j + 1]
				itemTemp = list[j];											//item swap pt 1
				list[j] = list[j + 1];										//item swap pt 2
				list[j + 1] = itemTemp;										//item swap pt 3
			}
		}
	}
	printf("\nItem list sorted! Use display option 'd' to view sorted list.\n");
}

// Q3 : delete (10 points)
// This function is used to delete an item by ID.
// Parse the list and compare the item IDs to check which one should be deleted.
// Restore the array structure after removal of the item record.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int idNumber_input)
{
	struct itemRecord itemTemp;								// useful for swapping structs. Not absolutely necessary to use.
	// Write the code below
	int idPosition = -1;									//initialize idPosition with -1
	for (int i = 0; i < count; i++) {						//iterate through filled elements of the list
		if (list[i].itemID == idNumber_input) {				//check if itemID of list[i] equals input
			idPosition = i;									//set idPosition to element position in list 
		}
	}
	if (idPosition == -1) {									//check if idPosition's value hasn't been changed
		return 0;											//return 0 since specified ID was not found
	}	
	for (int i = idPosition + 1; i < count; i++) {			//iterate through list after the item that is to be removed
		list[i-1] = list[i];								//move element down 1 position
	}
	count--;												//decrease count
	return 1;												//return 1 for successful removal
}

// Q4:  load (10 points)
// This function is called in the beginning of main().
// This function reads the item list from the saved file and builds the array of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Item_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the item list to read the employee details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//      So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//	You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
	// Write the code below.
	// The following two print statements are used in your code. You can change their position but not their contents. 
	FILE *fileBuffer;																			//File pointer
	fileBuffer = fopen(fileName, "rb");															//open file and read binary
	if(fileBuffer != NULL) {																	//check if file is empty
		fread(&count, sizeof(count), 1, fileBuffer);											//specifying arguments for fread
		for (int i = 0; i < count; i++) {														//iterate through count
			fread(list[i].itemName, sizeof(list[i].itemName), 1, fileBuffer);					//reading itemName from file and assigning to list[i]
			fread(list[i].gameName, sizeof(list[i].gameName), 1, fileBuffer);					//reading gameName from file and assigning to list[i]
			fread(&list[i].variety, sizeof(list[i].variety), 1, fileBuffer);					//reading variety from file and assigning to list[i]
			fread(&list[i].itemID, sizeof(list[i].itemID), 1, fileBuffer);						//reading itemID from file and assigning to list[i]
		}
		fclose(fileBuffer);																		//close file
		printf("Item record loaded from %s.\n", fileName);										

	}
	else {
		printf("%s not found.\n", fileName);
	}

}
