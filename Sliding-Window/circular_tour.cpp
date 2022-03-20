#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// amount of petrol
// distance of next petrol pump
struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
    public:
    // find starting petrol pump so that we can visit all petrol pumps
    int tour(petrolPump p[],int n) {
        int start = 0, end = 1;
        int curr_petrol = p[start].petrol - p[start].distance;
        while(start != end || curr_petrol < 0) {
            while(curr_petrol < 0 and start != end) {
                curr_petrol -= p[start].petrol - p[start].distance;
                start = (start + 1) % n;
                if(start == 0)
                    return -1;
            }
            curr_petrol += p[end].petrol - p[end].distance;
            end = (end + 1) % n;
        }
        return start;
    }

    int solve(petrolPump p[], int n) {
        int cap = 0, start = 0, deficit = 0;
        for(int i = 0; i<n; i++) {
            cap += p[i].petrol - p[i].distance;
            if(cap < 0) {
                deficit += cap;
                cap = 0;
                start = i+1;
            }
        }
        return (cap + deficit >= 0) ? start: -1;
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