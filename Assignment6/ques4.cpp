#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(char val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool checkPalindrome() {
        Node* front = head;
        Node* back = tail;

        while (front != nullptr && back != nullptr) {
            if (front->data != back->data) {
                return false;
            }
            if (front == back || front->prev == back) {
                break;
            }
            front = front->next;
            back = back->prev;
        }
        return true;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.addNode('a');
    dll.addNode('b');
    dll.addNode('c');
    dll.addNode('b');
    dll.addNode('a');

    cout << "List: ";
    dll.printList();

    if (dll.checkPalindrome()) {
        cout << "Is palindrome" << endl;
    } else {
        cout << "Not palindrome" << endl;
    }

    return 0;
}