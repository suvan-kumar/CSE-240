// CSE240 Spring 2023 HW6
// Suvan Kumar
// Visual Studio

// Reminder that your file name is incredibly important. Please do not change it. 
// Reminder that we are compiling on Gradescope using GCC. 

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of game items like you'd see in a folder.
// Each item has this information: item name, game name, type of item, item ID.
// The struct 'itemRecord' holds the information of one item. Variety is an enum.
// A linked list of structs called 'list' is declared to hold the list of items.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters. Otherwise, you risk getting compilation errors.
// You are not allowed to modify main().
// You can use all string library functions.
// You will have to write your functions from scratch by looking at what is expected to be passed into them in the pre-existing functions

// WRITE COMMENTS FOR IMPORANT STEPS IN YOUR CODE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 15
#define MAX_NAME_LENGTH 25

typedef enum { Health = 0, Equip, Etc } itemType;		// enum type

struct itemRecord {						// struct for item details
	char itemName[MAX_NAME_LENGTH];
	char gameName[MAX_NAME_LENGTH];
	itemType variety;
	unsigned int itemID;
	struct itemRecord* next;				// pointer to next node
};

struct itemRecord* list = NULL;					// declare linked list 'list'

int count = 0;							// the number of items currently stored in the list (initialized to 0)

// functions already pre-implemented last homework
void flushStdIn();
void executeAction(char);
void save(char* fileName);
void display();				  

// functions that need implementation: add, sort, delete, load
int add(char* itemName_input, char* gameName_input, char* variety_input, unsigned int idNumber_input);			// 10 points
void sort();							// 10 points
int delete(unsigned int idNumber_input);			// 10 points
void load(char* fileName);					// 10 points
void swap(struct itemRecord* item1, struct itemRecord* item2);


