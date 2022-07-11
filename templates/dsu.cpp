#include "template.cpp"

class DSU {
  private:
    int get_root_optimized(int a);
    int get_root_normal(int a);
    int n;

  public:
    vector<int> parent, _size;
    vector<ll> values;
    bool path_optimization;
    bool store_values;

    DSU(bool = 1);
    DSU(int, bool = 1);
    DSU(vector<ll>, bool = 1);
    void resize(int);
    void join_sets(int a, int b);
    int get_root(int a);
    ll get_value(int a);
    bool same_set(int a, int b);
    bool is_root(int a);
    int get_size(int a);
};
// Make a default DSU with no elements, with or without path_optimization
DSU::DSU(bool path_optimization) : path_optimization(path_optimization) {
    store_values = 0;
}
void DSU::resize(int n) {
    this->n = n;
    parent.clear();
    _size.clear();
    parent.resize(n + 1);
    _size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

// Make a default DSU with n elements, with or without path_optimization
DSU::DSU(int n, bool path_optimization)
    : n(n), path_optimization(path_optimization) {
    store_values = 0;
    parent.resize(n + 1);
    _size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

// Make a DSU with values as base array (1 indexed), with or without
// path_optimization
DSU::DSU(vector<ll> values, bool path_optimization)
    : values(values), path_optimization(path_optimization) {
    n = values.size();
    store_values = 1;
    parent.resize(n + 1);
    _size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

// join the sets that a and b belong too
void DSU::join_sets(int a, int b) {
    assert(a <= n and b <= n);
    a = get_root(a);
    b = get_root(b);

    if (_size[a] > _size[b])
        swap(a, b);

    if (a != b) {
        parent[a] = b;
        _size[b] += _size[a];
        if (store_values)
            values[b] += values[a];
    }
}

// get set id of a
int DSU::get_root(int a) {
    assert(a <= n);
    if (path_optimization)
        return get_root_optimized(a);
    else
        return get_root_normal(a);
}

int DSU::get_root_normal(int a) {
    while (a != parent[a])
        a = parent[a];
    return a;
}

int DSU::get_root_optimized(int a) {
    if (a != parent[a])
        parent[a] = get_root(parent[a]);
    return parent[a];
}

bool DSU::same_set(int a, int b) { return get_root(a) == get_root(b); }

int DSU::get_size(int a) { return _size[get_root(a)]; }

bool DSU::is_root(int a) { return parent[a] == a; }

ll DSU::get_value(int a) { return values[a]; }
