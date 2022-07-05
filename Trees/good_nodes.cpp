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

    void solve(TreeNode* root, int &cnt, int mx) {
        if(root == NULL) return;

        if(root->val >= mx) cnt++;
        mx = max(mx, root->val);
        solve(root->left, cnt, mx);
        solve(root->right, cnt, mx);
    }

    int goodNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt, 0);
        return cnt;
    }
};


class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
         if (!root) return 0;
        if (!root->left && !root->right) return isleft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
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