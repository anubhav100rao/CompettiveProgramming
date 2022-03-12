#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int offerings(vector<int>&arr) {
        int n = arr.size();
        vector<int>A(n, 1), B(n, 1);
        for(int i = 1; i<n; i++)
            if(arr[i] > arr[i-1])
                A[i] = A[i-1] + 1;
        
        for(int i = n-2; i>=0; i--)
            if(arr[i] > arr[i+1])
                B[i] = B[i+1] + 1;
        
        int ans = 0;
        for(int i = 0; i<n; i++)
            ans += max(A[i], B[i]);
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