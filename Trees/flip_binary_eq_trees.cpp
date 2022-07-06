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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        
        if(root1->val != root2->val) return false;
        
        return (root1->val == root2->val)
            and (
                (flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right))
                            or
                (flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left))
            );
    }
};

class Solution {
public:

    void dfs(TreeNode* &root, int low, int high) {
        if(!root) return;

        if(root->val > high || root->val < low) {
            root = NULL;
            return;
        }
        dfs(root->left, low, high);
        dfs(root->right, low, high);
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
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