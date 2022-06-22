#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    unordered_set<string>visited;
    unordered_map<string, vector<string>>adj;

    void dfs(string &node, vector<string>&mergedAccount) {
        mergedAccount.push_back(node);
        visited.insert(node);
        for(string &child: adj[node]) {
            if(!visited.count(child)) {
                dfs(child, mergedAccount);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for(vector<string>&account: accounts) {
            int ac = account.size();
            string firstEmail = account[1];
            for(int j = 2; j<ac; j++) {
                adj[firstEmail].push_back(account[j]);
                adj[account[j]].push_back(firstEmail);
            }
        }    
        vector<vector<string>>mergedAccounts;
        for(vector<string>&account: accounts) {
            string accountName = account[0];
            string firstEmail = account[1];
            if(visited.count(firstEmail)) continue;
            vector<string>mergedAccount;
            mergedAccount.push_back(accountName);
            dfs(firstEmail, mergedAccount);
            sort(mergedAccount.begin() + 1, mergedAccount.end());
            mergedAccounts.push_back(mergedAccount);
        }

        return mergedAccounts;
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