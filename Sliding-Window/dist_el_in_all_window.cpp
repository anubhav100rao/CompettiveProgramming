#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
  public:
    vector <int> countDistinct (vector<int>&arr, int n, int k) {
        map<int, int>fre;
        set<int>hsh;
        vector<int>res;
        int start = 0;
        if(k == 1)
            return vector<int>(n, 1);
        for(int i = 0; i<n; i++) {
            fre[arr[i]]++;
            hsh.insert(arr[i]);
            if(i - start + 1 == k) {
                int el = arr[start];
                res.push_back(hsh.size());
                fre[el]--;
                if(fre[el] == 0) {
                    hsh.erase(el);
                }
                start++;
            }
        }
        return res;
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
    Solution sol;
    int n, k; cin >> n >> k;
    vector<int>arr(n, 0);
    for(int &i: arr)
        cin >> i;
    
    vector<int>res = sol.countDistinct(arr, n, k);
    for(int i: res) cout << i << ' '; cout << '\n';
    return 0;
}