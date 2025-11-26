#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }
    
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    
    cout << head->data << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 20);
    insertEnd(head, 100);
    insertEnd(head, 40);
    insertEnd(head, 80);
    insertEnd(head, 60);

    cout << "Output: ";
    display(head);

    return 0;
}