#include<stdio.h> 
#include<stdlib.h> 
#include "intList.h"
  
int findmax(Node*); 
  
int findmax(Node* head) 
{ 
    int max = INT_MIN; 
    while (head != NULL) {  
        if (max < head->num) 
            max = head->num; 
        head = head->next; 
    } 
    return max; 
}
typedef struct myStr{
	int num;
	struct myStr *next;	
}NewNode;

Node* makeN(Node* head,int n){
	Node  *element;
	element =   (Node*) malloc(sizeof(Node));
	element->num = n;
	element->next = head;
	return element;
} 


Node* delete_item(Node* curr, int x) {
    Node* next;
    if (curr == NULL) { // Found the tail
        printf("not found\n");
        return NULL;
    } else if (curr->num == x) { // Found one to delete
        next = curr->next;
        free(curr);
        return next;
    } else { // Just keep going
        curr->next = delete_item(curr->next, x);
        return curr;
    }
}

main() { 
Node *myList = makeList();
printList(myList);
int max=0;
max= findmax(myList);
printf("\nThe Max Number is: %d\n",max); 

Node* newList = delete_item(myList, max);
printf("Deleted Max Number from List\n");
printList(newList);

Node* newInsert = makeN(newList,max);
printf("\nMax number added at head:\n");
printList(newInsert);

max= findmax(newInsert->next);
printf("\nThe Max Number is: %d\n",max);

newList = delete_item(newInsert, max);
printf("Deleted Max Number from List\n");
printList(newList); 

newInsert = makeN(newList,max);
printf("\nMax number added at head:\n");
printList(newInsert);

max= findmax(newInsert->next->next);
printf("\nThe Max Number is: %d\n",max);

newList = delete_item(newInsert, max);
printf("Deleted Max Number from List\n");
printList(newList); 

newInsert = makeN(newList,max);
printf("\nMax number added at head:\n");
printList(newInsert);


} 


