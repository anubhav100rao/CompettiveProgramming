#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size() % 2) return false;
        map<int, int>fre;
        for(int i: nums) {
            fre[((i % k) + k) % k]++;
        }
        int cnt = 0;
        for(int i: nums) {
            int rem = ((i % k) + k) % k;
            if(rem == k / 2 and !(k & 1)) {
                if(fre[rem] & 1)
                    return false;
            }
            else if(rem == 0) {
                if(fre[rem] & 1)
                    return false;
            } else {
                if(fre[rem] != fre[k - rem])
                    return false;
            }
        }
        return true;
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