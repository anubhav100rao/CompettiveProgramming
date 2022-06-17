#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution { // this is travelling salesman problem
public:
    const int MIN = -1e9;
    const int MAX = 1e9;
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>graph(1 << n, vector<int>(n, 0));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int len = min(words[i].size(), words[j].size());    
                int k = 0;
                while(k < len) {
                    if(words[i][(int)words[i].size() - 1 - k] == words[j][k]) {
                        k++;
                    } else break;
                }
                graph[i][j] = k;
                
            }
        }
        vector<vector<int>>dp(1 << n, vector<int>(n, 0));
        vector<vector<int>>path(1 << n, vector<int>(n, 0));
        int last = -1, min = MAX;
        
        for(int i = 0; i<(1 << n); i++) {
            // dp[i] = vector<int>(n, MAX);
            for(int j = 0; j<n; j++) {
                if((i & (1 << j))) {
                    int prev = i - (1 << j);
                    if(prev == 0) continue;
                    for(int k = 0; k<n; k++) {
                        if(prev & (1 << k)) {
                            
                        }
                    }
                }
                if(i == (1 << n) - 1) {
                    if(dp[i][j] < min) {
                        min = dp[i][j];
                        last = j;
                    }
                }
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cout << graph[i][j] << " ";
            } cout << "\n";
        }
        cout << last << " " << min << "\n";
        for(int i = 0; i<(1 << n); i++) {
            for(int j = 0; j<n; j++) {
                cout << dp[i][j] << " ";
            } cout << "\n";
        }

        return "";
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
    vector<string>arr = {"catg","ctaagt","gcta","ttca","atgcatc"};
    Solution sol;
    cout << sol.shortestSuperstring(arr);
    return 0;
}