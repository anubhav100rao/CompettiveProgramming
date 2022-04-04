#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct Job {
    int id;
    int dead;
    int profit; 
};

class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        sort(arr, arr + n, [&](const Job &a, const Job &b) {
            return a.profit > b.profit;
        });

        vector<bool>done(n, false);
        int cnt = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = min(n, arr[i].dead) - 1; j >=0; j--) {
                if(!done[j]) {
                    done[j] = true;
                    ans += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }

        return vector<int>{cnt, ans};

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