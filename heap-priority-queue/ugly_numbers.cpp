#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


int ugly(vector<int>&primes, int n) {
    priority_queue<int, vector<int>, greater<int>>pq;
    
    for(int i: primes)
        pq.push(i);
    
    int count = 1, curr = 1;

    while(count < n) {
        curr = pq.top();
        pq.pop();
        if(curr != pq.top()) {
            count++;
            for(int i: primes) {
                pq.push(curr * i);
            }
        }
    }
    return curr;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int>primes(n, 0);
    for(int &i: primes) cin >> i;
    
    cout << ugly(primes, m);
    return 0;
}