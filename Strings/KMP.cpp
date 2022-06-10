#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class KMP {
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

    vector<int>findAllIndexes(string &text, string &pattern) {
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