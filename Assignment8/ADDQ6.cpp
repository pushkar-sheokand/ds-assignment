#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *build(vector<int> &inorder, vector<int> &postorder,
            int &postIndex, int inStart, int inEnd, unordered_map<int, int> &mp)
{

    if (inStart > inEnd)
        return NULL;

    Node *root = new Node(postorder[postIndex--]);
    int mid = mp[root->val];

    root->right = build(inorder, postorder, postIndex, mid + 1, inEnd, mp);
    root->left = build(inorder, postorder, postIndex, inStart, mid - 1, mp);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    int postIndex = postorder.size() - 1;
    return build(inorder, postorder, postIndex, 0, inorder.size() - 1, mp);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Node *root = buildTree(inorder, postorder);
    cout << "Tree Built Successfully";
}
