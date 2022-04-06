#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    public:
    unsigned long long int countSub(int arr[], int n) {
        // Your code goes here
        // what is dp[i] denotes
        // dp[i] means number of increasing sequences ending at i
        
        vector<int>dp(n, 1);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(arr[i] > arr[j]) {
                    dp[i] += dp[j];
                }
            }
        }
        for(int i = 0; i<n; i++) {
            cout << dp[i] << ' ';   
        } cout << '\n';
        long long cnt = accumulate(arr, arr + n, 0LL);
        return cnt;
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
    int n; cin >> n;
    vector<int>arr(n, 0);
    
    return 0;
}