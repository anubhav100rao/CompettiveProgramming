#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>>adj;
        map<string, int>in, out;


        for(int i = 0; i<equations.size(); i++) {
            string start = equations[i][0], end = equations[i][1];
            out[start]++;
            in[end]++;
            adj[start].push_back({end, values[i]});
            adj[end].push_back({start, (1.00000) / (values[i])});
        }

        auto bfs = [&](const string &start, const string &end) {

            if(!adj.count(start) || !adj.count(end)) return -1.0000000;

            queue<pair<string, double>>q;
            q.push({start, 1.00000});

            map<string, double>dist;
            dist[start] = 1.0000000;
            while(!q.empty()) {
                auto top = q.front(); q.pop();
                
                string node = top.first; double node_dist = top.second;

                for(auto [child, child_dist]: adj[node]) {
                    if(dist.count(child)) continue;
                    dist[child] = child_dist * node_dist;
                    q.push({child, dist[child]});
                }
            }

            if(!dist.count(end)) return -1.0000000;
            return dist[end];
        };

        vector<double>res;

        for(auto query: queries) {
            res.push_back(bfs(query[0], query[1]));
        }

        return res;

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