#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    public:
    // Function for finding maximum AND value.

    int moreOptimised(vector<int>&arr) {
        int n = arr.size();
        if(n <= 1) return 0;
        int res = 0;
        for(int i = 30; i>=0; i--) {
            int cnt = 0;
            int poss = res | (1 << i);
            for(int e: arr) if((e & poss) == poss) cnt++;
            if(cnt >= 2)
                res |= (1 << i);
        }
        return res;
    }


    int maxAND (int arr[], int n) {

        vector<int>a(arr, arr + n);
        return moreOptimised(a);

        if(n <= 1) return 0;
        vector<int>hsh;
        int ans = 0;
        for(int i = 0; i<n; i++)
            hsh.push_back(i);
        
        for(int i = 30; i>=0; i--) {
            int cnt = 0;
            for(int &idx: hsh) {
                if(arr[idx] & (1 << i))
                    cnt++;
            }
            if(cnt >= 2) {
                vector<int>ms;
                for(int &idx: hsh) {
                    if(arr[idx] & (1 << i)) {
                        ms.push_back(idx);
                    }
                }
                hsh = ms;
            }
        }
        return arr[hsh[0]] & arr[hsh[1]];
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