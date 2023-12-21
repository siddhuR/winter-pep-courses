#include <iostream>
#include <string>
using namespace std;
// Define the node structure
struct Node {
string data;
Node* next;
};
// Function to create a new node
Node* createNode(const string& data) {
Node* newNode = new Node;
newNode->data = data;
newNode->next = nullptr;
return newNode;
}
// Function to insert a node at the specified position in the linked list
void insertNode(Node** head, const string& data, int pos) {
Node* newNode = createNode(data);
if (pos == 1) {
// If the position is 1, make the new node the new head
newNode->next = *head;
*head = newNode;
} else {
Node* temp = *head;
// Traverse to the node just before the insertion position
for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
temp = temp->next;
}
if (temp == nullptr) {
// Invalid position, append the new node at the end of the list
Node* lastNode = *head;
while (lastNode->next != nullptr) {
lastNode = lastNode->next;
}
lastNode->next = newNode;
} else {
// Insert the new node into the list
newNode->next = temp->next;
temp->next = newNode;
}
}
}
// Function to display the linked list
void displayList(Node* head) {
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
};

int main() {
int n, pos;
string data;
Node* head = nullptr;
cin >> n;
for (int i = 1; i <= n; i++) {
cin >> data;
insertNode(&head, data, i);
}
cout << "Current Linked List:" << endl;
displayList(head);
cin >> data >> pos;
insertNode(&head, data, pos);
cout << "Updated Linked List:" << endl;
displayList(head);
return 0
}