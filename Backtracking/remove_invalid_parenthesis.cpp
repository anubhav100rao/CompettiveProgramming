#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:

    bool good(string &str) {
        int cnt = 0;
        for(char c: str) {
            if(c == '(') cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }

    set<string>res;

    void solve(string &s, int idx, int cnt, string running) {
        if(idx >= s.size()) {
            if(good(running))
                res.insert(running);
            return;
        }
        running.push_back(s[idx]);
        solve(s, idx + 1, cnt, running);
        running.pop_back();
        if(cnt > 0)
            solve(s, idx + 1, cnt - 1, running);
    }

    vector<string> removeInvalidParentheses(string s) {
        stack<char>st;
        int cnt = 0;
        for(char ch: s) {
            if(ch == '(') st.push(ch);
            else if(ch == ')') {
                if(st.empty() || st.top() == ')') cnt++;
                else st.pop();
            }
        }
        cnt += st.size();

        cout << cnt << "\n";

        solve(s, 0, cnt, "");

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