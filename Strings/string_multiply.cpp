#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<vector<int>>res(405, vector<int>(405, 0));  
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i<m; i++) {
            int cursor = i;
            int carry = 0;
            int a = num2[i] - '0';
            for(int j = 0; j<n; j++) {
                int b = num1[j] - '0';
                int mul = a * b;
                mul += carry;
                res[i][cursor++] = mul % 10;
                carry = mul / 10;
            }
            res[i][cursor] = carry;
        }
        string ans = "";

        vector<int>f;
        int carry = 0;
        for(int i = 0; i<405; i++) {
            int sm = 0;
            for(int j = 0; j<405; j++) {
                sm += res[j][i];
            }
            sm += carry;
            carry = sm / 10;
            f.push_back(sm % 10);
        }
        f.push_back(carry);
        

        reverse(f.begin(), f.end());

        int itr = 0;
        while(itr < f.size() and f[itr] == 0) itr++;

        for(int i = itr; i<f.size(); i++) ans += to_string(f[i]);
        if(ans.size())
            return ans;
        return "0";
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