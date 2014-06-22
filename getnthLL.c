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

void deleteKey(struct node** headref, int key){
	struct node *temp, *prev;
	temp = *headref;

	if(temp == NULL) 
		return;

	if(temp->data == key){
		*headref = temp->next;
		free(temp);
		return;
	}

	while(temp->data != key){
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL){
		printf("No Deletion");
		return;
	}

	prev->next = temp->next;
	free(temp);

}

int getnth(struct node** headref, int key){
	int count = 0;
	struct node * n = NULL;
	n = *headref;

	while(count!=key){
		n = n->next;
		count++;
	}
	
	return n->data;
}

int main(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	struct node* newnode = NULL;
	int key, ch, ch1, ans;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	head->data = 4;
	head->next = second;

    second->data = 5 ;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    printf("\nOriginal List::\t\t");
    printList(head);

    ch1 = 0; 
    while(ch1 == 0){
			    printf("\nEnter choice::\n1.Insertion 2.Deletion 3. Get Nth element 4. Exit::");
			    scanf("%d",&ch);
			    switch(ch){
				    case 1:
				    		printf("\nEnter key for Insertion::\t");
				    		scanf("%d", &key);
							printf("\nInsertion in beg::\t");
						    insertBeg(&head,key);
						    printList(head);
						    continue;

					case 2:
				    
						    printf("\nEnter key for Deletion::\t");
						    scanf("%d", &key);

						    printf("\nAfter Deletion::\t");
						    deleteKey(&head,key);
						    printList(head);
						    continue;

					case 3:
					printf("\nEnter Index for nth element::");
					scanf("%d",&key);

					ans = getnth(&head,key);
					printf("Nth element = %d ",ans);
					
					continue;	    	

					case 4: 	ch1 = 1;
				}    
	}

	getchar();
	return 0;
}

