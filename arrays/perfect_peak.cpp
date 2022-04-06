#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


int perfectPeak(vector<int> &arr) {
    int n = arr.size();
    vector<int>pre(n, 0), post(n, 0);
    pre[0] = arr[0]; post[n-1] = arr[n-1];
    for(int i = 1; i<n; i++)
        pre[i] = max(pre[i-1], arr[i]);
    for(int i = n-2; i>=0; i--)
        post[i] = min(post[i+1], arr[i]);
    
    for(int i = 1; i<n-1; i++) {
        if(arr[i] > pre[i-1] and arr[i] < post[i+1])
            return 1;
    }
    return 0;
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