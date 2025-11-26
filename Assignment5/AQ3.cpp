#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at end
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

// Print list
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

// Find middle using slow & fast pointer
int findMiddle(Node *head)
{
    if (head == NULL)
        return -1; // empty list

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // move by 1
        fast = fast->next->next; // move by 2
    }
    return slow->data; // slow points to middle
}

int main()
{
    // Example list: 1->2->3->4->5
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr)
        insert(x);

    cout << "Linked List: ";
    printList(head);

    int middle = findMiddle(head);
    cout << "Middle Element: " << middle << endl;

    return 0;
}
