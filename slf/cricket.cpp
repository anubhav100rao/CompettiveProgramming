#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

#define int long long

int N;
vector<vector<int>>dp;

vector<int>runs = {1, 2, 6};

int solve(int curr_runs, bool isFour) {
    if(curr_runs >= N)
        return curr_runs == N;
    
    int &ans=dp[curr_runs][isFour];
    
    if(ans != -1)
        return ans;

    ans = 0;

    for(int run: runs)
        ans += solve(curr_runs + run, false);

    if(!isFour)
        ans += solve(curr_runs + 4, true);

    return ans;

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