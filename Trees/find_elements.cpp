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

class FindElements {
public:
    unordered_set<int>hsh;
    
    void solve(TreeNode* root, int req = 0) {
        if(root == NULL) return;

        if(root->val == -1) root->val = req;
        hsh.insert(root->val);

        solve(root->left, root->val * 2 + 1);
        solve(root->right, root->val * 2 + 2);

    }

    FindElements(TreeNode* root) {
        solve(root);
    }
    
    bool find(int target) {
        return hsh.count(target);
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