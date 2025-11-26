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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool checkCircular() {
        if (head == nullptr) {
            return false;
        }

        Node* current = head->next;
        while (current != nullptr && current != head) {
            current = current->next;
        }

        return (current == head);
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.head->next->next->next->next = list.head;

    if (list.checkCircular()) {
        cout << "Circular list" << endl;
    } else {
        cout << "Not circular" << endl;
    }

    return 0;
}