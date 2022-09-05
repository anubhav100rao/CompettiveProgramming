#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class KMP {
public:
    vector<int>constructLps(string &str) {

        int n = str.size();
        vector<int>lps(n, 0);
        int len = 0, j = 1;
        while(j < n) {
            if(str[len] == str[j]) {
                lps[j] = len + 1;
                len++;
                j++;
            } else {
                if(len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }

    vector<int>findAllIndexes(string &text, string &pattern) {

        // ABCAABCAABCACB
        // AABCAABC
        // lps = [0, 1, 0, 0, 1, 2, 3, 4]

        int n = text.size(), m = pattern.size();
        vector<int>lps = constructLps(pattern);
        vector<int>indexs;
        int i = 0, j = 0;
        while(i < n) {
            if(text[i] == pattern[j]) {
                if(j == m - 1) {
                    indexs.push_back(i - m + 1);
                    j = lps[j];
                } else {
                    i++;
                    j++;
                }
            } else {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    }

    bool findPattern(string &text, string &pattern) {
        int n = text.size(), m = pattern.size();
        vector<int>lps = constructLps(pattern);
        int i = 0, j = 0;
        while(i < n) {
            if(text[i] == pattern[j]) {
                if(j == m - 1) {
                    return true;
                } else {
                    i++;
                    j++;
                }
            } else {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
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