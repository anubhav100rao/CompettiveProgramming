#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end());
        int start = 0, end = 0;
        int n = points.size();
        for(int i = 0; i<n; ) {
            start = points[i][0], end = points[i][1];
            int j = i + 1;
            while(j < n and points[j][0] <= end) {
                start = max(start, points[j][0]);
                end = min(end, points[j][1]);
                j++;
            }
            i = j;
            res++;
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