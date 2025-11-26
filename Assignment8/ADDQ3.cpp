#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTree(vector<int> &arr)
{
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;
    Node *root = new Node(arr[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *cur = q.front();
        q.pop();

        if (arr[i] != -1)
            cur->left = new Node(arr[i]);
        if (cur->left)
            q.push(cur->left);
        i++;
        if (i >= arr.size())
            break;

        if (arr[i] != -1)
            cur->right = new Node(arr[i]);
        if (cur->right)
            q.push(cur->right);
        i++;
    }
    return root;
}

int maxDepth(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Node *root = buildTree(arr);
        cout << maxDepth(root) << endl;
    }
}
