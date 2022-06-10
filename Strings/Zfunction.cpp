#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class ZPatternMatching {
public:
    vector<int>constructZArray(string &str) {
        // z[i] represents the length of the longest proper prefix of str[0..i] that is also a suffix
        // of str[0..i] and suffix will start from i
        int n = str.size();
        vector<int>z(n, 0);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i > r) {
                l = r = i;
                while(r < n && str[r - l] == str[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            } else {
                int k = i - l;
                if(z[k] < r - i + 1) {
                    z[i] = z[k];
                } else {
                    l = i;
                    while(r < n && str[r - l] == str[r]) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    vector<int>findAllIndexes(string &text, string &pattern) {
        string z_string = pattern + "#" + text;
        vector<int>z = constructZArray(z_string);
        vector<int>indexs;
        int n = text.size(), m = pattern.size();
        for(int i = 0; i < n; i++) {
            if(z[i] == m) {
                indexs.push_back(i - m + 1);
            }
        }
        return indexs;
    }

    bool findPattern(string &text, string &pattern) {
        string z_string = pattern + "#" + text;
        vector<int>z = constructZArray(z_string);
        int n = text.size(), m = pattern.size();
        for(int i = 0; i < n; i++) {
            if(z[i] == m) {
                return true;
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