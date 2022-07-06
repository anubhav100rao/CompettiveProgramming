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
    
    map<TreeNode*, TreeNode*>parent;

    void dfs(TreeNode* node, TreeNode* par) {
        if(!node) return;
        parent[node] = par;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    void solve(TreeNode* root, vector<int>&dist, int height) {

    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        dfs(root, root);

        vector<int>res;
        set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*, int>dist;
        visited.insert(target);
        dist[target] = 0;

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            int curr_dist = dist[node];

            if(curr_dist == k) {
                res.push_back(node->val);
                continue;
            }


            if(node->left and !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
                dist[node->left] = curr_dist + 1;
            } 

            if(node->left and !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
                dist[node->left] = curr_dist + 1;
            }

            if(node->right and !visited.count(node->right)) {
                q.push(node->right);
                visited.insert(node->right);
                dist[node->right] = curr_dist + 1;
            }

            if(!visited.count(parent[node])) {
                q.push(parent[node]);
                visited.insert(parent[node]);
                dist[parent[node]] = curr_dist + 1;
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