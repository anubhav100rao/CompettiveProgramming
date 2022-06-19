#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int n;
    string str;
    vector<vector<int>>adj;
    vector<int>dp;
    vector<int>sub_max;
    vector<multiset<int>>pos;

    void dfs(int node) {
        dp[node] = 1;
        sub_max[node] = 1;
        for(int &child: adj[node]) {
            dfs(child);
            if(str[node] != str[child]) {
                sub_max[node] = max(sub_max[node], sub_max[child] + 1);
                pos[node].insert(sub_max[child]);
            }
        }
        
        if(pos[node].empty()) {

        } else if(pos[node].size() == 1) {
            dp[node] += *pos[node].rbegin();
        } else {
            dp[node] += *pos[node].rbegin();
            auto itr = pos[node].rbegin();
            pos[node].erase(pos[node].lower_bound(*itr));
            dp[node] += *pos[node].rbegin();
        }
    }

    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        adj = vector<vector<int>>(n);
        for(int i = 1; i<n; i++) {
            adj[parent[i]].push_back(i);
        }
        pos = vector<multiset<int>>(n);
        dp = vector<int>(n, 0);
        sub_max = dp;
        str = s;
        dfs(0);
        
        return *max_element(dp.begin(), dp.end());
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
    vector<int>parent = {
        -1,137,65,60,73,138,81,17,45,163,145,99,29,162,19,20,132,132,13,60,21,18,155,65,13,163,125,102,96,60,50,101,100,86,162,42,162,94,21,56,45,56,13,23,101,76,57,89,4,161,16,139,29,60,44,127,19,68,71,55,13,36,148,129,75,41,107,91,52,42,93,85,125,89,132,13,141,21,152,21,79,160,130,103,46,65,71,33,129,0,19,148,65,125,41,38,104,115,130,164,138,108,65,31,13,60,29,116,26,58,118,10,138,14,28,91,60,47,2,149,99,28,154,71,96,60,106,79,129,83,42,102,34,41,55,31,154,26,34,127,42,133,113,125,113,13,54,132,13,56,13,42,102,135,130,75,25,80,159,39,29,41,89,85,19
    };
    string str = "ajunvefrdrpgxltugqqrwisyfwwtldxjgaxsbbkhvuqeoigqssefoyngykgtthpzvsxgxrqedntvsjcpdnupvqtroxmbpsdwoswxfarnixkvcimzgvrevxnxtkkovwxcjmtgqrrsqyshxbfxptuvqrytctujnzzydhpal";
    Solution sol;
    cout << sol.longestPath(parent, str);
    return 0;
}