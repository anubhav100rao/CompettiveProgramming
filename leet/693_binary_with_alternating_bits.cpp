#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int>bits;
        while(n) {
            if(n & 1) bits.push_back(1);
            else bits.push_back(0);
            n >>= 1;
        }        
        for(int i = 1; i<bits.size(); i++) 
            if(bits[i] == bits[i-1]) 
                return false;
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