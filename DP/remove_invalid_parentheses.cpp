#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    set<string>res;

    set<int>visited;

    bool check(string &str) {
        int curr = 0;
        for(char &ch: str) {
            if(curr < 0) return false;
            if(ch == '(') curr++;
            else if(ch == ')') {
                curr--;
            }
        }
        return curr == 0;
    }

    void solve(int idx, string &str, string running, int remain, int hash) {
        if(idx >= str.size()) {
            if(remain == 0 and check(running)) {
                res.insert(running);
            }
            return;
        }

        if(visited.count(hash)) return;

        if(str[idx] == '(') {
            
        }

        visited.insert(hash);

    }

    vector<string> removeInvalidParentheses(string s) {
        int cnt = 0;
        stack<char>st;
        for(char ch: s) {
            if(ch == '(') {
                st.push('(');
            } else if(ch == ')') {
                if(st.empty()) {
                    cnt++;
                } else {
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            cnt++;
            st.pop();
        }

        cout << cnt << "\n";

        solve(0, s, "", cnt, 0);

        return vector<string>(res.begin(), res.end());
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