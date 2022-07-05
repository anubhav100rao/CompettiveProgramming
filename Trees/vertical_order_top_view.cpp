#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct Node {
    int data;
    Node* left, *right;
};

class Solution1 { // vertical order traversal

public:

    
    vector<int> verticalOrder(Node *root) {
        vector<int>arr;
        queue<Node*>q;
        map<int, vector<int>>res;
        map<Node*, int>level;
        map<Node*, int>pos;
        
        if(root) {
            q.push(root);
            pos[root] = 0;
        }

        while(!q.empty()) {
            vector<Node*>curr_level;
            while(!q.empty()) {
                curr_level.push_back(q.front());
                res[pos[q.front()]].push_back(q.front()->data);
                q.pop();
            }


            for(int i = 0; i<curr_level.size(); i++) {
                Node* node = curr_level[i];
                if(node->left) {
                    q.push(node->left);
                    pos[node->left] = pos[node] - 1;
                }

                if(node->right) {
                    q.push(node->right);
                    pos[node->right] = pos[node] + 1;
                }
            }
        }

        for(auto &p: res)
            for(int &i: p.second)
                arr.push_back(i);
        return arr;
    }
};

class Solution2 { // top view
public:


    map<int, vector<int>> verticalOrder(Node *root) {
        vector<int>arr;
        queue<Node*>q;
        map<int, vector<int>>res;
        map<Node*, int>level;
        map<Node*, int>pos;
        
        if(root) {
            q.push(root);
            pos[root] = 0;
        }

        while(!q.empty()) {
            vector<Node*>curr_level;
            while(!q.empty()) {
                curr_level.push_back(q.front());
                res[pos[q.front()]].push_back(q.front()->data);
                q.pop();
            }


            for(int i = 0; i<curr_level.size(); i++) {
                Node* node = curr_level[i];
                if(node->left) {
                    q.push(node->left);
                    pos[node->left] = pos[node] - 1;
                }

                if(node->right) {
                    q.push(node->right);
                    pos[node->right] = pos[node] + 1;
                }
            }
        }

        for(auto &p: res)
            for(int &i: p.second)
                arr.push_back(i);
        return res;
    }

    vector<int> topView(Node *root) {
        map<int, vector<int>>res = verticalOrder(root);
        vector<int>arr;
        for(auto &p: res)
            arr.push_back(p.second[0]);
        return arr;
    }

};


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        map<int, vector<int>>res;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()) {
            vector<pair<TreeNode*, int>>curr_level;

            vector<pair<TreeNode*, int>>curr;

            while(!q.empty()) {
                auto [node, pos] = q.front();
                q.pop();
                curr.push_back({node, pos});
                curr_level.push_back({node, pos});
            }

            sort(curr.begin(), curr.end(), [&](pair<TreeNode*, int> &a, pair<TreeNode*, int> &b) {
                return a.first->val < b.first->val;
            });

            for(auto &[node, pos]: curr)
                res[pos].push_back(node->val);
            



            for(auto &[node, pos]: curr_level) {
                if(node->left) q.push({node->left, pos - 1});
                if(node->right) q.push({node->right, pos + 1});
            }
        }

        vector<vector<int>>arr;
        for(auto [a, b]: res)
            arr.push_back(b);
    
        return arr;
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