#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int flipLights(int n, int presses) {
        // observation
        // A op A = 0
        // A op B = B op A
        if(presses == 0)
            return 1;

        set<string>res;
        res.insert(string(n, '1'));

        if(presses >= 1) {
            vector<string>arr;
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(i&1) {
                        if(temp[i] == '1')
                            temp[i] = '0';
                        else temp[i] = '1';
                    }
                }
                arr.push_back(temp);
            }
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(!(i & 1)) {
                        if(temp[i] == '1')
                            temp[i] = '0';
                        else temp[i] = '1';
                    }
                }
                arr.push_back(temp);
            }
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i+=3) {
                    if(temp[i] == '1')
                        temp[i] = '0';
                    else temp[i] = '1';
                }
                arr.push_back(temp);
            }

            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(temp[i] == '0') temp[i] = '0';
                    else temp[i] = '1';
                }
                arr.push_back(temp);
            }

            for(string str: arr) res.insert(str);
            
        }

        if(presses >= 2) {
            vector<string>arr;
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(i&1) {
                        if(temp[i] == '1')
                            temp[i] = '0';
                        else temp[i] = '1';
                    }
                }
                arr.push_back(temp);
            }
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(!(i & 1)) {
                        if(temp[i] == '1')
                            temp[i] = '0';
                        else temp[i] = '1';
                    }
                }
                arr.push_back(temp);
            }
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i+=3) {
                    if(temp[i] == '1')
                        temp[i] = '0';
                    else temp[i] = '1';
                }
                arr.push_back(temp);
            }

            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(temp[i] == '0') temp[i] = '0';
                    else temp[i] = '1';
                }
                arr.push_back(temp);
            }

            for(string str: arr) res.insert(str);
        }
        if(presses >= 3) {
            vector<string>arr;
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(i&1) {
                        if(temp[i] == '1')
                            temp[i] = '0';
                        else temp[i] = '1';
                    }
                }
                arr.push_back(temp);
            }
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(!(i & 1)) {
                        if(temp[i] == '1')
                            temp[i] = '0';
                        else temp[i] = '1';
                    }
                }
                arr.push_back(temp);
            }
            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i+=3) {
                    if(temp[i] == '1')
                        temp[i] = '0';
                    else temp[i] = '1';
                }
                arr.push_back(temp);
            }

            for(string str: res) {
                string temp = str;
                for(int i = 0; i<n; i++) {
                    if(temp[i] == '0') temp[i] = '0';
                    else temp[i] = '1';
                }
                arr.push_back(temp);
            }

            for(string str: arr) res.insert(str);
        }
        
        return res.size();
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