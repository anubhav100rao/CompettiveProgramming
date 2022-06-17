#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// Type1: minimize k such that f(k) is true
// false false false  ..... false true true true ..... true
// which is also true for reverse of this

int binary_search(vector<int>&arr, function<bool(int)>&good) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(good(mid)) right = mid;
        else left = mid + 1;
    }
    return left;
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