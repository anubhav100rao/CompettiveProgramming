#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        int start = 0, end = 0;
        int j = 0;
        for(int i = 0; i<n;) {
            start = intervals[i][0];
            end = intervals[i][1];
            j = i+1;
            while(j < n && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }
            i = j;
            ans.push_back({start, end});
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