#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int solve_base(vector<int>&arr) {
    set<int>seen;
    int cnt = 0;
    for(int &i: arr) {
        if(!seen.count(i - 1))
            cnt++;
        seen.insert(i);
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
    int n, m; cin >> n >> m;
    vector<int>arr(n, 0);

    map<int, int>pos = {{0, -1}, {n + 1, n}};
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int ans = solve_base(arr);

    
    

    while(m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        
        if(abs(arr[a] - arr[b]) == 1) {

            if(arr[a] > arr[b]) {
                ans--;
                int right = pos[arr[a] + 1];
                if(a < right and right < b) {
                    ans++;
                }

                int left = pos[arr[b] - 1];
                if(a < left and left < b) {
                    ans++;
                }
            }
            else {
                ans++;
                int left = pos[arr[a] - 1];
                if(a < left and left < b) {
                    ans--;
                }

                int right = pos[arr[b] + 1];
                if(a < right and right < b) {
                    ans--;
                }
            }



        } else {

            int left = pos[arr[a] - 1], right = pos[arr[a] + 1];
            if(a < left and left < b) {
                ans--;
            }

            if(a < right and right < b) {
                ans++;
            }

            left = pos[arr[b] - 1], right = pos[arr[b] + 1];

            if(a < left and left < b) ans++;
            if(a < right and right < b) ans--;

        }

        pos[arr[a]] = b;
        pos[arr[b]] = a;
        swap(arr[a], arr[b]);

        cout << ans << '\n';

    }
    

    return 0;
}