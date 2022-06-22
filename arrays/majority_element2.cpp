#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, can1 = 0, can2 = 0;

        int n = nums.size();

        auto good = [&](const int x) {
            int cnt = 0;
            for(int &i: nums)
                cnt += (i == x);
            return cnt > n / 3;
        };

        for(int i: nums) {
            if(i == can1) {
                cnt1++;
            } else if(i == can2) {
                cnt2++;
            } else if(cnt1 == 0) {
                can1 = i, cnt1 = 1;
            } else if(cnt2 == 0) {
                can2 = i, cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int>res;
        if(good(can1)) res.push_back(can1);
        if(good(can2) and can1 != can2) res.push_back(can2);

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