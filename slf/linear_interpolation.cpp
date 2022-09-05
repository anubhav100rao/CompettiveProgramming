#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

double solve(int x1, double y1, int x2, double y2, int x) {
    return ((y2 - y1) / (x2 - x1)) * (x - x1) + y2;
}

string interpolate(int x, vector<int>&X, vector<double>&Y) {
    
    int sz = X.size();
    auto pos = lower_bound(X.begin(), X.end(), x);
    

    if(pos == X.end()) {
        return to_string(solve(X[sz - 1], Y[sz - 1], X[sz - 2], Y[sz - 2], x));
    }

    if(*pos == x) {
        return to_string(Y[pos - X.begin()]);
    }

    if(pos == X.begin()) {
        return to_string(solve(X[0], Y[0], X[1], Y[1], x));
    }

    int idx = pos - X.begin();

    return to_string(solve(X[idx], Y[idx], X[idx - 1], Y[idx - 1], x));
    
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