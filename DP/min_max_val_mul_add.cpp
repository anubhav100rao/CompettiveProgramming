#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// given expression like 2+5*9+1*2*9
// we have to find min and maximum value of it using parenthesization

bool isOperator(char ch) {
    return ch == '+' || ch == '*';
}

void solve(string &exp) {
    vector<int>num;
    vector<char>opr;
    string temp = "";
    for(int i = 0; i<exp.size(); i++) {
        if(isOperator(exp[i])) {
            opr.push_back(exp[i]);
            num.push_back(stoi(temp));
            temp = "";
        } else {
            temp.push_back(exp[i]);
        }
    }

    num.push_back(stoi(temp)); temp = "";

    int n = num.size();
    vector<vector<int>>maxVal(n, vector<int>(n, 0));
    vector<vector<int>>minVal(n, vector<int>(n, INT_MAX));

    for(int i = 0; i<n; i++) {
        maxVal[i][i] = num[i];
        minVal[i][i] = num[i];
    }
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i<n-len+1; i++) {
            int j = i + len - 1;
            for(int k = i; k<j; k++) {
                int mnTemp = 0, mxTemp = 0;
                if(opr[k] == '+') {
                    mnTemp = minVal[i][k] + minVal[k+1][j];
                    mxTemp = maxVal[i][k] + maxVal[k+1][j];
                }
                else if(opr[k] == '*') {
                    mnTemp = minVal[i][k] * minVal[k+1][j];
                    mxTemp = maxVal[i][k] * maxVal[k+1][j];
                }
                if(mnTemp < minVal[i][j])
                    minVal[i][j] = mnTemp;
                
                if(mxTemp > maxVal[i][j])
                    maxVal[i][j] = mxTemp;

            }
        }
    }
    cout << minVal[0][n-1] << " " << maxVal[0][n-1] << "\n";
}

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