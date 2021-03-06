#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
	char ans;
	int num;
	struct node *head = NULL;
	do {
		printf("Enter a number: ");
		scanf("%d", &num);
		append(&head, num); //Change push to append...
		printf("Do you want another num (y or n): ");
		scanf("%1s",&ans);
	} while(ans=='y');

	//to test for length fumction
	printf("%d\n", length(head));
	
	print(head, length(head));
	
	sort_descending((&head));
	delete((&head), 2);
	print(head, length(head));
	
	clear((&head));
	sort_ascending((&head));
	sort_descending((&head));
	
	print(head, length(head));
	
	return 0;
}

