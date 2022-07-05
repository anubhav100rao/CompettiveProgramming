#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:

    TreeNode* new_root = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);

        root->right = new_root;
        root->left = NULL;
        new_root = root;
    }
};

class Solution {
public:

    void dfs(TreeNode* root, TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return;
        root = new TreeNode(0);
        if(root1) root->val += root1->val;
        if(root2) root->val += root2->val;
        dfs(root->left, root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        dfs(root->right, root1 ? root1->right : NULL, root2 ? root2->right : NULL);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = NULL;
        dfs(root, root1, root2);
        return root;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    return 0;
}