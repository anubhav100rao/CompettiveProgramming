#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct Point {
    int x, y, z;
    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int calDistance(Point p1, Point p2) {
    return min({
        abs(p1.x - p2.x),
        abs(p1.y - p2.y),
        abs(p1.z - p2.z)
    });
}

struct DSU {
    vector<int>parent;
    vector<int>comp_sz;
    DSU(int n) {
        parent.resize(n + 1, 0);
        comp_sz.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_parent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find_parent(parent[node]);
    }

    bool merge(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if(a == b) return false;

        if(comp_sz[a] < comp_sz[b]) swap(a, b);

        parent[b] = a;
        comp_sz[a] += comp_sz[b];
        return true;
    }
};

int minLengthRope(vector<Point>points) {
    int n = points.size();
    vector<vector<int>>edges;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int d = calDistance(points[i], points[j]);
            edges.push_back({d, i, j});
            edges.push_back({d, j, i});
        }
    }

    sort(edges.begin(), edges.end());

    
    int dist = 0;
    
    DSU dsu(100);
    for(auto edge: edges) {
        int wt = edge[0], from = edge[1], to = edge[2];
        if(dsu.merge(from, to)) {
            dist += wt;
        }
    }

    return dist;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    vector<Point>points = { {1, 2, 3}, {6, 8, 1}, {5, 3, 4}, {8, 5, 6} };
          

    cout << minLengthRope(points);

    return 0;
}