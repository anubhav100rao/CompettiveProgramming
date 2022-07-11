#include "template.cpp"

ll binpow(ll a, ll b) {
    a %= mod;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

class PNC {
  private:
    int maxn;
    bool check;
    vector<ll> _factorial;

  public:
    PNC(int n, bool);
    ll factorial(int);
    ll modInv(ll);
    ll ncr(int, int);
    ll npr(int, int);
};

// max n supported, wether to check for r<=n or just return 0
PNC::PNC(int maxn, bool check = 1) : maxn(maxn), check(check) {
    _factorial.resize(maxn + 1);
    _factorial[0] = 1;
    for (int i = 1; i < maxn; i++) {
        _factorial[i] = i * _factorial[i - 1] % mod;
    }
}
ll PNC::ncr(int n, int r) {
    if (r < 0 || n < 0 || r > n || n > maxn) {
        if (check)
            throw invalid_argument("ncr received invalid input: n = " +
                                   to_string(n) + ", r = " + to_string(r));
        else
            return 0;
    }
    return _factorial[n] * modInv(_factorial[r]) % mod *
           modInv(_factorial[n - r]) % mod;
}

ll PNC::npr(int n, int r) {
    if (r < 0 || n < 0 || r > n || n > maxn) {
        if (check)
            throw invalid_argument("npr received invalid input: n = " +
                                   to_string(n) + ", r = " + to_string(r));
        else
            return 0;
    }

    return _factorial[n] * modInv(_factorial[n - r]) % mod;
}

ll PNC::factorial(int n) {
    if (n < 0 || n > maxn) {
        throw invalid_argument("factorial received invalid input: n = " +
                               to_string(n));
    }
    return _factorial[n];
}

ll PNC::modInv(ll n) {
    if (n < 0) {
        throw invalid_argument("modInv received invalid input: n = " +
                               to_string(n));
    }
    return binpow(n, mod - 2);
}
