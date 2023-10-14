//Date: 2023.10.14
//Purpose: A program that uses structures and pointers to 
// read in an Item name, quantitiy, price and amount, and 
// then displays it.

#include <stdio.h>
#include <stdlib.h> // for malloc

//Defining structures globally, so it can be accessed in any functions

struct sItem {
	char* itemName;
	int quantity;
	float price;
	float amount;

};

//function prototypes

void readItem(struct sItem *sPtr);
void printItem(struct sItem *sPtr);
//main function
int main() {
	struct sItem myItem;
	//myItem.itemName = malloc(50); //allocate memory for itemName, that was defined inside the struct. Not used, because we want to connect myItem and the ptr , not clone it.
	struct sItem* itemPtr = NULL; //declare a pointer pointing to NULL
	itemPtr = &myItem;
	itemPtr->itemName = (char*)malloc(50*sizeof(char)); //have to cast the malloc returned void pointer to type char*
	if (itemPtr->itemName == NULL) { // if allocation fails, exit 
		exit (-1);
	}
	//itemPtr = malloc(1 * sizeof(struct sItem)); //allocate memory for itemPtr, same as itemPtr &myItem, but this keeps them separated, myItem won't change
	//*itemPtr = myItem;
	readItem(itemPtr);
	printItem(itemPtr);
	free(itemPtr->itemName);
	return 0;
}

//function declaration
// sPtr.price does not exist, because a ptr does not have members
// (*sPtr).price refers to the value of price int inside the struct sPtr points to (has no name, dynamically allocated)
// (*sPtr).price == sPtr->price  just simpler, in structs
// scanf needs an address to store an int, so &(sPtr->price) is needed
// itemName is already an address, no & needed. (*sPtr).itemName equally good, but more complex notation
void readItem(struct sItem *sPtr) {
	printf("Please provide the item name:");
	scanf("%s", sPtr->itemName); 
	printf("\nPlease provide the price:");
	scanf("%f", &(sPtr->price));
	printf("\nPlease provide the quantity:");
	scanf("%i", &(sPtr->quantity));
	sPtr->amount = sPtr->price * sPtr->quantity;
	return;
}

void printItem(struct sItem* sPtr) { 
	printf("\nItem: %s", sPtr->itemName);
	printf("\nPrice: %.2f", sPtr->price);
	printf("\nQuantity: %i", sPtr->quantity);
	printf("\nAmount: %.2f", sPtr->amount);

	return;
}
