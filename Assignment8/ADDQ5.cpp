#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *build(vector<int> &preorder, vector<int> &inorder,
            int &preIndex, int inStart, int inEnd, unordered_map<int, int> &mp)
{

    if (inStart > inEnd)
        return NULL;

    Node *root = new Node(preorder[preIndex++]);
    int mid = mp[root->val];

    root->left = build(preorder, inorder, preIndex, inStart, mid - 1, mp);
    root->right = build(preorder, inorder, preIndex, mid + 1, inEnd, mp);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    int preIndex = 0;
    return build(preorder, inorder, preIndex, 0, inorder.size() - 1, mp);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Node *root = buildTree(preorder, inorder);
    cout << "Tree Built Successfully";
}
