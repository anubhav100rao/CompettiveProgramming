#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    const int inf = 1e9 + 7;
	    vector<int>dist(n, inf);
	    sort(edges.begin(), edges.end(), [&](const auto a, const auto b) {
	        return a[2] < b[2]; 
	    });
	    int done = 0;
	    dist[0] = 0;
	    for(int i = 0; i<n; i++) {
            done = 0;
	        for(auto edge: edges) {
	            int from = edge[0], to = edge[1], wt = edge[2];
	            if(dist[from] != inf and dist[to] > dist[from] + wt) {
	                dist[to] = dist[from] + wt;
	                done = 1;
	            }
    	    }
	    }
	    return done;
	    
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