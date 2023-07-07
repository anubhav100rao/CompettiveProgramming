#include <bits/stdc++.h> 
using namespace std;
#define ll long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(ll i = a; i<b; i++)
#define index(i, n) for(ll i = 0; i<n; i++)
#define rrep(i, b, a) for(ll i = b; i>=a; i--)
#define INF 2e18
const long long mod = 1e9 + 7;
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
#define vi vector<int>
#define mii map<int, int> 
#define pii pair<int, int>
#define sz(a) (int)(a).size()
#define setbits(x) __builtin_popcountll(x)




struct Segment {
    int left, right, color;
    Segment(int left, int right, int color): left(left), right(right), color(color) {}
    Segment() {}
};

struct compareLeft {
    bool operator()(Segment &a, Segment &b) {
        return a.left < b.left;
    }
};

struct compareRight {
    bool operator()(Segment &a, Segment &b) {
        return a.right > b.right;
    }
};




istream &operator >>( istream &input, Segment &a )
{
    input >> a.left >> a.right >> a.color;
    return input; 
}

//*.........................VARIABLES


//*.........................FUNCTIONS


//* ........................LOGIC
void solve() {
    int n; cin >> n;
    vector<Segment>arr(n);
    index(i, n)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), compareLeft());

    vector<int>ans;

    priority_queue<Segment, vector<Segment>, compareRight>pq;
    vector<int>fre(n + 1);
    vector<Segment>pop_positions(n + 1, Segment(-10, -10, -10));
    vector<Segment>pop_history;

    
    for(int i = 0; i < n; i++) {
        while(!pq.empty() and pq.top().right < arr[i].left) {
            Segment top = pq.top();
            fre[top.color]--;
            int idx = pop_history.size();
            pop_history.push_back(top);
            
            if(pop_positions[top.color].right + 1 == idx) {
                pop_positions[top.color].right++;
            } else {
                pop_positions[top.color] = Segment(idx, idx, -1);
            }
            
            pq.pop();
        }



        if((int)pq.size() - fre[arr[i].color]) {
            ans.push_back(0);
        } else {
            int res = INT_MAX;
            if(!pop_history.empty() and pop_history.back().color != arr[i].color) {
                res = min(res, abs(arr[i].left - pop_history.back().right));
            } else if(pop_positions[arr[i].color].left > 0) {
                res = min(res, abs(arr[i].left - pop_history[pop_positions[arr[i].color].left - 1].right));
            }

            ans.push_back(res);

        }
        fre[arr[i].color]++;
        pq.push(arr[i]);
    }

    for(int i: ans) cout << i << " "; cout << "\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }    
    return 0;
}