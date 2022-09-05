#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int getMax(int funds, vector<int>&price, vector<int>&profit, int k) {
    vector<pair<int, int>>arr;
    for(int i = 0; i < price.size(); i++)
        arr.push_back({price[i], profit[i]});
    int n = arr.size();
    sort(arr.begin(), arr.end());

    priority_queue<int>pq;

    int idx = 0;

    while(k--) {
        while(idx < n and arr[idx].first <= funds) {
            pq.push(arr[idx++].second);
        }
        if(!pq.empty()) {
            funds += pq.top();
            pq.pop();
        } else break;
    }

    return funds;
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