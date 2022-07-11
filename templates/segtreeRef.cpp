#include "template.cpp"

template <class T> class SegTree {
  private:
    int size;
    vector<T> tree, ltree;
    void build(T *, int, int, int);
    void _query(int, int, int, int, int, bool, T &);
    void _update(int, int, int, int, function<void(T &)>);
    function<void(T &, T &, T &)> operation;
    SegTree(const SegTree &) = delete;

  public:
    SegTree(vector<T>, function<void(T &, T &, T &)>);
    SegTree(T *, int, function<void(T &, T &, T &)>);
    T query(int, int);
    void update(int, function<void(T &)>);
};

template <class T>
SegTree<T>::SegTree(T *arr, int size, function<void(T &, T &, T &)> operation)
    : size(size), operation(operation) {
    tree.resize(size * 4 + 1);
    build(arr, 1, 0, size - 1);
}

template <typename T>
SegTree<T>::SegTree(vector<T> v, function<void(T &, T &, T &)> operation)
    : size(v.size()), operation(operation) {
    tree.resize(size * 4 + 1);
    build(&v[0], 1, 0, size - 1);
}

// [start, stop]
template <typename T>
void SegTree<T>::build(T *arr, int i, int start, int stop) {

    if (start == stop) {
        tree[i] = arr[start];
        return;
    }

    int mid = (stop + start) / 2;

    build(arr, 2 * i, start, mid);
    build(arr, 2 * i + 1, mid + 1, stop);

    operation(tree[i], tree[2 * i], tree[2 * i + 1]);
}

// Return the value between [l, r] inclusive (0 index)
template <typename T> T SegTree<T>::query(int l, int r) {
    assert(0 <= l && l <= r && r < size);
    T res;
    _query(1, 0, size - 1, l, r, 1, res);
    return res;
}

// Update value at a (index 0) by using update function
template <typename T>
void SegTree<T>::update(int a, function<void(T &)> updateFun) {
    assert(0 <= a && a < size);
    _update(1, 0, size - 1, a, updateFun);
}

template <typename T>
void SegTree<T>::_query(int i, int start, int end, int l, int r, bool leftmost,
                        T &res) {

    if (l <= start && end <= r) {
        if (leftmost)
            res = tree[i];
        else
            operation(res, tree[i], res);
        return;
    }

    int mid = (start + end) / 2;

    if (l <= mid)
        _query(2 * i, start, mid, l, r, leftmost, res);

    if (mid + 1 <= r)
        _query(2 * i + 1, mid + 1, end, l, r, 0, res);
}

template <typename T>
void SegTree<T>::_update(int i, int start, int end, int a,
                         function<void(T &)> updateFun) {

    if (a < start || a > end)
        return;

    if (start == end) {
        updateFun(tree[i]);
        return;
    }

    int mid = (start + end) / 2;

    _update(2 * i, start, mid, a, updateFun);
    _update(2 * i + 1, mid + 1, end, a, updateFun);

    operation(tree[i], tree[2 * i], tree[2 * i + 1]);
}
