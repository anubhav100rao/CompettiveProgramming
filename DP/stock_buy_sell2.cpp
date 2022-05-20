#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

int solve(vector<int>&arr) {
    int n = arr.size();
    vector<int>f(n, 0), s(n, 0);
    int curr = 0, mn = INT_MAX;
    for(int i = 0; i<n; i++) {
        mn = min(mn, arr[i]);
        curr = max(curr, arr[i] - mn);
        f[i] = curr;
    }

    mn = INT_MIN;
    curr = 0;

    for(int i = n - 1; i>=0; i--) {
        mn = max(mn, arr[i]);
        curr = max(curr, mn - arr[i]);
        s[i] = curr;
    }
    int ans = 0;
    for(int i = 0; i<n-1; i++) {
        ans = max(ans, f[i] + s[i+1]);
    }

    ans = max(ans, f[n-1]);
    return ans;
}

int sol(vector<int>&arr) {
    int n = arr.size();

    int first_buy = INT_MIN, second_buy = INT_MIN;
    int first_sell = 0, second_sell = 0;

    for(int i = 0; i<n; i++) {
        first_buy = max(first_buy, -arr[i]);
        first_sell = max(first_sell, first_buy + arr[i]);
        second_buy = max(second_buy, first_sell - arr[i]);
        second_sell = max(second_sell, second_buy + arr[i]);

        cout << first_buy << " " << first_sell << " " << second_buy << " " << second_sell << "\n";
    }
    return second_sell;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    vector<int>shares = {10, 22, 5, 75, 65, 80};
    int n = shares.size();

    int ans = 0;
    for(int i = 0; i<n; i++) {
        int curr1 = 0, mn = INT_MAX;
        for(int j = 0; j<=i; j++) {
            mn = min(mn, shares[j]);
            curr1 = max(curr1, shares[j] - mn);
        }
        int curr2 = 0;
        mn = INT_MAX;
        for(int j = i+1; j<n; j++) {
            mn = min(mn, shares[j]);
            curr2 = max(curr2, shares[j] - mn);
        }

        ans = max(ans, curr1 + curr2);
    }

    cout << ans << " " << solve(shares) << "\n";

    cout << sol(shares) << "\n";

    return 0;
}