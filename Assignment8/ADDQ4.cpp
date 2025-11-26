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
        Node *temp = q.front();
        q.pop();

        if (arr[i] != -1)
            temp->left = new Node(arr[i]);
        if (temp->left)
            q.push(temp->left);
        i++;
        if (i >= arr.size())
            break;

        if (arr[i] != -1)
            temp->right = new Node(arr[i]);
        if (temp->right)
            q.push(temp->right);
        i++;
    }
    return root;
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == size - 1)
                ans.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return ans;
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
        vector<int> out = rightView(root);

        for (int x : out)
            cout << x << " ";
        cout << endl;
    }
}
