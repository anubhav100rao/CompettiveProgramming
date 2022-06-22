#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int so_far = 0;
        int i = 0;
        while(i < coins.size()) {
            int next = so_far + 1;
            if(so_far + coins[i] >= next and coins[i] <= next) {
                so_far += coins[i++];
            } else break;
        }         
        return so_far + 1;
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