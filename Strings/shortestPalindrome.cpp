#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:

    vector<int>constructLps(string &str) {
        int n = str.size();
        vector<int>lps(n, 0);
        int i = 0, j = 1;
        while(j < n) {
            if(str[i] == str[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if(i != 0) {
                    i = lps[i - 1];
                } else {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }


    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + "#" + rev;
        vector<int>lps = constructLps(str);
        string toAdd = s.substr(lps.back());
        reverse(toAdd.begin(), toAdd.end());
        return toAdd + s;
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