/*********************************************************************
** Program Filename: lists.c
** Author: Helena Bales
** Date: 06/06/2014
** Description: creates and provides functionality for linked lists
** Input: integer values
** Output: pointer to a linked list of values
*********************************************************************/

#include "./list.h"

/*********************************************************************
** Function: length
** Description: gets the length of the linked list
** Parameters: struct node * currentnodepointer- a pointer to the
**		first value in the linked list
** Pre-Conditions: none
** Post-Conditions: the length of the list is returned
*********************************************************************/ 
int length(struct node * currentnodepointer) {
	int length = 0;

	if(currentnodepointer == NULL) {
		return length;
	}

	do {
		//adds 1 to length while there is a next value
		length += 1;
		//sets the pointer to the current element to the pointer to the
		//next element
		currentnodepointer = currentnodepointer->next;

	}while(currentnodepointer != NULL);
	return length;
}

/*********************************************************************
** Function: push
** Description: pushes a new value onto the front of the list
** Parameters: struct node ** head- the address of the pointer to the
** 	start of the list; int number- the value to push on
** Pre-Conditions: the pointer exists
** Post-Conditions: the new value is added to the front of the list
*********************************************************************/
void push(struct node ** headnode, int number) {
	
	//temp holds where head was pointing
	//this value with become the second element in the list
	struct node *temp = *headnode;
	//make the new node
	(*headnode) = malloc(sizeof(struct node));
	//new node gets the value
	(*headnode)->val = number;
	//new node gets the address of the second node
	(*headnode)->next = temp;
	
	return;
}

/*********************************************************************
** Function: append
** Description: appends a new value onto the end of the list
** Parameters: node head, int number- the value to append on
** Pre-Conditions: the pointer exists (can be null)
** Post-Conditions: a new value is added to the end of the list
*********************************************************************/
void append(struct node ** head, int number) {
	struct node *currentnode;
	
	//case 1: no elements in the list yet
	if((*head) == NULL) {
		//head points to new element
		(*head) = malloc(sizeof(struct node));
		//new element gets value
		(*head)->val = number;
		//new element points to NULL
		(*head)->next = NULL;
		
		return;
	}
	
	//case 2: list contains elements
	else {
		//currentnode gets the value of head
		//currentnode will find the end of the list
		currentnode = (*head);
		while(currentnode->next != NULL) {
			//iterate through the list while the end has not yet been found
			currentnode = currentnode->next;
		}
		//current node now has the end of the list
		//make new element
		currentnode->next = malloc(sizeof(struct node));
		//new element gets the value
		currentnode->next->val = number;
		//new element is at the end so points to 
		currentnode->next->next = NULL;
		
	}

}

/*********************************************************************
** Function: print
** Description: prints the linked list 
** Parameters: node *currentnode- the pointer to the linked list
** 	(head); int number- the length of the linked list
** Pre-Conditions: number contains the length of the list
** Post-Conditions: the list is printed
*********************************************************************/
void print(struct node *currentnode, int number) {
	int i;
	
	for(i = 0; i < number; i++) {
		//prints out the value of the node pointed to
		printf("%d ", currentnode->val);
		//iterates through the list
		currentnode = currentnode->next;
	}
	printf("\n");
}

/*********************************************************************
** Function: sort_ascending
** Description: sorts the list in ascending order of values
** Parameters: struct node ** head- the head pointer's address
** Pre-Conditions: the pointer exists
** Post-Conditions: the list is sorted in ascending value order
*********************************************************************/
void sort_ascending(struct node ** head) {
	struct node *temp;
	struct node *temp2;
	
	if((*head) == NULL) {
		return;
	}
	temp = (*head);
	do{
		//if the value is less than the prev val, val gets moved to
		//the front of the list
		if((temp->next->val) < (temp->val)) {
			temp2 = temp->next->next;
			temp->next->next = (*head);
			(*head) = temp->next;
			temp->next = temp2;
			temp = (*head);
		}
		//once the value is not less than the prev value
		//iterate through the list
		else {
			temp = temp->next;
		}
	}while(temp->next != NULL);
	
	return;
}

/*********************************************************************
** Function: sort_descending
** Description: sorts the list in descending order
** Parameters: struct node ** head- the head of the list
** Pre-Conditions: the pointer exists
** Post-Conditions: the list is sorted in descending order
*********************************************************************/
void sort_descending(struct node ** head) {
	struct node *temp;
	struct node *temp2;
	
	if((*head) == NULL) {
		return;
	}
	temp = (*head);
	do{
		//if the value is more than the prev val, val gets moved to
		//the front of the list
		if((temp->next->val) > (temp->val)) {
			temp2 = temp->next->next;
			temp->next->next = (*head);
			(*head) = temp->next;
			temp->next = temp2;
			temp = (*head);
		}
		//once the value is not more than the prev value
		//iterate through the list
		else {
			temp = temp->next;
		}
	}while(temp->next != NULL);
	
	return;
}

/*********************************************************************
** Function: clear
** Description: deletes all of the elements in the list
** Parameters: struct node ** head- the address of the head of list
** Pre-Conditions: pointer exists
** Post-Conditions: the list contains no elements
*********************************************************************/
void clear(struct node ** head) {
	int i;
	
	for(i=length((*head)); i>0; i--) {
		//calls delete along the length of the list
		//always deletes the first element
		delete(head, 1);
	}
}

/*********************************************************************
** Function: delete
** Description: deletes an element in the list
** Parameters: struct node ** head; int del- the number of elements
** 	down the list to delete
** Pre-Conditions: pointer head exists, delete contains a number in
** 	range
** Post-Conditions: that number of element is deleted
*********************************************************************/
void delete(struct node ** head, int del) {
	int i;
	struct node *temp = NULL;
	struct node *temp2 = NULL;
	
	//case 1: deleting the first element
	if(del == 1) {
		//temp keeps track of where head was pointing to
		temp = (*head);
		temp->next = (*head)->next;
		//delete the element
		free((*head));
		//give head where temp was pointing to
		(*head) = temp->next;
	}
	
	//case 2: deleting any other element
	else {
		temp = (*head);
		//same as before but with this clever little iterative bit
		for(i=1; i<(del-1); i++) {
			temp = temp->next;
		}
		//also there's a second temp to keep track of where the element
		//was pointing to
		temp2 = temp->next->next;
		//free the element marked for deletion
		free((temp->next));
		//give the element before the deleted one the pointer
		//to the element after the deleted one
		temp->next = temp2;
	}
}

