#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0, square = 0;
        for(int i: students)
            if(i == 0)
                circular++;
            else
                square++;
        for(int i: sandwiches) {
            if(i == 0)
                if(circular > 0)
                    circular--;
                else 
                    break;
            else if(i == 1)
                if(square > 0)
                    square--;
                else
                    break;
        }
        
        return circular + square;
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