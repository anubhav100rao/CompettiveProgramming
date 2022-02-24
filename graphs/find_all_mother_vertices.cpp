#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class KosaRajuSCC {
    /**
     * run dfs from any node
     * and push node in stack after running dfs for all its childs
     * get transpose of graph
     * while !stack.empty():
     *         dfs(st.top()); st.pop();
     *         push this current component in global connectedComponents
    */
public:
    int n, m;
    stack<int>st;
    vector<vector<int>>adj;
    vector<vector<int>>trans;
    vector<bool>visited;
    vector<vector<int>>connectedComponents;
    void read() {
        cin >> n >> m;
        adj = vector<vector<int>>(n+1);
        trans = vector<vector<int>>(n+1);
        visited = vector<bool>(n+1, false);
        for(int i = 0; i<m; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            trans[b].push_back(a);
        }
    }

    void dfsUtil(int node) {
        visited[node] = true;
        for(int &child: adj[node]) {
            if(!visited[child]) {
                dfsUtil(child);
            }
        }
        st.push(node);
    }

    void init() {
        visited = vector<bool>(n+1, false);
    }

    void dfs() {
        init();
        for(int i = 1; i<=n; i++) {
            if(!visited[i]) {
                dfsUtil(i);
            }
        }
    }

    void dfsRunner(int node) {
        visited[node] = true;
        for(int &child: adj[node]) {
            if(!visited[child]) {
                dfsRunner(child);
            }
        }
    }

    int mother_vertex() {
        init();
        int last = -1;
        for(int i = 1; i<=n; i++) {
            if(!visited[i]) {
                dfsRunner(i);
                last = i;
            }
        }
        init();
        dfsRunner(last);
        for(int i = 1; i<=n; i++) {
            if(!visited[i]) return -1;
        }
        return last;
    }

    void dfsSCC(int node, vector<int>&component) {
        visited[node] = true;
        component.push_back(node);
        for(int &child: trans[node]) {
            if(!visited[child]) {
                dfsSCC(child, component);
            }
        }
    }

    int getConnectedComponents() {
        init();
        dfs();
        init();
        vector<int>component;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfsSCC(node, component);
                connectedComponents.push_back(component);
                component.clear();
            }
        }
        return connectedComponents.size();
    }

    vector<int>getAllMotherVertices() {
        vector<int>res;
        int mother = mother_vertex();
        if(mother == -1)
            return res;
        res.push_back(mother);
        getConnectedComponents();
        for(vector<int> component: connectedComponents) {
            bool contain = false;
            for(int i: component) {
                if(i == mother) {
                    contain = true;
                }
            }
            if(contain) for(int i: component) if(i != mother) res.push_back(i);
        }
        return res;
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