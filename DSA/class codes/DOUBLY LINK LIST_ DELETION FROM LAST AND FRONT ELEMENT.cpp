/*You are tasked with developing a program for a task management system 
that utilizes a doubly linked list to track and manage tasks. 
Each node in the doubly linked list represents a task with a unique ID. 
The program should allow for inserting tasks at the front, 
deleting tasks from the front and end of the list, 
and displaying the updated list of tasks after each operation.

Implement a doubly linked list where elements can be 
inserted at the front and deleted from the front and end of the list. */ 
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtFront(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void deleteAtFront(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    delete temp;
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }
    delete current;
}

void displayList(Node* head) {
    Node* current = head;

    if (current == NULL) {
        return;
    }

   // cout << "List elements: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int numElements, data;
cout<<"enter size:";
    cin >> numElements;
cout<<"enter element:";
    for (int i = 0; i < numElements; i++) {
        cin >> data;
        insertAtFront(&head, data);
    }

    displayList(head);
cout<<"deleteAtFront: ";
    deleteAtFront(&head);

    displayList(head);
cout<<"deleteAtEnd: ";
    deleteAtEnd(&head);

    displayList(head);

    return 0;
}
