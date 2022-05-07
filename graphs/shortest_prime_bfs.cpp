#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

const int N = 1e5 + 10;
vector<bool>is_prime(N+1, true);


set<int>primes;



int generateNewNum(int num, int idx, int change) {
    string str_num = to_string(num);
    if(idx == 0 and change == 0)
        return -1;
    
    if(str_num[idx] - '0' == change)
        return -1;
    str_num[idx] = '0' + change;
    
    num = stoi(str_num);
    if(primes.count(num)) {
        primes.erase(num);

        return num;
    }
    
    return -1;
}

void seive() {
    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 2; i<N; i++) {
        if(is_prime[i])
            for(int j = i + i; j < N; j+= i) {
                is_prime[j] = false;
            }
    }

    for(int i = 1000; i<10000; i++) {
        if(is_prime[i]) {
            primes.insert(i);
        }
    }
}

int shortestDistance(int l, int r) {
    if(l == r)
        return 0;
    queue<int>q;
    q.push(l);
    map<int, int>dis;
    dis[l] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i = 0; i<4; i++) {
            for(int j = 0; j<=9; j++) {
                int genNum = generateNewNum(node, i, j);
                if(genNum != -1) {
                    dis[genNum] = dis[node] + 1;
                    q.push(genNum);
                }
            }
        }
    }

    
    if(dis.count(r))
        return dis[r];
    return 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    seive();
    
    int l, r; cin >> l >> r;
    cout << shortestDistance(l, r) << '\n';
    return 0;
}