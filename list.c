#include "./list.h"
// test test
int length(struct node * currentnodepointer) {
	int length = 0;

	if(currentnodepointer == NULL) {
		return length;
	}

	do {
		length += 1;
		currentnodepointer = currentnodepointer->next;

	}while(currentnodepointer != NULL);
	return length;
}

void push(struct node ** headnode, int number) {
	
	struct node *temp = *headnode;
	(*headnode) = malloc(sizeof(struct node));
	(*headnode)->val = number;
	(*headnode)->next = temp;
	
	return;
}


void append(struct node ** head, int number) {
	struct node *currentnode;
	
	if((*head) == NULL) {
		(*head) = malloc(sizeof(struct node));
		(*head)->val = number;
		(*head)->next = NULL;
		
		return;
	}
	
	else {
		currentnode = (*head);
		while(currentnode->next != NULL) {
			currentnode = currentnode->next;
		}
		currentnode->next = malloc(sizeof(struct node));
		currentnode->next->val = number;
		currentnode->next->next = NULL;
		
	}

}


void print(struct node *currentnode, int number) {
	int i;
	
	for(i = 0; i < number; i++) {
		//printf("current node pointer: %p\n", currentnode);

		printf("%d ", currentnode->val);
		//printf("current node pointer (next): %p\n", currentnode->next);
		currentnode = currentnode->next;
		//printf("current node pointer (head): %p\n", currentnode);
	}
	printf("\n");
}


