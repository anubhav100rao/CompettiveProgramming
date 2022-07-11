#include "template.cpp"

class BiTree {
  private:
    int size;

  public:
    vector<ll> tree;
    BiTree(int);
    void updateAdd(int, ll);
    void update(int, ll);
    ll query(int, int);
    ll sumTill(int);
};

BiTree::BiTree(int size) : size(size) { tree.resize(size + 1, 0); }

// get sum of values between [l, r] (inclusive, 1 index)
ll BiTree::query(int l, int r) {
    assert(l <= r);
    return sumTill(r) - sumTill(l - 1);
}

// get sum of values till a (1 index)
ll BiTree::sumTill(int a) {
    assert(0 <= a && a <= size);
    ll ans = 0;
    while (a != 0) {
        ans += tree[a];
        a -= (a & -a);
    }
    return ans;
}

// add val at i to value (1 index)
void BiTree::updateAdd(int k, ll val) {
    while (k <= size) {
        tree[k] += val;
        k += k & -k;
    }
}

// assign val at i to value (1 index)
void BiTree::update(int k, ll val) {
    ll cur = query(k, k);
    updateAdd(k, val - cur);
}
