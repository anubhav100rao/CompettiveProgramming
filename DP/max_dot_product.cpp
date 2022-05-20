#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// maximum dot product achievable by inserting zeroes

int solve(vector<int>&arr, vector<int>&brr, int idx1, int idx2) {
    if(idx2 == brr.size())
        return 0;
    if(idx1 == arr.size())
        return INT_MIN;

    return max(
            arr[idx1] * brr[idx2] + solve(arr, brr, idx1 + 1, idx2 + 1),
            solve(arr, brr, idx1 + 1, idx2) 
        );
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