#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int sz, n;
    set<string>hsh;
    string crackSafe(int n, int k) {
        sz = 1;
        this->n = n;
        for(int i = 0; i<n; i++)
            sz *= k;
        string str(n, '0');
        hsh.insert(str);
        solve(str, k);
        return str;
    }

    bool solve(string &str, int k) {
        if(hsh.size() == sz)
            return true;

        string lstDigits;
        for(int i = str.size() - n + 1; i<str.size(); i++) {
            lstDigits.push_back(str[i]);
        }
        for(char ch = '0'; ch < '0' + k; ch++) {
            string newStr = lstDigits + ch;
            if(!hsh.count(newStr)) {
                hsh.insert(newStr);
                str.push_back(ch);
                if(solve(str, k)) {
                    return true;
                }
                hsh.erase(newStr);
                str.pop_back();
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