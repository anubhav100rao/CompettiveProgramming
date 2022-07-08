#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class LRUCache {
public:

    map<int, int>hsh;
    int capacity;
    stack<int>last_used;


    void print() {
        for(auto [a, b]: hsh) {
            cout << a << " " << b << "\n";
        } cout << "-------------------\n";
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hsh.count(key)) {
            last_used.push(key);
            return hsh[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hsh.size() == capacity) {
            if(last_used.empty()) {
                hsh.erase(hsh.begin());
            } else {
                while(!last_used.empty() and !hsh.count(last_used.top())) {
                    last_used.pop();
                }
                if(last_used.empty()) {
                    hsh.erase(hsh.begin());
                } else {
                    hsh.erase(last_used.top());
                    last_used.pop();
                }
            }
        }
        last_used.push(key);
        hsh[key] = value;

        print();
        
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