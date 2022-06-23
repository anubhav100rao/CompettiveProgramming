#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

template<typename T>
class NodePair {
public:
    T first;
    T second;

    NodePair(T first, T second) {
        this->first = first;
        this->second = second;
    }

    bool operator==(const NodePair node) const {
        return node.first == this->first and node.second == this->second;
    }
};


class Node {
public:
    int first;
    int second;
    Node(int first, int second) {
        this->first = first;
        this->second = second;
    }

    bool operator<(const Node node) const {
        return this->first == node.first ? this->second < node.second : this->first < node.first;
    }
};

struct HashFunction {
    size_t operator()(NodePair<int> node) const {
        return node.first * 797 + node.second*1337;
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
    unordered_set<NodePair<int>, HashFunction>hsh;
    hsh.insert(NodePair<int>(1, 2));
    hsh.insert(NodePair<int>(1, 2));
    cout << hsh.size() << "\n";
    set<Node>hsh_set;
    hsh_set.insert(Node(1, 2));
    hsh_set.insert(Node(2, 3));
    cout << (*hsh_set.begin()).first << " " << (*hsh_set.begin()).second << " " << hsh_set.size() << "\n";
    return 0;
}