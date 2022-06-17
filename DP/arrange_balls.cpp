#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
	public:
    
    int dp[101][101][101][3];

    int countWays(int p, int q, int r, int last) {
        if (p<0 || q<0 || r<0)
        return 0;
 
    // If last ball required is of type P and the number
    // of balls of P type is 1 while number of balls of
    // other color is 0 the number of ways is 1.
    if (p==1 && q==0 && r==0 && last==0)
        return 1;
 
    // Same case as above for 'q' and 'r'
    if (p==0 && q==1 && r==0 && last==1)
        return 1;
    if (p==0 && q==0 && r==1 && last==2)
        return 1;
 
    // If this subproblem is already evaluated
    if (dp[p][q][r][last] != -1)
        return dp[p][q][r][last];
 
    // if last ball required is P and the number of ways is
    // the sum of number of ways to form sequence with 'p-1' P
    // balls, q Q Balls and r R balls ending with Q and R.
    if (last==0)
       dp[p][q][r][last] = countWays(p-1,q,r,1) + countWays(p-1,q,r,2);
 
    // Same as above case for 'q' and 'r'
    else if (last==1)
       dp[p][q][r][last] = countWays(p,q-1,r,0) + countWays(p,q-1,r,2);
    else //(last==2)
       dp[p][q][r][last] =  countWays(p,q,r-1,0) + countWays(p,q,r-1,1);
 
    return dp[p][q][r][last];
    }

	int CountWays(int p, int q, int r) {
	    // Code here
	    if(p > q + r + 1) return 0;
	    if(q > p + r + 1) return 0;
	    if(r > p + q + 1) return 0;

        memset(dp, -1, sizeof dp);    

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