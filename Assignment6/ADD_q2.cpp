// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

// // Function to count number of 1s in binary representation
// int countParity(int n) {
//     int count = 0;
//     while (n) {
//         count += (n & 1);
//         n >>= 1;
//     }
//     return count;
// }

// class CircularLinkedList {
// public:
//     Node* head;
//     CircularLinkedList() { head = nullptr; }

//     void insertEnd(int val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = newNode;
//             newNode->next = head;
//             return;
//         }
//         Node* temp = head;
//         while (temp->next != head)
//             temp = temp->next;
//         temp->next = newNode;
//         newNode->next = head;
//     }

//     void removeEvenParityNodes() {
//         if (!head) return;

//         Node *curr = head, *prev = nullptr;

//         // Handle case where head may need to be deleted
//         bool firstPass = true;
//         do {
//             int parity = countParity(curr->data);
//             if (parity % 2 == 0) {
//                 // Delete this node
//                 if (curr == head) {
//                     // Find last node
//                     Node* last = head;
//                     while (last->next != head)
//                         last = last->next;

//                     // If only one node
//                     if (head->next == head) {
//                         delete head;
//                         head = nullptr;
//                         return;
//                     }
//                     last->next = head->next;
//                     Node* temp = head;
//                     head = head->next;
//                     curr = head;
//                     delete temp;
//                     if (curr == head && !firstPass) break;
//                 } else {
//                     prev->next = curr->next;
//                     Node* temp = curr;
//                     curr = curr->next;
//                     delete temp;
//                 }
//             } else {
//                 prev = curr;
//                 curr = curr->next;
//             }
//             firstPass = false;
//         } while (curr != head);
//     }

//     void display() {
//         if (!head) {
//             cout << "List is Empty" << endl;
//             return;
//         }
//         Node* temp = head;
//         do {
//             cout << temp->data;
//             temp = temp->next;
//             if (temp != head) cout << " -> ";
//         } while (temp != head);
//         cout << endl;
//     }
// };

// int main() {
//     CircularLinkedList cll;
//     cll.insertEnd(9);
//     cll.insertEnd(11);
//     cll.insertEnd(34);
//     cll.insertEnd(6);
//     cll.insertEnd(13);
//     cll.insertEnd(21);

//     cout << "Original CLL: ";
//     cll.display();

//     cll.removeEvenParityNodes();

//     cout << "After removing even parity nodes: ";
//     cll.display();
//     return 0;
// }


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

int countParity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

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

    void removeEvenParityNodes() {
        Node* curr = head;
        while (curr) {
            int parity = countParity(curr->data);
            if (parity % 2 == 0) {
                Node* toDelete = curr;
                if (curr == head) {
                    head = head->next;
                    if (head)
                        head->prev = nullptr;
                    curr = head;
                } else {
                    if (curr->prev)
                        curr->prev->next = curr->next;
                    if (curr->next)
                        curr->next->prev = curr->prev;
                    curr = curr->next;
                }
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
            if (temp) cout << " <=> ";
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(18);
    dll.insertEnd(15);
    dll.insertEnd(8);
    dll.insertEnd(9);
    dll.insertEnd(14);

    cout << "Original DLL: ";
    dll.display();

    dll.removeEvenParityNodes();

    cout << "After removing even parity nodes: ";
    dll.display();
    return 0;
}
