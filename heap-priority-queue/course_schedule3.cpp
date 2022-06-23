#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](const auto &a, const auto &b) {
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        
        
        priority_queue<pair<int, int>>pq;
        int time = 0;
        int cnt = 0;
        for(int i = 0; i<courses.size(); i++) {
            if(time + courses[i][0] <= courses[i][1]) {
                cnt++;
                time += courses[i][0];
                pq.push({courses[i][0], courses[i][1]});
            } else {
                if(!pq.empty()) {
                    auto [a, b] = pq.top();
                    // pq.pop();
                    if(a > courses[i][0]) {
                        pq.pop();
                        pq.push({courses[i][0], courses[i][1]});
                        time -= (a - courses[i][0]);
                    }
                }
            }
        }

        return cnt;
        
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