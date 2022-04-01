#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int solve(vector<int>&arr);
    int repeatedNumber(const vector<int> &V);
};
int Solution::solve(vector<int> &arr) {
    using ll = long long;
    int n = arr.size();
    vector<pair<int, int>>pre(n), suf(n);
    pre[0] = {arr[0], 0};
    if(n & 1) {
        suf[n-1] = { arr[n-1], 0 };
    } else {
        suf[n-1] = { 0, arr[n-1] };
    }

    for(int i = 1; i<n; i++) {
        pre[i] = pre[i-1];
        if(i & 1) {
            pre[i].second += arr[i];
        } else {
            pre[i].first += arr[i];
        }
    }
    for(int i = n-2; i>=0; i--) {
        suf[i] = suf[i+1];
        if(i & 1) {
            suf[i].second += arr[i];
        } else {
            suf[i].first += arr[i];
        }
    }

    int cnt = 0;
    if(n == 1)
        return 1;
    for(int i = 0; i<n; i++) {
        if(i == 0) {
            if(suf[i+1].first == suf[i+1].second)
                cnt++;
        } else if(i == n-1) {
            if(pre[n-2].first == pre[n-2].second)
                cnt++;
        } else {
            int odd = pre[i-1].first + suf[i+1].second;
            int even = pre[i-1].second + suf[i+1].first;
            if(odd == even)
                cnt++;
        }
        
    }
    return cnt;
    
}


int Solution::repeatedNumber(const vector<int> &V) {
    if (V.size() <= 1) return -1;
    int valueRange = V.size() - 1; // 1 to N when the size is N+1.
    int range = sqrt(valueRange);
    if (range * range < valueRange) range++;
    int count[range + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < V.size(); i++) {
    count[(V[i] - 1) / range]++;
    }

    int repeatingRange = -1;
    int numRanges = ((valueRange - 1) / range) + 1;
    for (int i = 0; i < numRanges && repeatingRange == -1; i++) {
        if (i < numRanges - 1 || valueRange % range == 0) {
            if (count[i] > range) repeatingRange = i;
        } else {
            if (count[i] > valueRange % range) repeatingRange = i;
        }
    }
    if (repeatingRange == -1) return -1;
    memset(count, 0, sizeof(count));
    for (int i = 0; i < V.size(); i++) {
        if ((V[i] - 1) / range == repeatingRange) count[(V[i] - 1) % range]++;
    }
    for (int i = 0; i < range; i++) {
        if (count[i] > 1) {
            return repeatingRange * range + i + 1;
        }
    }
    return -1;
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