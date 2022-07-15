#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution
{
    public:
    int isCircle(int n, vector<string> A)
    {
        // code here
        vector<int>in(26, 0), out(26, 0);
        vector<int>adj[26];
        for(int i = 0; i<n; i++) {
            adj[A[i][0] - 'a'].push_back(A[i].back() - 'a');
            out[A[i][0] - 'a']++;
            in[A[i].back() - 'a']++;
        }
        
        int extra_in = 0, extra_out = 0;
        
        for(int i = 0; i<26; i++) {
            if(in[i] != out[i]) return 0;
        }
        int src = 0;
        for(int i = 0; i<26; i++) {
            if(out[i] != 0) {
                src = i;
                break;
            }
        }
        
        vector<bool>visited(n, false);
        
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for(int child: adj[node]) {
                if(!visited[child]) {
                    dfs(child);
                }
            }
        };
        
        dfs(src);
        
        for(int i = 0; i<26; i++) {
            if(!visited[i] and out[i])
                return 0;
        }
        
        return 1;
        
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