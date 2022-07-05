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


    void dfs(TreeNode* root, vector<int>&res) {
        if(!root) return;
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        // vector<int>res;    
        // dfs(root, res);
        // return res[k-1];

        stack<TreeNode*>st;
        while(true) {
            while(root != NULL) {
                st.push(root);
                root = root->left;
            }
            TreeNode* top = st.top(); st.pop();
            if(--k == 0) return top->val;
            root = top->right;
        }
        return 0;
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