#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    void permute(vector<vector<int>>&ans, int N, vector<int>&arr, map<int, int>&hsh) {
        if(arr.size() == N) {
            ans.push_back(arr);
        } else {
            for(pair<const int, int>&pii: hsh) {
                int num = pii.first;
                int count = pii.second;
                if(count == 0) continue;
                hsh[num]--;
                arr.push_back(num);
                permute(ans, N, arr, hsh);
                hsh[num]++;
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        map<int, int>hsh;
        for(int &num: nums) hsh[num]++;
        permute(ans, nums.size(), arr, hsh);
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