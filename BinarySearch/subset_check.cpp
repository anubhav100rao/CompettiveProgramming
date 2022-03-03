#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    for(int i = 0; i<m; i++) {
        if(!binary_search(a1, a1 + n, a2[i]))
            return "No";
    }
    return "Yes";
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