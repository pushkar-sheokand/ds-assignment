#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Convert BST to sorted DLL
void bstToDll(Node *root, Node *&head, Node *&prev)
{
    if (!root)
        return;

    bstToDll(root->left, head, prev);

    if (!prev)
        head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDll(root->right, head, prev);
}

// Merge two sorted doubly linked lists
Node *mergeDLL(Node *a, Node *b)
{
    Node dummy(0);
    Node *tail = &dummy;

    while (a && b)
    {
        if (a->val < b->val)
        {
            tail->right = a;
            a->left = tail;
            a = a->right;
        }
        else
        {
            tail->right = b;
            b->left = tail;
            b = b->right;
        }
        tail = tail->right;
    }

    tail->right = (a ? a : b);
    if (tail->right)
        tail->right->left = tail;

    return dummy.right;
}

int main()
{
    // Example trees
    Node *t1 = new Node(20);
    t1->left = new Node(10);
    t1->right = new Node(30);
    t1->left->left = new Node(25);
    t1->right->right = new Node(100);
    t1->right->left = new Node(50);

    Node *t2 = new Node(5);
    t2->right = new Node(70);

    Node *h1 = NULL, *p1 = NULL;
    bstToDll(t1, h1, p1);

    Node *h2 = NULL, *p2 = NULL;
    bstToDll(t2, h2, p2);

    Node *merged = mergeDLL(h1, h2);

    Node *cur = merged;
    while (cur)
    {
        cout << cur->val << " <—> ";
        cur = cur->right;
    }
    cout << "null";
}
