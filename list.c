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

void delete(struct node ** head, int del) {
	int i;
	struct node *temp = NULL;
	struct node *temp2 = NULL;
	
	if(del == 1) {
		temp = (*head);
		//printf("head (next): %p\n", (*head)->next);
		//printf("temp (next): %p\n", temp->next);
		temp->next = (*head)->next;
		//printf("temp (next): %p\n", temp->next);
		free((*head));
		(*head) = temp->next;
	}
	else {
		temp = (*head);
		//printf("temp : %p\n", temp);
		for(i=1; i<(del-1); i++) {
			//printf("temp (next): %p\n", temp->next);
			temp = temp->next;
		}
		//printf("temp: %p\n", temp);
		temp2 = temp->next->next;
		//printf("temp (nextx2): %p\n", temp->next->next);
		//printf("temp2: %p\n", temp2);
		free((temp->next));
		temp->next = temp2;
	}
}

