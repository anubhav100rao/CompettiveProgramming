#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

long long int floorSqrt(long long int x) 
{
    // Your code goes here 
    long long l = 1LL, r = x, res = x;
    while(r - l >= 0) {
        long long mid = l + (r - l) / 2;
        if(mid * mid <= x) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

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