#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        DNode* newNode = new DNode(value);
        if (head == NULL) {
            head = newNode;
            return;
        }

        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        DNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void printList() {
        DNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;

    CNode(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    CNode* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        CNode* newNode = new CNode(value);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }

        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (head == NULL)
            return 0;

        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void printList() {
        if (head == NULL) {
            cout << "Empty list!" << endl;
            return;
        }

        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);

    cll.insertEnd(5);
    cll.insertEnd(15);
    cll.insertEnd(25);
    cll.insertEnd(35);

    cout << "Doubly List: ";
    dll.printList();
    cout << "Doubly Size: " << dll.getSize() << endl;

    cout << "Circular List: ";
    cll.printList();
    cout << "Circular Size: " << cll.getSize() << endl;

    return 0;
}