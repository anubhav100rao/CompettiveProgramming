#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

void print_vector(vector<int>&arr) {
    for(int &i: arr) cout << i << " ";
    cout << "\n";
}

void solve(vector<int>&arr, int index) {
    if(index == arr.size()) {
        print_vector(arr);
    } else {
        solve(arr, index+1);
        for(int i = index+1; i<arr.size(); i++) {
            swap(arr[index], arr[i]);
            solve(arr, index+1);
            swap(arr[index], arr[i]);
        }
    }
}

void permute(string &str, int index) {
    if(index == str.size()) {
        cout << str << '\n';
    } else {
        permute(str, index+1);
        for(int i = index+1; i<str.size(); i++) {
            swap(str[i], str[index]);
            permute(str, index+1);
            swap(str[i], str[index]);
        }
    }
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    string str; cin >> str;
    permute(str, 0);
    return 0;
}