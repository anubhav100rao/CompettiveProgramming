#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int>last_occcur;
        stack<char>st;
        unordered_set<char>visited;

        for(int i = 0; i<s.size(); i++)
            last_occcur[s[i]] = i;
        
        for(int i = 0; i<s.size(); i++) {
            if(!visited.count(s[i])) {
                while(!st.empty() and st.top() > s[i] and last_occcur[st.top()] > i) {
                    visited.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                visited.insert(s[i]);
            }
        }      

        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
        
    return 0;
}