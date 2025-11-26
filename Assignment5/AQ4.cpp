#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    // Create list: 1->2->3->4->NULL
    Node *head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};

    cout << "Original List: ";
    for (Node *t = head; t != NULL; t = t->next)
        cout << t->data << "->";
    cout << "NULL\n";

    // Reverse
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    cout << "Reversed List: ";
    for (Node *t = head; t != NULL; t = t->next)
        cout << t->data << "->";
    cout << "NULL\n";

    return 0;
}
