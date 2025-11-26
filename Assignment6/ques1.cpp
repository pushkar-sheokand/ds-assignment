#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    
    DNode(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

void insertEndDLL(DNode*& head, int value) {
    DNode* newNode = new DNode(value);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    DNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNodeDLL(DNode*& head, int key) {
    if (head == NULL) return;
    
    DNode* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    delete temp;
}

void searchDLL(DNode* head, int key) {
    DNode* current = head;
    while (current != NULL) {
        if (current->data == key) {
            cout << "Found " << key << " in Doubly Linked List." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Not Found." << endl;
}

void displayDLL(DNode* head) {
    DNode* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertEndCLL(CNode*& head, int value) {
    CNode* newNode = new CNode(value);
    
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    
    CNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void deleteNodeCLL(CNode*& head, int key) {
    if (head == NULL) return;
    
    CNode *current = head, *previous = NULL;
    
    if (current->data == key) {
        if (current->next == head) {
            delete current;
            head = NULL;
            return;
        }
        
        CNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        CNode* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    
    while (current->next != head && current->data != key) {
        previous = current;
        current = current->next;
    }
    
    if (current->data != key) {
        cout << "Node not found!" << endl;
        return;
    }
    
    previous->next = current->next;
    delete current;
}

void searchCLL(CNode* head, int key) {
    if (head == NULL) return;
    
    CNode* temp = head;
    do {
        if (temp->data == key) {
            cout << "Found " << key << " in Circular Linked List." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    cout << "Not Found." << endl;
}

void displayCLL(CNode* head) {
    if (head == NULL) return;
    
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    DNode* dllHead = NULL;
    CNode* cllHead = NULL;
    int option, type, value;
    
    while (true) {
        cout << endl << "1. Doubly Linked List" << endl;
        cout << "2. Circular Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> type;
        
        if (type == 3) break;
        
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "Enter operation: ";
        cin >> option;
        
        cout << "Enter value: ";
        cin >> value;
        
        if (type == 1) {
            if (option == 1) insertEndDLL(dllHead, value);
            else if (option == 2) deleteNodeDLL(dllHead, value);
            else if (option == 3) searchDLL(dllHead, value);
            else if (option == 4) displayDLL(dllHead);
        } 
        else if (type == 2) {
            if (option == 1) insertEndCLL(cllHead, value);
            else if (option == 2) deleteNodeCLL(cllHead, value);
            else if (option == 3) searchCLL(cllHead, value);
            else if (option == 4) displayCLL(cllHead);
        }
    }
    
    return 0;
}