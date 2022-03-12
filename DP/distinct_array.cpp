#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
	int n; cin >> n;
	vector<int>arr(n, 0);
	for(int &i: arr) cin >> i;
	if(n <= 2) {
		cout << n << '\n';
		return;
	}
	vector<int>dp(n+1, 0);
	dp[1] = 1; dp[2] = 2;
	for(int i = 3; i<=n; i++) {
		dp[i] = (dp[i-1] + ((i - 1) * (dp[i-2]) % mod)) % mod;
	}
	cout << dp[n] << '\n';
}

signed main() {
	int tt; cin >> tt;
	while(tt--) solve();
	return 0;
}