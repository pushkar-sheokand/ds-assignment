#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

// Utility to get length of list
int getLength(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

// Function to get intersection point
Node *getIntersectionNode(Node *headA, Node *headB)
{
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Move longer list's head forward
    while (lenA > lenB)
    {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA)
    {
        headB = headB->next;
        lenB--;
    }

    // Move both heads until they meet
    while (headA && headB)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main()
{
    Node *common = new Node(8);
    common->next = new Node(10);

    Node *headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;

    Node *headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = common;

    Node *intersect = getIntersectionNode(headA, headB);
    if (intersect)
        cout << "Intersected at " << intersect->data;
    else
        cout << "No intersection";
}
