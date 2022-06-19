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


class Solution {
public:

    map<TreeNode*, int>depth;

    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        return depth[root] = max(dfs(root->left), dfs(root->right)) + 1;
    }

    int ans = 0;

    void solve(TreeNode* root) {
        if(root == NULL) return;
        int curr = 0;
        if(root->left) curr += depth[root->left];
        if(root->right) curr += depth[root->right];

        ans = max(ans, curr);

        solve(root->left);
        solve(root->right);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        ans = max(ans, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // TreeNode* temp = root;
        // dfs(temp);
        // temp = root;
        // solve(temp);
        maxDepth(root);
        return ans;
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