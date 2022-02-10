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