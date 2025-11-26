#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// (a) Insertion at the beginning
void insertAtBeginning(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// (b) Insertion at the end
void insertAtEnd(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// (c) Insert before a specific node
void insertBefore(int val, int target)
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    if (head->data == target)
    {
        insertAtBeginning(val);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Target not found!\n";
        return;
    }
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// (c) Insert after a specific node
void insertAfter(int val, int target)
{
    Node *temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Target not found!\n";
        return;
    }
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// (d) Deletion from the beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

// (e) Deletion from the end
void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// (f) Deletion of a specific node
void deleteNode(int target)
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    if (head->data == target)
    {
        deleteFromBeginning();
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found!\n";
        return;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// (g) Search for a node
void search(int target)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            cout << "Node found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found!\n";
}

// (h) Display list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main Menu
int main()
{
    int choice, val, target;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Insert before which node? ";
            cin >> target;
            insertBefore(val, target);
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Insert after which node? ";
            cin >> target;
            insertAfter(val, target);
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter node value to delete: ";
            cin >> target;
            deleteNode(target);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> target;
            search(target);
            break;
        case 9:
            display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
