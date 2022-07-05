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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root == NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {

            vector<TreeNode*>level;
            
            while(!q.empty()) {
                level.push_back(q.front());
                q.pop();
            }

            res.push_back(level.back()->val);

            for(int i = 0; i<level.size(); i++) {
                TreeNode* curr = level[i];
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

        }

        return res;
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