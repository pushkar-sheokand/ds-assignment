#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node *rotateLeft(Node *head, int k)
{
    if (!head || k == 0)
        return head;

    Node *curr = head;
    int len = 1;
    while (curr->next)
    {
        curr = curr->next;
        len++;
    }

    curr->next = head; // make it circular
    k = k % len;

    Node *newTail = head;
    for (int i = 0; i < k - 1; i++)
        newTail = newTail->next;

    Node *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 6; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    int k = 2;
    head = rotateLeft(head, k);
    printList(head);
}
