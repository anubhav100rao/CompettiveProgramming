#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    // Code here
    const int inf = 1e8;
    vector<int>dist(n, inf);
    dist[0] = 0;
    bool flag = false;
    for(int i = 0; i<n; i++) {
        flag = false;
        for(vector<int>&edge: edges) {
            if(dist[edge[0]] != inf and dist[edge[0]] + edge[2] < dist[edge[1]]) {
                dist[edge[1]] = dist[edge[0]] + edge[2];
                flag = true;
            }
        }
    }
    return flag;
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