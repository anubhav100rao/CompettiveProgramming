#include "template.cpp"

template <class T, class L> class SegTree {
  private:
    vector<T> tree;
    vector<pair<int, L>> ltree;
    int size;
    function<T(T &, T &)> build_operation;
    vector<function<L(L &, L &)>> lazy_update_operation;
    vector<function<T(int, int, T &, L &)>> unlazy_operation;
    L defaultVal;
    int types;
    void build(T *, int, int, int);
    void unlazyNode(int, int, int);
    T _query(int, int, int, int, int);
    void _update(int, int, int, int, int, pair<int, L>);
    SegTree(const SegTree &) = delete;

  public:
    SegTree(vector<T> arr, function<T(T &, T &)> build_operation,
            vector<function<L(L &, L &)>> lazy_update_operation,
            vector<function<T(int, int, T &, L &)>> unlazy_operation,
            L defaultVal);
    T query(int, int);
    void update(int, int, int, L);
};

// arr = base array.
// build operation = basic operation, ex- min(left, right).
// lazy_update_operation, operation to update a lazy node's lazy value (same
// type), ex- ltree[i] += val. unlazy_operation, operation to convert a lazy
// node into non-lazy, ex tree[i]+=ltree[i]. defaultVal = defaultVal in ltree of
// non lazy nodes.
template <typename T, typename L>
SegTree<T, L>::SegTree(vector<T> arr, function<T(T &, T &)> build_operation,
                       vector<function<L(L &, L &)>> lazy_update_operation,
                       vector<function<T(int, int, T &, L &)>> unlazy_operation,
                       L defaultVal)

    : size(arr.size()), build_operation(build_operation),
      lazy_update_operation(lazy_update_operation),
      unlazy_operation(unlazy_operation), defaultVal(defaultVal),
      types(unlazy_operation.size()) {

    tree.resize(size * 4 + 1);
    ltree.resize(size * 4 + 1, {-1, defaultVal});
    build(&arr[0], 1, 0, size - 1);
}

template <typename T, typename L>
void SegTree<T, L>::build(T *arr, int i, int start, int stop) {

    if (start == stop) {
        tree[i] = arr[start];
        return;
    }

    int mid = (stop + start) / 2;

    build(arr, 2 * i, start, mid);
    build(arr, 2 * i + 1, mid + 1, stop);

    tree[i] = build_operation(tree[2 * i], tree[2 * i + 1]);
}

template <typename T, typename L>
void SegTree<T, L>::unlazyNode(int i, int start, int end) {
    int t = ltree[i].first;
    tree[i] = unlazy_operation[t](start, end, tree[i], ltree[i].second);

    if (start != end) {
        int mid = (start + end) / 2;
        if (ltree[2 * i].first != t && ltree[2 * i].first != -1)
            unlazyNode(2 * i, start, mid);
        if (ltree[2 * i + 1].first != t && ltree[2 * i + 1].first != -1)
            unlazyNode(2 * i + 1, mid + 1, end);

        ltree[2 * i].first = ltree[2 * i + 1].first = t;
        ltree[2 * i].second =
            lazy_update_operation[t](ltree[2 * i].second, ltree[i].second);
        ltree[2 * i + 1].second =
            lazy_update_operation[t](ltree[2 * i + 1].second, ltree[i].second);
    }

    ltree[i] = {-1, defaultVal};
}

template <typename T, typename L> T SegTree<T, L>::query(int l, int r) {
    return _query(1, 0, size - 1, l, r);
}

template <typename T, typename L>
void SegTree<T, L>::update(int l, int r, int type, L val) {
    _update(1, 0, size - 1, l, r, {type, val});
}

template <typename T, typename L>
T SegTree<T, L>::_query(int i, int start, int end, int l, int r) {

    if (ltree[i].first != -1) {
        unlazyNode(i, start, end);
    }

    if (l <= start && end <= r) {
        return tree[i];
    }

    int mid = (start + end) / 2;

    T left, right, ret;
    bool lflag = 0, rflag = 0;

    if (l <= mid) {
        left = _query(2 * i, start, mid, l, r);
        lflag = 1;
    }
    if (mid + 1 <= r) {
        right = _query(2 * i + 1, mid + 1, end, l, r);
        rflag = 1;
    }
    if (lflag && rflag)
        ret = build_operation(left, right);
    else if (lflag)
        ret = left;
    else if (rflag)
        ret = right;

    return ret;
}

template <typename T, typename L>
void SegTree<T, L>::_update(int i, int start, int end, int l, int r,
                            pair<int, L> val) {
    if (ltree[i].first != -1) {
        unlazyNode(i, start, end);
    }

    if (l <= start && end <= r) {
        ltree[i] = val;
        unlazyNode(i, start, end);
        return;
    }

    if (r < start || l > end) {
        return;
    }

    int mid = (start + end) / 2;

    _update(2 * i, start, mid, l, r, val);
    _update(2 * i + 1, mid + 1, end, l, r, val);

    tree[i] = build_operation(tree[2 * i], tree[2 * i + 1]);
}
