#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    struct TrieNode {
        map<int, TrieNode*>children;
        bool isEnd = false;
    };
    TrieNode* root;

    void insert(vector<int>&nums, int k, int p) {
        TrieNode* temp = root;
        for(int &node: nums) {
            if(k == 0 and node % p == 0) break;
            if(!temp->children.count(node)) {
                temp->children[node] = new TrieNode();
            }
            temp = temp->children[node];
            if(node % p == 0) k--;
            temp->isEnd = true;
        }
    }

    int dfs(TrieNode* trieNode) {
        int ans = trieNode->isEnd;
        for(auto [a, b]: trieNode->children) {
            ans += dfs(b);
        }
        return ans;
    }

    int countDistinct(vector<int>& nums, int k, int p) {
        root = new TrieNode();

        int n = nums.size();
        vector<int>pre(n + 1, 0);
        for(int i = 0; i<n; i++) {
            pre[i + 1] = pre[i] + (nums[i] % p == 0);
        }

        for(int i = 0; i<n; i++) {
            vector<int>curr;
            for(int j = i; j<n; j++) {
                if(pre[j+1] - pre[i] > k) break;
                curr.push_back(nums[j]);
            }
            if(!curr.empty())
                insert(curr, k, p);
        }

        return dfs(root);
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