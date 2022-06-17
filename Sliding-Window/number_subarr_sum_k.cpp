#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int>pre = {{0, 0}};
        int s = 0;
        for(int &i: arr) {
            s += i;
            pre[i]++;
        }
        int ans = 0;
        s = 0;
        for(int &i: arr) {
            s += i;
            if(pre.count(s - k))
                ans += pre[s - k];
        }
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