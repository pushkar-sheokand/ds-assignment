#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random; // Extra pointer that may point to any node

    Node(int val) {
        data = val;
        next = prev = random = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to correct the random pointer
    void correctRandomPointer() {
        if (!head) return;

        Node* curr = head;
        Node* incorrectNode = nullptr;

        // Step 1: Find the node with incorrect random pointer
        while (curr) {
            if (curr->random && (curr->random->prev != curr && curr->random->next != curr)) {
                incorrectNode = curr;
                break;
            }
            curr = curr->next;
        }

        if (!incorrectNode) {
            cout << "No incorrect random pointer found!" << endl;
            return;
        }

        // Step 2: Correct the random pointer
        // For this problem, assume the correct pointer should point to the previous node.
        if (incorrectNode->prev)
            incorrectNode->random = incorrectNode->prev;
        else if (incorrectNode->next)
            incorrectNode->random = incorrectNode->next;
    }

    void display() {
        Node* temp = head;
        cout << "List (data <=> random):" << endl;
        while (temp) {
            cout << temp->data << " <=> ";
            if (temp->random)
                cout << temp->random->data;
            else
                cout << "NULL";
            cout << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);

    // Creating incorrect random link (2 points to head instead of previous)
    dll.head->random = nullptr;
    dll.head->next->random = dll.head;     // Wrong random pointer
    dll.head->next->next->random = nullptr;

    cout << "Before correction:" << endl;
    dll.display();

    dll.correctRandomPointer();

    cout << "After correction:" << endl;
    dll.display();

    return 0;
}
