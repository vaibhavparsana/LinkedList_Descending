#include <stdio.h>
#include <stdlib.h>
typedef struct myStruct{
	int num;
	struct myStruct *next;	
}Node;
Node* makeNode(int n){
	Node  *element;
	element =   (Node*) malloc(sizeof(Node));
	element->num = n;
	element->next = NULL;
	return element;
}

void printList(Node *top){
	
	Node *head = top;
	while (head != NULL){    // head->next != NULL
	    printf("%d==>",head->num);
	    head = head->next;
	}
}

Node* makeList(){
	
	Node *head=NULL,*np,*last;
	int num;
	printf("Please enter integer numbers. Non-numeric value to terminate!");
    while (scanf("%d",&num)==1){
    	np = makeNode(num);
    	if (head== NULL)
    	   head = np;
    	else
    		last->next = np; 
		last = np;  	
	}
	getchar();
	return head;

}
