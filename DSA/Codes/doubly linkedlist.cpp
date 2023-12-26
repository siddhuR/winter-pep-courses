#include <iostream> 
#include <string> 
 
using namespace std; 
 
class Node { 
public: 
    string data; 
    Node* prev; 
    Node* next; 
 
    Node(string value) { 
        data = value; 
        prev = NULL; 
        next = NULL; 
    } 
}; 
 
class DoublyLinkedList { 
public: 
    Node* head; 
    Node* tail; 
 
    DoublyLinkedList() { 
        head = NULL; 
        tail = NULL; 
    } 
 
    void insertAtEnd(string data) { 
        Node* newNode = new Node(data); 
        if (!head) { 
            head = newNode; 
            tail = newNode; 
        } else { 
            newNode->prev = tail; 
            tail->next = newNode; 
            tail = newNode; 
        } 
    } 
 
    bool searchAndReplace(string searchId, string updatedId) { 
        Node* current = head; 
        while (current) { 
            if (current->data == searchId) { 
                current->data = updatedId; 
                return true; 
            } 
            current = current->next; 
        } 
        return false; 
    } 
 
    void displayList() { 
        Node* current = head; 
        while (current) { 
            cout << current->data << " "; 
            current = current->next; 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    int n; 
    cin >> n; 
 
    DoublyLinkedList feedbackList; 
 
    for (int i = 0; i < n; ++i) { 
        string entry; 
        cin >> entry; 
        feedbackList.insertAtEnd(entry); 
    } 
 
    string searchId, updatedId; 
    cin >> searchId >> updatedId; 
 
    if (feedbackList.searchAndReplace(searchId, updatedId)) { 
        cout << "Modified List: "; 
        feedbackList.displayList(); 
    } else { 
        cout << "Entry not found in the list." << endl; 
    } 
 
    return 0; 
}