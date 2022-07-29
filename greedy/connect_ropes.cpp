#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>>q;
        for(int i = 0; i<n; i++)
            q.push(arr[i]);
        ll ans = 0;
        while(q.size() > 1) {
            ll f = q.top(); q.pop();
            ll s = q.top(); q.pop();
            ans += f + s;
            q.push(f + s);
        }
        return ans;
    }
};



int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}