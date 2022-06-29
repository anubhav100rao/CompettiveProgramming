#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        vector<int>fre(n + 1, 0);    
        for(int i = n-1; i>=0; i--)
            fre[i] = fre[i + 1] + (s[i] == letter);
        stack<char>st;
        int extra = k - repetition;
        for(int i = 0; i<n; i++) {
            
        }
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