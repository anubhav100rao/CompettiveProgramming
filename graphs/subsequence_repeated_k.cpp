#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    map<char, int>fre;

    bool good(string &s, string &str, int k) {
        int i = 0, j = 0, cnt = 0;
        while(i < str.size()) {
            if(s[j] == str[i]) {
                i++;
                j++;
            } else {
                i++;
            }
            if(j == s.size()) cnt++, j = 0;
        }
        return cnt >= k;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        for(char &ch: s)
            fre[ch]++;
        
        queue<string>q;
        for(auto &[a, b]: fre)
            if(b >= k) {
                string p = string(1, a);
                q.push(p);
            }

        string ans = "";    
        
        while(!q.empty()) {
            string curr = q.front(); q.pop();
            if(curr.size() >= ans.size()) ans = curr;
            for(char ch = 'a'; ch <= 'z'; ch++) {
                curr.push_back(ch);
                if(good(curr, s, k)) q.push(curr);
                curr.pop_back();
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