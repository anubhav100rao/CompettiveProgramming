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
    map<int, int>fre;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        int left = solve(root->left), right = solve(root->right);
        int tot = left + right + root->val;
        fre[tot]++;
        return tot;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<pair<int, int>>hsh;
        for(auto [a, b]: fre) {
            hsh.push_back({b, a});
        }
        sort(hsh.rbegin(), hsh.rend());
        int j = 0;
        while(j < hsh.size() and hsh[j].first == hsh[0].first) {
            j++;
        }
        vector<int>res;
        for(int i = 0; i < j; i++) {
            res.push_back(hsh[i].second);
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