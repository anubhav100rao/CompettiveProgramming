#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int count_triplets(vector<int>&arr) {
    int n = arr.size();
    set<int>cubes;
    for(int i = 1; i<=500; i++) {
        cubes.insert(i * i * i);
    }

    int cnt = 0;
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            for(int k = j + 1; k<n; k++) {
                int sm = arr[i] + arr[j] + arr[k];
                if(cubes.count(sm))
                    cnt++;
            }
        }
    }
    return cnt;
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