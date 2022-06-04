#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {

public:
    const int N = 1e6 + 10;
    const int mod = 1e9 + 7;
    vector<bool>isPrime;
    vector<long long>pre;
    void precompute()
    {
        isPrime = vector<bool>(2*N, true);
        isPrime[0] = isPrime[1] = false;
        for(long long i = 2; i<N; i++) {
            if(isPrime[i]) {
                for(long long j = i * i; j<N; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        pre = vector<long long>(N, 0);
        pre[2] = 2;
        for(int i = 3; i<N; i++) {
            pre[i] = pre[i-1];
            if(isPrime[i]) {
                pre[i] *= i;
                pre[i] %= mod;
            }
        }
    }
    long long primorial(long long n){
        return pre[n];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Solution sol;
    sol.precompute();
    cout << sol.primorial(5) << "\n";
    return 0;
}