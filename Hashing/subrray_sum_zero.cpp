#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        set<int>hsh = {0};
        long long curr = 0;
        for(int i = 0; i<n; i++) {
            curr += arr[i];
            if(hsh.count(curr))
                return true;
            hsh.insert(curr);
        }
        return false;
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