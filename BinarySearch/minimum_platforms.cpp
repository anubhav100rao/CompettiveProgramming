#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
    public:
    
    int good(int arr[], int dep[], int n) {
        vector<pair<int, int>>s;
        for(int i = 0; i<n; i++) {
            s.push_back({arr[i], -1});
            s.push_back({dep[i], 1});
        }
        sort(s.begin(), s.end());
        int res = 0;
        int ans = 0;
        for(int i = 0; i<2*n; i++) {
            if(s[i].second == -1) {
                res++;
            } else {
                res--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
    
    int findPlatform(int arr[], int dep[], int n) {
    	return good(arr, dep, n);
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