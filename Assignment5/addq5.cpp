#include <iostream>
using namespace std;

struct Node
{
    int coeff, pow;
    Node *next;
    Node(int c, int p) : coeff(c), pow(p), next(NULL) {}
};

Node *addPolynomial(Node *poly1, Node *poly2)
{
    Node *head = NULL, *tail = NULL;
    while (poly1 && poly2)
    {
        int coeff = 0, pow = 0;
        if (poly1->pow == poly2->pow)
        {
            coeff = poly1->coeff + poly2->coeff;
            pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow)
        {
            coeff = poly1->coeff;
            pow = poly1->pow;
            poly1 = poly1->next;
        }
        else
        {
            coeff = poly2->coeff;
            pow = poly2->pow;
            poly2 = poly2->next;
        }
        Node *newNode = new Node(coeff, pow);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (poly1)
    {
        tail->next = new Node(poly1->coeff, poly1->pow);
        tail = tail->next;
        poly1 = poly1->next;
    }
    while (poly2)
    {
        tail->next = new Node(poly2->coeff, poly2->pow);
        tail = tail->next;
        poly2 = poly2->next;
    }
    return head;
}

void printPoly(Node *head)
{
    while (head)
    {
        cout << head->coeff << "x^" << head->pow;
        if (head->next)
            cout << " + ";
        head = head->next;
    }
}

int main()
{
    Node *poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    Node *poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    Node *result = addPolynomial(poly1, poly2);
    printPoly(result);
}
