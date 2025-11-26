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

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);
        cout << endl;
    }

    // Function to split into two halves
    void splitList(CircularLinkedList &firstHalf, CircularLinkedList &secondHalf) {
        if (!head) return;

        Node *slow = head, *fast = head;

        // Move fast by 2 and slow by 1
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // For even nodes, move fast to last node
        if (fast->next->next == head)
            fast = fast->next;

        // Set head of first and second halves
        firstHalf.head = head;
        if (head->next != head)
            secondHalf.head = slow->next;

        // Make both halves circular
        fast->next = slow->next;
        slow->next = head;
    }
};

int main() {
    CircularLinkedList cll, firstHalf, secondHalf;
    cll.insertEnd(10);
    cll.insertEnd(4);
    cll.insertEnd(9);

    cout << "Original Circular Linked List: ";
    cll.display();

    cll.splitList(firstHalf, secondHalf);

    cout << "First Half: ";
    firstHalf.display();
    cout << "Second Half: ";
    secondHalf.display();

    return 0;
}
