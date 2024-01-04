#include <iostream>
#include <string>
using namespace std;

// A linked list node
struct Node {
    string data;
    Node* next;
};

// Given a reference (pointer to pointer) to the head of a list and a string, inserts a new node at the front of the list.
void push(Node** head_ref, string new_data)
{
    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;

    // Make the new node point to the current head
    new_node->next = (*head_ref);

    // Update the head to point to the new node
    (*head_ref) = new_node;
}

// Given a reference (pointer to pointer) to the head of a list and a string, appends a new node at the end
void append(Node** head_ref, string new_data)
{
    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;

    // Store the head reference in a temporary variable
    Node* last = *head_ref;

    // Set the next pointer of the new node as NULL since it will be the last node
    new_node->next = NULL;

    // If the Linked List is empty, make the new node as the head and return
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next pointer of the last node to point to the new node
    last->next = new_node;
}

// This function prints the contents of the linked list starting from the head
void printList(Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    // Start with an empty list
    Node* head = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        push(&head, str);
    }

    cout << "Document:";
    printList(head);

    string new_string;
    cin >> new_string;

    // Insert the new string at the end
    append(&head, new_string);

    cout << "\nUpdated Document:";
    printList(head);

    return 0;
}
