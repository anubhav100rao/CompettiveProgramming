#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int get_histo_area(vector<int>&hist) {
    int n = hist.size();
    stack<int>st;

    int max_area = 0;

    int i = 0;
    while(i < n) {
        if(st.empty() || hist[st.top()] <= hist[i]) {
            st.push(i++);
        } else {
            int cur_top = st.top(); st.pop();
            int cur_area = hist[cur_top] * (st.empty() ? i: (i - st.top() - 1));
            if(cur_area > max_area) {
                max_area = cur_area;
            }
        }
    }

    while(!st.empty()) {
        int cur_top = st.top(); st.pop();
        int cur_area = hist[cur_top] * (st.empty() ? i: (i - st.top() - 1));
        if(cur_area > max_area)
            max_area = cur_area; 
    }

    return max_area;

}

int get_largest_rectangle(vector<vector<int>>&matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0));
    int ans = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(i == 0) dp[i][j] = matrix[i][j];
            else {
                if(matrix[i][j] == 1) {
                    dp[i][j] = dp[i-1][j] + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        ans = max(ans, get_histo_area(dp[i]));
    }
    return ans;
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