int main()
{
	char* fileName = "Item_List.txt";
	load(fileName);			// load list of items from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new item\n");
		printf("\t d: display item list\n");
		printf("\t r: remove a item from list\n");
		printf("\t s: sort item list by ID\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName); 		// save list of items to file (overwrites file if it exists)
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
	unsigned int itemId_input, add_result = 0;
	char itemtype_input[20];
	switch (c)
	{
	case 'a':
		// input item record from user
		printf("\nEnter item name: ");
		fgets(itemName_input, sizeof(itemName_input), stdin);
		itemName_input[strlen(itemName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter game name: ");
		fgets(gameName_input, sizeof(gameName_input), stdin);
		gameName_input[strlen(gameName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter item type (Health/Equip/Etc): ");
		fgets(itemtype_input, sizeof(itemtype_input), stdin);
		itemtype_input[strlen(itemtype_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter item ID number: ");
		scanf("%d", &itemId_input);
		flushStdIn();


		// add the item to the list
		add_result = add(itemName_input, gameName_input, itemtype_input, itemId_input);
		if (add_result == 0)
			printf("\nItem is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nItem successfully added to the list! \n\n");
		else
			printf("\nUnable to add the item. the Item list is full! \n\n");

		break;

	case 'r':
		printf("Please enter ID number of item to be deleted: ");
		scanf("%d", &itemId_input);
		flushStdIn();
		int delete_result = delete(itemId_input);
		if (delete_result == 0)
			printf("\nItem not found in the list! \n\n");
		else
			printf("\nItem deleted successfully! \n\n");
		break;
	case 'd': 
		display();	
		break;
	case 's': 
		sort();	
		break;
	case 'q':
		break;
	default: printf("%c is invalid input!\n", c);
	}
}

// This function displays the item list with the details (struct elements) of each item. 
// Display all items.
void display()
{
	struct itemRecord* tempList = list;				// work on a copy of 'list'
	char* itemTypeString = "NoType";				// dummy init

	while (tempList != NULL) {					// traverse all items in the list
		printf("\nItem Name: %s", tempList->itemName);		// display the item name
		printf("\nGame name: %s", tempList->gameName);		// display the game name

		if (tempList->variety == Health)			// find what to display for item type
			itemTypeString = "Health";
		else if(tempList->variety == Equip)
			itemTypeString = "Equip";
		else
			itemTypeString = "Etc";
		printf("\nItem Type: %s", itemTypeString);		// display item type
		printf("\nItem ID: %d", tempList->itemID);		// display item id
		printf("\n");

		tempList = tempList->next;
	}
}

// save() is called at the end of main()
// This function saves the linked list of structures to file.
// save() is called at end of main() to save the item list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 20XX\Projects\Project1\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	struct itemRecord* tempList = list;		// work on a copy of 'list'

	FILE* file;
	int itemTypeValue = 0;
	file = fopen(fileName, "wb");			// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of items in the list

	// Parse the list and write item records to the file
	while (tempList != NULL) {
		fwrite(tempList->itemName, sizeof(tempList->itemName), 1, file);
		fwrite(tempList->gameName, sizeof(tempList->gameName), 1, file);
		// convert enum to a number for storing
		if (tempList->variety == Health)
			itemTypeValue = 0;		// 0 for Health
		else if(tempList->variety == Equip)
			itemTypeValue = 1;		// 1 for Equip
		else
			itemTypeValue = 2;		// 2 for Etc

		fwrite(&itemTypeValue, sizeof(itemTypeValue), 1, file);
		fwrite(&tempList->itemID, sizeof(tempList->itemID), 1, file);
		tempList = tempList->next;
	}

	fclose(file);					// close the file after writing
}

// Q1 : add (10 points)
// This function is used to add an item into the list. You can simply add the new item to the end of list (linked list of structs).
// Do not allow the item to be added to the list if it already exists in the list. You can do that by checking the item IDs already in the list.
// If the item already exists then return 0 without adding it to the list. If the item does not exist in the list, then add the item at the end of the list and return 1.
// If item list is full, then do not add new item to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You will likely pass the variety attribute as a string. This must be converted to an enum type because itemType has enum type. 
// The list should be case sensitive. For instance, 'Poprocks' and 'popRocks' should be considered two different names.
// Hint: 'count' holds the number of items currently in the list
int add(char* itemName_input, char* gameName_input, char* variety_input, unsigned int idNumber_input) {
	struct itemRecord* list2 = list;												//copy of list
	struct itemRecord* list3 = list;												//copy of list
	struct itemRecord* newItem;														//new struct itemReocrd item
	itemType item_enum;																//item_enum
	newItem = malloc(sizeof(struct itemRecord));									//allocating for space
	if (count == MAX_ITEMS) {														//check if list is full
		return 2;																	//return 2
	}	
	while (list2 != NULL) {															//check if list head isn't null
		if (list2->itemID == idNumber_input) {										//check if item id already exists
			return 0;																//return 0
		}
		else {
			list2 = list2->next;													//list = list.next
		}
	}
	if (strcasecmp(variety_input, "Health") == 0) {									//check variety input
		item_enum = Health;															//assign item_enum to Health
	}	
	else if (strcasecmp(variety_input, "Equip") == 0) {								//check variety input
		item_enum = Equip;															//assign item_enum to Equip
	}
	else {
		item_enum = Etc;															//assign Etc to item_enum
	}

	strcpy(newItem->itemName, itemName_input);										//use input to fill newItem
	strcpy(newItem->gameName, gameName_input);										//use input to fill newItem
	newItem->variety = item_enum;													//use input to fill newItem
	newItem->itemID = idNumber_input;												//use input to fill newItem
	newItem->next = NULL;															//use input to fill newItem
	if (list == NULL) {																//if list is null
		list = newItem;																//set head to newItem
	}
	else {
		while (list3->next != NULL) {												//iterate as long as next != NULL
			list3 = list3->next;													//list3 = list3.next
		}
		list3->next = newItem;														//assign new item to list3.next
	}
	count++;
	return 1;
} 

// Q2 : sort (10 points)
// This function is used to sort the list (linked list of structs) numerically by item ID.
// Parse the list and compare the item IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new node of structs having sorted items.
// Please use this print statement to print after successfully sorting the list:
// printf("\nItem list sorted! Use display option 'd' to view sorted list.\n");
void sort()
{
	struct itemRecord* list2 = list;											//work on copy of list

	for (int i = 0; i < count; i++) {											//iterate through list
		list2 = list;															//reset list2 to head of list
		for (int j = 0; j < count - 1; j++) {									//iterate through list - 1
			if (list2->itemID > list2->next->itemID) {							//check if itemIDs are in order
				struct itemRecord* tempItem;									//create new struct
				tempItem = malloc(sizeof(struct itemRecord));					//allocate space

				strcpy(tempItem->itemName, list2->itemName);					//copy itemName
				strcpy(tempItem->gameName, list2->gameName);					//copy gameName
				tempItem->variety = list2->variety;								//tempItem.variety = list2.variety
				tempItem->itemID = list2->itemID;								//tempItem.itemID = list2.itemID
				
				strcpy(list2->itemName, list2->next->itemName);					//copy itemName
				strcpy(list2->gameName, list2->next->gameName);					//copy gameName
				list2->variety = list2->next->variety;							//list2.variety = list2.next.variety
				list2->itemID = list2->next->itemID;							//list2.itemID = list2.next.itemID

				strcpy(list2->next->itemName, tempItem->itemName);				//copy itemName
				strcpy(list2->next->gameName, tempItem->gameName);				//copy gameName
				list2->next->variety = tempItem->variety;						//list2.next.variety = tempItem.variety
				list2->next->itemID = tempItem->itemID;							//list2.next.itemID = tempItem.itemID
			}
			list2 = list2->next;												//list2 = list2.next
		}
	}
	printf("\nItem list sorted! Use display option 'd' to view sorted list.\n");
}

// Q3 : delete (10 points)
// This function is used to delete an item by ID.
// Parse the list and compare the item IDs to check which one should be deleted.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int idNumber_input) 
{
	struct itemRecord* list2 = list;										//copy of list
	struct itemRecord* nodeRemover;											//removal struct itemRecord
	struct itemRecord* list3 = list;										//copy of list
	
	if (list2->itemID == idNumber_input) {									//check if itemID of list2 equals idNumber_input
		nodeRemover = list;													//set nodeRemover to list
		list = list2->next;													//list = list.next
		free(nodeRemover);													//free nodeRemover
		count--;															//decrement count
		return 1;															//return 1
	}

	while (list2 != NULL) {													//while list2 is not null
		if (list2->itemID == idNumber_input) {								//if itemID equals idNumber_input
			nodeRemover = list2;											//set nodeRemover to list2
			list3->next = list2->next;										//list3.next = list2.next
			free(nodeRemover);												//free nodeRemover
			count--;														//decrement count
			return 1;														//return 1
		}
		else {
			list3 = list2;													//set list3 = list2
			list2 = list2->next;											//list2 = list2.next
		}
	}
	return 0;																//return 0
}


// Q4:  load (10 points)
// This function is called in the beginning of main().
// This function reads the item list from the saved file and builds the linked list of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So, at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See the expected output of add() in homework the question file. It displays "Item_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the item list to read the item details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
// So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
// You can simply delete the file to 'reset the list' or to avoid loading from it.
// You'll need to use the following two print statements in your code: 
// printf("Item record loaded from %s.\n", fileName);
// printf("%s not found.\n", fileName);

void load(char* fileName)
{
	FILE *fileBuffer;																			//initialize fileBuffer
	fileBuffer = fopen(fileName, "rb");															//open file and set to read binary
	int itemNum = 0;																			//set itemNum to 0
	itemType itemEnum;																			//intialize itemEnum
	if (fileBuffer != NULL) {																	//check if fileBuffer is null
		fread(&count, sizeof(count), 1, fileBuffer);											//read count value from file
		for (int i = 0; i < count; i++) {														//iterate until count
			char itemName_input[MAX_NAME_LENGTH], gameName_input[MAX_NAME_LENGTH];				//intialize itemName and gameName char arrays
			unsigned int itemId_input;															//initialize itemId_input
			char itemtype_input[20];															//initialize char array itemtype_input
			fread(itemName_input, sizeof(itemName_input), 1, fileBuffer);						//read itemName from file
			fread(gameName_input, sizeof(gameName_input), 1, fileBuffer);						//read gameName from file
			fread(&itemNum, sizeof(itemNum), 1, fileBuffer);									//read itemNum from file
			if (itemNum == 0) {														    		
				char itemtype_input[20] = "Health";												//itemtype array = Health
			}
			else if(itemNum == 1) {
				char itemtype_input[20] = "Equip";												//itemtype array = Equip
			}
			else {
				char itemtype_input[20] = "Etc";												//itemtype = Etc
			}
			fread(&itemId_input, sizeof(itemId_input),1 , fileBuffer);							//read itemID 
			add(itemName_input, gameName_input, itemtype_input, itemId_input);					//read itemName
		}
		fclose(fileBuffer);																		//close file
		printf("Item record loaded from %s.\n", fileName);										//print statement
	}
	else {
		printf("%s not found.\n", fileName);													//print statement
	}
}

			
