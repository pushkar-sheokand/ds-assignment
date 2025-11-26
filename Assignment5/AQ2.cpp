#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert node at end
void insert(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to print linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        if (node->next != NULL)
            cout << "->";
        node = node->next;
    }
    cout << endl;
}

// Count and delete all occurrences of key
int deleteKey(int key)
{
    int count = 0;

    // Delete from beginning if head has key
    while (head != NULL && head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Delete rest of occurrences
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == key)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        }
        else
        {
            curr = curr->next;
        }
    }
    return count;
}

int main()
{
    // Build example list: 1->2->1->2->1->3->1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int x : arr)
        insert(x);

    cout << "Original List: ";
    printList(head);

    int key = 1;
    int count = deleteKey(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    printList(head);

    return 0;
}
