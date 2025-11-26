#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generate(int start, int end)
{
    if (start > end)
        return {NULL};
    vector<TreeNode *> res;

    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = generate(start, i - 1);
        vector<TreeNode *> right = generate(i + 1, end);

        for (auto l : left)
        {
            for (auto r : right)
            {
                TreeNode *node = new TreeNode(i);
                node->left = l;
                node->right = r;
                res.push_back(node);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    if (n == 0)
        return {};
    return generate(1, n);
}

int main()
{
    int n = 3;
    vector<TreeNode *> ans = generateTrees(n);
    cout << "Total Trees = " << ans.size();
}
