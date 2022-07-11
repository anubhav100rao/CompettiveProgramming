#include "segtreeLazy.cpp"

template <class T, class L> class SegTree2d {
  private:
    int sizeX, sizeY;
    vector<SegTree<T, L>> _tree;

    void _combine(int, int, int);
    void _updateCombine(int, int, int, int, int, int, int);
    void build(vector<vector<T>> &v, int, int, int);

    function<L(L &, L &)> lazy_update_operation;
    function<T(T &, T &)> build_operation;
    function<T(int, int, T &, L &)> unlazy_operation;

    T _query(int, int, int, int, int, int, int);
    void _update(int, int, int, int, int, function<T(T &)>);
    SegTree2d(const SegTree2d &) = delete;

  public:
    L defaultVal;
    SegTree2d(vector<vector<T>>, function<T(T &, T &)>, function<L(L &, L &)>,
              function<T(int, int, T &, L &)>, L);
    T query(int, int, int, int);
    void update(int, int, function<T(T &)>);
};

template <typename T, typename L>
SegTree2d<T, L>::SegTree2d(vector<vector<T>> v,
                           function<T(T &, T &)> build_operation,
                           function<L(L &, L &)> lazy_update_operation,
                           function<T(int, int, T &, L &)> unlazy_operation,
                           L defaultVal)

    : sizeX(v.size()), sizeY(v[0].size()), build_operation(build_operation),
      lazy_update_operation(lazy_update_operation),
      unlazy_operation(unlazy_operation), defaultVal(defaultVal) {

    _tree.resize(sizeX * 4 + 1,
                 SegTree<T, L>(sizeY, build_operation, lazy_update_operation,
                               unlazy_operation, defaultVal));
    build(v, 1, 0, sizeX - 1);
}

// [start, stop]
template <typename T, typename L>
void SegTree2d<T, L>::build(vector<vector<T>> &v, int i, int start, int stop) {
    if (start == stop) {
        _tree[i] = SegTree<T, L>(v[start], build_operation,
                                 lazy_update_operation, unlazy_operation);
        return;
    }

    int mid = (stop + start) / 2;

    build(v, 2 * i, start, mid);
    build(v, 2 * i + 1, mid + 1, stop);
    _combine(i, i * 2, i * 2 + 1);
}

template <typename T, typename L>
void SegTree2d<T, L>::_combine(int r, int a, int b) {
    for (int j = 0; j <= 4 * sizeY; j++)
        _tree[r]._tree[j] =
            build_operation(_tree[a]._tree[j], _tree[b]._tree[j]);
}

// Return the value between [x2, x2] in first index and [y1, y2] in second
// index (0 index)
template <typename T, typename L>
T SegTree2d<T, L>::query(int x1, int x2, int y1, int y2) {
    if (!(0 <= x1 && x1 <= x2 && x2 < sizeX && 0 <= y1 && y1 <= y2 &&
          y2 < sizeY)) {
        cerr << "Index error in query" << endl;
        cerr << "x1:" << x1 << " x2:" << x1 << " sizeX:" << sizeX << endl;
        cerr << "y1:" << y1 << " y2:" << y2 << " sizeY:" << sizeY << endl;
        exit(131);
    }
    return _query(1, 0, sizeX - 1, x1, x2, y1, y2);
}

// Update value at (x, y) (index 0) by using update function
template <typename T, typename L>
void SegTree2d<T, L>::update(int x, int y, function<T(T &)> updateFun) {
    if (!(0 <= x && x < sizeX && 0 <= y && y < sizeY)) {
        cerr << "Index error in update" << endl;
        cerr << "x:" << x << " y:" << y << " sizeY:" << sizeY << endl;
        exit(131);
    }
    _update(1, 0, sizeX - 1, x, y, updateFun);
}

template <typename T, typename L>
T SegTree2d<T, L>::_query(int i, int start, int end, int x1, int x2, int y1,
                          int y2) {

    if (x1 <= start && end <= x2)
        return _tree[i].query(y1, y2);

    int mid = (start + end) / 2;

    T left, right, ret;
    bool lflag = 0, rflag = 0;

    if (x1 <= mid) {
        left = _query(2 * i, start, mid, x1, x2, y1, y2);
        lflag = 1;
    }
    if (mid + 1 <= x2) {
        right = _query(2 * i + 1, mid + 1, end, x1, x2, y1, y2);
        rflag = 1;
    }
    if (lflag && rflag)
        ret = build_operation(left, right);
    else if (lflag)
        ret = left;
    else if (rflag)
        ret = right;
    else
        exit(131);
    return ret;
}

template <typename T, typename L>
void SegTree2d<T, L>::_update(int i, int start, int end, int x, int y,
                              function<T(T &)> updateFun) {

    if (x < start || x > end)
        return;

    if (start == end) {
        _tree[i].update(y, updateFun);
        return;
    }

    int mid = (start + end) / 2;

    _update(2 * i, start, mid, x, y, updateFun);
    _update(2 * i + 1, mid + 1, end, x, y, updateFun);

    _updateCombine(1, 0, sizeY - 1, y, i, 2 * i, 2 * i + 1);

    return;
}

template <typename T, typename L>
void SegTree2d<T, L>::_updateCombine(int j, int start, int end, int y, int r,
                                     int a, int b) {

    if (y < start || y > end)
        return;

    if (start == end) {
        _tree[r]._tree[j] =
            build_operation(_tree[a]._tree[j], _tree[b]._tree[j]);
        return;
    }

    int mid = (start + end) / 2;

    _updateCombine(2 * j, start, mid, y, r, a, b);
    _updateCombine(2 * j + 1, mid + 1, end, y, r, a, b);

    _tree[r]._tree[j] = build_operation(_tree[a]._tree[j], _tree[b]._tree[j]);

    return;
}
