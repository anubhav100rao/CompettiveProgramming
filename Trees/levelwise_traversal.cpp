#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            vector<Node*>currLevel;
            vector<int>res;
            while(!q.empty()) {
                currLevel.push_back(q.front());
                q.pop();
            }
            int mx = INT_MIN;
            for(auto node: currLevel) {
                res.push_back(node->val);
                for(auto child: node->children) {
                    if(child) {
                        q.push(child);
                    }
                }
            }
            ans.push_back(res);
            
            
        }   
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