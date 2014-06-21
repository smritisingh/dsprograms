#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

void printList(struct node * n){
	//printf("\n");
	while(n != NULL){
		printf("%d\t",n->data);
		n = n->next;
	}
}

//insert in the beginning
void insertBeg(struct node** headref, int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = *headref;
	*headref = newnode;
	return;
}

//insert after
void insertAfter(struct node** headref, int after, int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;	

	struct node * afterlast = *headref;
 
	if(*headref == NULL){
		*headref = newnode;
		return;
	}

	while(afterlast->data != after){
		afterlast = afterlast->next;
	}

	newnode->next = afterlast->next;
	afterlast->next = newnode;	
	return;
}

//insert in the end
void insertEnd(struct node** headref, int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;	

	struct node * last = *headref;
 
	if(*headref == NULL){
		*headref = newnode;
		return;
	}

	while(last->next != NULL){
		last = last->next;
	}

	last->next = newnode;	
	return;
}

int main(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	struct node* newnode = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	head->data = 1;
	head->next = second;

    second->data = 2 ;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    printf("\nOriginal List::\t\t");
    printList(head);

	printf("\nInsertion in beg::\t");
    insertBeg(&head,0);
    printList(head);
    
    printf("\nInsertion in bet::\t");
    insertAfter(&head,2,3);
    printList(head);
    
    printf("\nInsertion in end::\t");
    insertEnd(&head,5);
    printList(head);

	getchar();
	return 0;
}
