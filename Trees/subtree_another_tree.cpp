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

    TreeNode* sub_root;

    bool check(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;

        if(root->val != subRoot->val) return false;

        return check(root->left, subRoot->left) and check(root->right, subRoot->right);
    }

    bool solve(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;

        if(check(root, subRoot)) return true; 
             
        subRoot = sub_root;

        return solve(root->left, subRoot) || solve(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        sub_root = subRoot;
        if(sub_root == NULL) return true;
        if(root == NULL) return false;

        return solve(root, subRoot);
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