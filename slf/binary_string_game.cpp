#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

const string Bert = "Bert";
const string Ernie = "Ernie";
const string Tie = "Tie";

// if zero == 0: Tie

// if zero is even || zero at centre -> Bert
// else Ernie

const int inf = 1e9;
int dp[100][100][2][2];

// curr - opp
int f(int zz, int oz, int centre, bool last_reverse) {
    if(zz == 0 and oz == 0 and centre == 0) {
        return 0;
    }

    int &ans = dp[zz][oz][centre][last_reverse];

    if(ans != -1) {
        return ans;
    }

    ans = inf;
    if(zz > 0) {
        ans = min(ans, 1 - f(zz - 1, oz + 1, centre, false));
    }

    if(oz > 0) {
        ans = min(ans, 1 - f(zz, oz - 1, centre, false));
    }

    if(centre > 0) {
        ans = min(ans, 1 - f(zz, oz, 0, false));
    }

    if(!last_reverse and oz > 0) {
        ans = min(ans, -f(zz, oz, centre, true));
    }

   // cout << zz << " " << oz << " " << centre << " " << last_reverse << " " << ans << "\n";


    return ans;
}

string solve(string &str) {
    int centre = 0;
    int n = str.size();
    if((n & 1) and str[n/2] == '0') centre = 1;

    int zz = 0;
    int oz = 0;

    for(int i = 0; i < n/2; i++) {
        if(str[i] == str[n-i-1]) {
            if(str[i] == '0') {
                zz++;
            }
        } else {
            oz++;
        }
    }  

    int res = f(zz, oz, centre, false);


    cout << res << endl;
    return (res == 0) ? Tie : (res > 0 ? Bert : Ernie);
}

vector<string> findWinner(vector<string> &specialStrings) {
    return {};
}


// if zero == 0: Tie
// if zero is even || zero at centre -> Bert
// else Ernie

string solveSingle(string &str) {
    int n = str.size();
    int zero = count(str.begin(), str.end(), '0');
    if(zero == 0) {
        return Tie;
    }
    if(zero == 1 || zero % 2 == 0) {
        return Bert;
    } else {
        return Ernie;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    memset(dp, -1, sizeof dp);
 
    string a, b; cin >> a >> b;
    cout << solveSingle(a) << "\n" << solveSingle(b) << '\n';
    

    return 0;
}