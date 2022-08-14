#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl



int sumMinElements(vector<int>&arr) {

    int n = arr.size();
    vector<int>left(n, 0), right(n, 0);
    stack<pair<int, int>>st;

    for(int i = 0; i<n; i++) {
        int cnt = 1;
        while(!st.empty() and st.top().first > arr[i]) {
            cnt += st.top().second;
            st.pop();
        }

        st.push({arr[i], cnt});
        left[i] = cnt;
    }

    while(!st.empty())
        st.pop();
    
    for(int i = n - 1; i >= 0; i--) {
        int cnt = 1;
        while(!st.empty() and st.top().first >= arr[i]) {
            cnt += st.top().second;
            st.pop();
        }
        st.push({arr[i], cnt});
        right[i] = cnt;
    }

    int res = 0;
    for(int i = 0; i<n; i++)
        res += arr[i] * left[i] * right[i];

    return res;
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