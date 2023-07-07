#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long maxPoints(vector<vector<int>>& points) {
	int n = points.size(), m = points[0].size();
	vector<vector<ll>>dp(n, vector<ll>(m, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			dp[i][j] = points[i][j];

	for(int i = 1; i < n; i++) {
		vector<ll>prefix = dp[i - 1], suffix = dp[i - 1];
		for(int i = 0; i < m; i++) {
			suffix[i] -= i;
			prefix[m - i - 1] -= i;
		}
		for(int i = 1; i < m; i++) prefix[i] = max(prefix[i], prefix[i - 1]);
		for(int i = m - 2; i >= 0; i--) suffix[i] = max(suffix[i], suffix[i + 1]);

		for(int j = 0; j < m; j++) {
			dp[i][j] += max(prefix[j] + m - j - 1, suffix[j] + j);
		}
	}  

	return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}
int main() {
	int tt; cin >> tt;
	while(tt--) {
		int n, m; cin >> n >> m;
		vector<vector<int>>points(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> points[i][j];
			}
		}

		cout << maxPoints(points) << '\n';
	}

}