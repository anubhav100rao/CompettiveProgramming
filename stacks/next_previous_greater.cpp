#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>nextGreater(vector<int>&arr) {
    stack<int>s;
    int n = arr.size();
    vector<int>nbe(n, -1);
    for(int i = 0; i<n; i++) {
        while(!s.empty() and arr[s.top()] < arr[i]) {
            int x = s.top();
            nbe[x] = i;
            s.pop();
        }
        s.push(i);
    }

    return nbe;
}

vector<int>previousMax(vector<int>&arr) {
    stack<int>s;
    int n = arr.size();
    vector<int>pbe(n, -1);
    for(int i = 0; i<n; i++) {
        while(!s.empty() and arr[s.top()] < arr[i]) {
            s.pop();
        }
        if(!s.empty())
            pbe[i] = s.top();
        s.push(i);
    }

    return pbe;
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