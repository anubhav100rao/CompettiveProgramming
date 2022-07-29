#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<vector<int>>transitiveClosure(vector<vector<int>>&graph) {
    int n = graph.size();
    const int inf = 1e7 + 9;
    vector<vector<int>>res(n, vector<int>(n, inf));

    for(int i = 0; i<n; i++) {
        res[i][i] = 1;
        for(int j = 0; j<n; j++) {
            if(graph[i][j])
                res[i][j] = 1;
        }
    }

    for(int k = 0; k<n; k++) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(res[i][k] != inf and res[k][j] != inf and res[i][k] + res[k][j] < res[i][j]) {
                    res[i][j] = res[i][k] + res[k][j];
                }
            }
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(res[i][j] >= inf) res[i][j] = 0;
            else res[i][j] = 1;
        }
    }

    return res;
}

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