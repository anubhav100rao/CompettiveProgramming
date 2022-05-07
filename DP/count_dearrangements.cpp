#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int countDerragements(int n) {
    if(n <= 1)
        return 0;
    if(n == 2)
        return 1;
    return (n - 1) * (countDerragements(n - 1) + countDerragements(n - 2));
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