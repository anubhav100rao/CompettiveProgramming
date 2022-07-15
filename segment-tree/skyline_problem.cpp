#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// Skyline Problem
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> res;
        vector<int> curr;
        int n = buildings.size();
        if(n == 0) return res;
        
        vector<int> heights(n, 0);
        for(int i = 0; i<n; i++) {
            heights[i] = buildings[i][2];
        }
        
        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());
        
        vector<int> left(n, 0), right(n, 0);
        for(int i = 1; i<n; i++) {
            if(buildings[i][2] > buildings[i-1][2]) {
                left[i] = left[i-1] + 1;
            }
        }  
        
        for(int i = n-2; i>=0; i--) {
            if(buildings[i][2] > buildings[i+1][2]) {
                right[i] = right[i + 1] + 1;
            }
        }
        
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += max(left[i], right[i]);
        
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