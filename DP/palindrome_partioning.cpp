#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

bool isPalindrome(string str, int i, int j) {
    while(i < j) {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palinPart(string str, int i, int j) {
    if(i >= j || isPalindrome(str, i, j)) return 0;
    int ans = INT_MAX, count = 0;
    for(int k = i; k<j; k++) {
        count = palinPart(str, i, k) + palinPart(str, k+1, j) + 1;
        ans = min(ans, count);
    }
    return ans;
}

int palinPartDp(string str) {
    int n = str.size();
    if(n == 1) return 0;
    vector<vector<bool>>P(n, vector<bool>(n, false));
    vector<vector<int>>C(n, vector<int>(n, 1e9));

    for(int i = 0; i<n; i++) {
        P[i][i] = true; // single len string is alwasys palindrome
        C[i][i] = 0; // no of partitions = 0 if string is already a palindrome
    }

    for(int l = 2; l<=n; l++) { // for string of len l
        for(int i = 0; i<n-l+1; i++) { // starting index
            int j = i + l - 1; // ending index
            if(l == 2) P[i][j] = (str[i] == str[j]);
            else P[i][j] = (str[i] == str[j] and P[i+1][j-1]);

            if(P[i][j]) C[i][j] = 0;
            else {
                for(int k = i; k<j; k++) { // trying to cut at (k = i, i+1, ... j-1) and taking minimum
                    C[i][j] = min(C[i][j], C[i][k] + C[k+1][j] + 1);
                }
            }
        }
    }
    return C[0][n-1];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    string str = "ababbbabbababa";
    cout << palinPart(str, 0, str.size() - 1) << '\n';
    cout << palinPartDp(str) << "\n";
    return 0;
}