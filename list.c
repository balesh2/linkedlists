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

void sort_ascending(struct node ** head) {
	int i;
	int right = 0;
	struct node *temp;
	
	temp = (*head);
	do {
		for(i=0; i<length((*head)); i++) {
			printf("temp next val: %i", temp->next->val);
			printf("temp val: %i", temp->val);
			if((temp->next->val) < (temp->val)) {
				print((*head), length((*head)));
				push(head, temp->next->val);
				print((*head), length((*head)));
				delete(head, (i+3));
				print((*head), length((*head)));
			}
			else {
				right += 1;
			}
			temp = temp->next;
		}
	}while(right != length((*head)));
}

void clear(struct node ** head) {
	int i;
	
	for(i=length((*head)); i>0; i--) {
		delete(head, 1);
	}
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

