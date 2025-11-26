#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node *reverseKGroup(Node *head, int k)
{
    Node *curr = head;
    int count = 0;
    while (curr && count < k)
    {
        curr = curr->next;
        count++;
    }
    if (count < k)
        return head; // fewer than k nodes

    // Reverse first k nodes
    Node *prev = NULL;
    curr = head;
    Node *next = NULL;
    count = 0;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        head->next = reverseKGroup(next, k);

    return prev;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << "->";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 9; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }
    int k = 3;
    head = reverseKGroup(head, k);
    printList(head);
}
