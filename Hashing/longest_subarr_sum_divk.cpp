#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int, int>hsh;
	    int ans = 0;
	    int curr = 0;
	    for(int i = 0; i<n; i++) {
	        curr += arr[i];
	        curr = ((curr % k) + k) % k;
	        if(curr == 0)
	            ans = max(ans, i + 1);
	        if(hsh.count(curr)) {
	            ans = max(ans, i - hsh[curr]);
	        } else hsh[curr] = i;
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