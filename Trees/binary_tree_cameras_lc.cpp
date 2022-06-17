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
    vector<int> solve(TreeNode* root) {
        if(root == NULL) {
            return {0, 0, 10000000}; // since if this node is null we can't have camera here
        }
        vector<int>left = solve(root->left);
        vector<int>right = solve(root->right);

        int minL = min(left[1], left[2]);
        int minR = min(right[1], right[2]);

        int state0 = left[1] + right[1]; // all child must be in state 1
        int state1 = min(left[2] + minR, right[2] + minL); // atleast one child in state 2
        int state2 = 1 + min(left[0], minL) + min(right[0], minR); // child can be in any state

        return {state0, state1, state2};
    }

    int minCameraCover(TreeNode* root) {
        vector<int>ans = solve(root);
        return min(ans[1], ans[2]);
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