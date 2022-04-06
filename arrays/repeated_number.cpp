#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>repeatedNumber(const vector<int> &arr) {
    int n = arr.size();
    int xor_tot = 0;
    for(int i = 0; i<n; i++)
        xor_tot ^= arr[i];
    for(int i = 1; i<=n; i++)
        xor_tot ^= i;
    
    // now this xor_tot = a ^ b

    int set_bit = 0;

    for(int i = 0; i<31; i++) {
        if(xor_tot & (1 << i)) {
            set_bit = i;
            break;
        }
    }

    int a = 0, b = 0;

    for(int i: arr) {
        if(i & (1 << set_bit)) a ^= i;
        else b ^= i;
    }
    for(int i = 1; i<=n; i++) {
        if(i & (1 << set_bit)) a ^= i;
        else b ^= i;
    }
    int small = min(a, b);
    int big = max(a, b);

    long long sm = accumulate(arr.begin(), arr.end(), 0LL);
    long long tot = (n*(n + 1LL)) >> 1;
    if(sm > tot) {
        return vector<int>{big, small};
    } else {
        return vector<int>{small, big};
    }
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