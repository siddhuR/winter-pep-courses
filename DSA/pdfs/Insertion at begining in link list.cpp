// C program to show inserting a node
// at front of given Linked List
#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct Node {
    int data;
    struct Node* next;
};
 
// Given a reference (pointer to pointer)
// to the head of a list and an int, inserts
// a new node on the front of the list.

void insertAtFront(struct Node** head_ref, int new_data)
{
 
    // 1. allocate node
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
 
    // 2. put in the data
    new_node->data = new_data;
 
    // 3. Make next of new node as head
    new_node->next = (*head_ref);
 
    // 4. move the head to point
    // to the new node
    (*head_ref) = new_node;
}
 
// Function to insert element in LL
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
// This function prints contents of
// linked list starting from head
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}
 
// Driver code
int main()
{
	int ITEM;
    // Start with the empty list
    struct Node* head = NULL;
  int arr[100],n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
   	scanf("%d",&arr[i]);
   	
   }
   for(int i=n-1;i>=0;i--)
   {
   	
   	push(&head, arr[i]);
   }
   	/*
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
 */
    printf("Created Linked list is: ");
    printList(head);
 
    // Insert 1 at the beginning.
   printf("Enter the element you want to insert at Begining: ");
    scanf("%d",&ITEM);
    
    insertAtFront(&head, ITEM);
 
    printf("After inserting %d at front: ", ITEM);
    printList(head);
 
    return 0;
}
