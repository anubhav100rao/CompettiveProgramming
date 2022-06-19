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

    map<TreeNode*, int>dp;
    map<TreeNode*, multiset<int>>pos;
    map<TreeNode*, int>sub_max;
    void dfs(TreeNode* root) {
        if(root == NULL)
            return;
        sub_max[root] = 1;
        dp[root] = 1;
        dfs(root->left);
        dfs(root->right);
        if(root->left and root->val == root->left->val) {
            sub_max[root] = max(sub_max[root], sub_max[root->left] + 1);
            pos[root].insert(sub_max[root->left]);
        }
            
        if(root->right and root->val == root->right->val) {
            sub_max[root] = max(sub_max[root], sub_max[root->right] + 1);
            pos[root].insert(sub_max[root->right]);
        }

        if(pos[root].empty()) {

        } else if(pos[root].size() == 1) {
            dp[root] += *pos[root].rbegin();
        } else {
            dp[root] += *pos[root].rbegin();
            auto itr = pos[root].rbegin();
            pos[root].erase(pos[root].lower_bound(*itr));
            dp[root] += *pos[root].rbegin();
        }
        
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        int ans = 0;
        for(auto &[a, b]: dp)
            ans = max(ans, b);
        return ans - 1;
    }
};

class Solution {
public:

    int ans = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int l = 0, r = 0;
        if(root->left and root->val == root->left->val)
            l += left + 1;
        if(root->right and root->val == root->right->val)
            r += right + 1;
        ans = max(ans, l + r);

        return max(l, r);
    }
   
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
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