#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    vector<int>prev_min(vector<int>&arr) {
        int n = arr.size();
        vector<int>left(n, -1);
        stack<int>st;
        for(int i = 0; i<n; i++) {
            while(!st.empty() and arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        return left;
    }

    vector<int>next_min(vector<int>&arr) {
        int n = arr.size();
        vector<int>right(n, n);
        stack<int>st;
        for(int i = 0; i<n; i++) {
            while(!st.empty() and arr[st.top()] >= arr[i]) {
                int x = st.top();
                st.pop();
                right[x] = i;
            }
            st.push(i);
        }
        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>ple = prev_min(heights);
        vector<int>nle = next_min(heights);
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, (nle[i] - ple[i] - 1) * heights[i]);
        }
        return ans;
    }
};


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