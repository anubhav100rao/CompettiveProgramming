#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    using pii = pair<int, int>;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());   

        priority_queue<pii, vector<pii>, greater<pii>>pq;
        priority_queue<int, vector<int>, greater<int>>avail;
        map<int, int>fre;
        for(int i = 0; i < n; i++) {
            avail.push(i);
        }
        int ans = 0, mx = 0;
        
        for(auto &meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            int delay = 0;
            while(!pq.empty() and (pq.top().first <= start || avail.empty())) {
                auto top = pq.top(); pq.pop();
                delay = max(0, top.first - start);
                avail.push(top.second);
            }

            int top = avail.top(); avail.pop();
            pq.push({delay + end, top});
            int res = ++fre[top];
            if(mx <= res) {
                mx = res;
                ans = min(ans, top);
            }
        }

        return ans;
        
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