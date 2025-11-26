#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
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

    // Function to reverse DLL in groups of size k
    Node* reverseInGroups(Node* head, int k) {
        if (!head) return nullptr;

        Node* current = head;
        Node* nextNode = nullptr;
        Node* newHead = nullptr;
        int count = 0;

        // Reverse first k nodes
        while (current && count < k) {
            nextNode = current->next;
            current->next = current->prev;
            current->prev = nextNode;
            newHead = current;  // new head after reversing k nodes
            current = nextNode;
            count++;
        }

        // Now 'head' points to the last node of the reversed group
        if (nextNode) {
            Node* restHead = reverseInGroups(nextNode, k);
            head->next = restHead;
            if (restHead)
                restHead->prev = head;
        }

        return newHead;
    }

    void reverseInGroups(int k) {
        head = reverseInGroups(head, k);
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <=> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);
    dll.insertEnd(4);
    dll.insertEnd(5);
    dll.insertEnd(6);

    int k = 2; // change to test Example 2 (k=4)
    cout << "Original DLL: ";
    dll.display();

    dll.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    dll.display();

    return 0;
}
