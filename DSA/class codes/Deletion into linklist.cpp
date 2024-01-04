// A complete working C program
// to demonstrate deletion in
// singly linked list
#include <stdio.h>
#include <stdlib.h>
  
// A linked list node
struct Node {
    int data;
    struct Node* next;
};
  
/* Given a reference (pointer to pointer) to the head of a
   list and an int, inserts a new node on the front of the
   list. */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
  
/* Given a reference (pointer to pointer) to the head of a
   list and a key, deletes the first occurrence of key in
   linked list */
void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;
  
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
  
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
  
    // If key was not present in linked list
    if (temp == NULL)
        return;
  
    // Unlink the node from linked list
    prev->next = temp->next;
  
    free(temp); // Free memory
}
  
// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
  
// Driver code
int main()
{
	 struct Node* head = NULL;
  
	 int arr[100],n;
	 printf("Enter the size of Link List ");
   scanf("%d",&n);
    printf("Enter the elements of Link List ");
   for(int i=0;i<n;i++)
   {
   	scanf("%d",&arr[i]);
   	
   }
   for(int i=n-1;i>=0;i--)
   {
   	   	push(&head, arr[i]);
   }
    /* Start with the empty list */
   /* push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
  */
    printf("Created Linked List: ");
    printList(head);
    printf("\n Enter the Element you wants to delete:  ");
    int elem;
    scanf("%d",&elem);
    deleteNode(&head, elem);
    printf("Linked List after Deletion: ");
    printList(head);
    return 0;
}
