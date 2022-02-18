#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    map<char, string>hsh = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string>res;

    void solve(string &digits, int index, string &curr) {
        if(index == digits.size()) {
            res.push_back(curr);
            return;
        }
        for(char ch: hsh[digits[index]]) {
            curr.push_back(ch);
            solve(digits, index+1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string curr = "";
        solve(digits, 0, curr);
        return res;
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