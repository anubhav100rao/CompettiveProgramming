#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int>row, col, diag, rdiag;
        unordered_map<int, unordered_set<int>>ls;
        for(vector<int>&lamp: lamps) {
            int r = lamp[0], c = lamp[1];
            if(!ls[r].count(c)) {
                ls[r].insert(c);
                row[r]++;
                col[c]++;
                diag[r-c]++;  // this r - c determines unique normal diagonal
                rdiag[r+c]++; // this r + c determines unique reverse diagonal
            }
        }
        vector<int>ans;
        for(vector<int>&query: queries) {
            int r = query[0], c = query[1];
            if(row[r] || col[c] || diag[r - c] || rdiag[r + c]) {
                ans.push_back(1);
                for(int i = r - 1; i <= r + 1; i++) {
                    for(int j = c - 1; j <= c + 1; j++) {
                        if(ls[i].count(j)) {
                            ls[i].erase(j);
                            row[i]--;
                            col[j]--;
                            diag[i - j]--;
                            rdiag[i + j]--;
                        }
                    }
                }
            } else {
                ans.push_back(0);
            }
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