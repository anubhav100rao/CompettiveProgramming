#include "template.cpp"


template <class T> class SegTree {
  private:
    T _query(int, int, int, int, int);
    void _update(int, int, int, int, function<T(T &)>);
    function<T(T &, T &)> operation;
    // SegTree(const SegTree &) = delete;
    void _build(vector<T> &, int, int, int);

  public:
    int size;
    vector<T> _tree;
    void build(vector<T> &);
    SegTree(function<T(T &, T &)>);
    SegTree(vector<T>, function<T(T &, T &)>);
    T query(int, int);
    void update(int, function<T(T &)>);
};

template <typename T>
SegTree<T>::SegTree(function<T(T &, T &)> operation) : operation(operation) {
    size = 0;
}

template <typename T>
SegTree<T>::SegTree(vector<T> v, function<T(T &, T &)> operation)
    : size(v.size()), operation(operation) {
    _tree.resize(size * 4 + 1);
    _build(v, 1, 0, size - 1);
}

template <typename T> void SegTree<T>::build(vector<T> &v) {
    size = v.size();
    _tree.resize(size * 4 + 1);
    _build(v, 1, 0, size - 1);
}

// [start, stop]
template <typename T>
void SegTree<T>::_build(vector<T> &v, int i, int start, int stop) {

    if (start == stop) {
        _tree[i] = v[start];
        return;
    }

    int mid = (stop + start) / 2;

    _build(v, 2 * i, start, mid);
    _build(v, 2 * i + 1, mid + 1, stop);

    _tree[i] = operation(_tree[2 * i], _tree[2 * i + 1]);
}

// Return the value between [l, r] inclusive (0 index)
template <typename T> T SegTree<T>::query(int l, int r) {
    if (!(0 <= l && l <= r && r < size)) {
        cerr << "Index error in query" << endl;
        cerr << "l: " << l << " r:" << r << " size:" << size << endl;
        exit(131);
    }
    return _query(1, 0, size - 1, l, r);
}

// Update value at a (index 0) by using update function
template <typename T>
void SegTree<T>::update(int a, function<T(T &)> updateFun) {
    if (!(0 <= a && a < size)) {
        cerr << "Index error in update" << endl;
        cerr << "a: " << a << " size:" << size << endl;
        exit(131);
    }
    _update(1, 0, size - 1, a, updateFun);
}

template <typename T>
T SegTree<T>::_query(int i, int start, int end, int l, int r) {

    if (l <= start && end <= r)
        return _tree[i];

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
        ret = operation(left, right);
    else if (lflag)
        ret = left;
    else if (rflag)
        ret = right;
    else
        exit(131);
    return ret;
}

template <typename T>
void SegTree<T>::_update(int i, int start, int end, int a,
                         function<T(T &)> updateFun) {

    if (a < start || a > end)
        return;

    if (start == end) {
        _tree[i] = updateFun(_tree[i]);
        return;
    }

    int mid = (start + end) / 2;

    _update(2 * i, start, mid, a, updateFun);
    _update(2 * i + 1, mid + 1, end, a, updateFun);

    _tree[i] = operation(_tree[2 * i], _tree[2 * i + 1]);
    return;
}
