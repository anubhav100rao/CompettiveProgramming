#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

long long findPairs(int n, int m, vector<vector<int>> &response) {

	// Initialise a variable 'oddCount' to store the number of Ninjas with odd parity.
	    long long oddCount = 0;

	    // Initialise a variable 'evenCount' to store the number of Ninjas with even parity.
	    long long evenCount = 0;

	    // Run a for loop for 'i' = 0 to 'i' < 'n'.
        for (int i = 0; i < n; i++) {
            
            // Initialise a variable 'oneNum' to store the parity of answers given by 'i'th Ninja.
            int oneNum = 0;
            
            // Run a for loop for 'j' = 0 to 'j' < 'm'.
            for (int j = 0; j < m; j++) {
                
                // If 'response[i][j]' is 1, increment 'oneNum'.
                if (response[i][j] == 1) {
                    oneNum++;
                }
            }

            // If 'oneNum' is even, increment 'evenCount'.
            if (oneNum % 2 == 0) {
                evenCount++;
            }
            
            // Else, increment 'oddCount'.
            else {
				oddCount++;
			}
        }
    
    // Return 'oddCount * evenCount'.
    return oddCount * evenCount;
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