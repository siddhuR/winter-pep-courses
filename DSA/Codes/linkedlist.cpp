#include<iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* newNode(const string& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node** root, int data) {
    Node* node = newNode(data);
    Node* ptr;
    if (*root == NULL) {
        *root = node;
    }
    else {
        ptr = *root;
        while(ptr->next != NULL) {
            ptr = ptr-> next;
        }
        ptr->next = node;
    }
}

void printLinkedList(Node* root) {
    while (root != Null) {
        cout << root->data <<"|"<<root->next<< " -> ";
        root = root->next;
    } 
    cout<<"NULL"<<endl;
}

void createLinkedList(int arr[], int n) {
    Node *root = NULL;
    for (int i=0;i<n;i++) {
        insertNewNode(&root, arr[i]);
    }
    return root;
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    Node* root = createLinkedList(arr, n);
    printLinkedLisr(root);
    return 0;   
}