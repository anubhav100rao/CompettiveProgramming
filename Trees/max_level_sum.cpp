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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        if(root)
            q.push({root, 1});
        map<int, int>level_sum;


        while(!q.empty()) {
            vector<pair<TreeNode*, int>>curr_level;
            while(!q.empty()) {
                curr_level.push_back(q.front()); q.pop();
            }
            int sum = 0;
            for(auto [a, b]: curr_level) {
                sum += a->val;
            }

            level_sum[curr_level.back().second] = sum;

            for(auto [node, level]: curr_level) {
                if(node->left) {
                    q.push({node->left, level + 1});
                }
                if(node->right) {
                    q.push({node->right, level + 1});
                }
            }
        }
        int level = 1, ans INT_MIN;

        for(auto [a, b]: level_sum) {
            if(b > ans) {
                ans = b;
                level = a;
            }
        }
        return level;
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