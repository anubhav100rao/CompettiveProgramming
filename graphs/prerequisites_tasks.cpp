#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(N);
	    vector<int>in(N, 0);
	    for(auto p: prerequisites) {
	        int a = p.first, b = p.second;
	        adj[b].push_back(a);
	        in[a]++;
	    }
	    
	    queue<int>q;
	    for(int i = 0; i<N; i++) {
	        if(in[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    int cnt = 0;
	    
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        cnt++;
	        for(int &child: adj[node]) {
	            in[child]--;
	            if(in[child] == 0) q.push(child);
	        }
	    }
	    
	    return cnt == N;
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