#include "template.cpp"

// Makes an array like object.
// For int, sieve[x] gives largest prime factor of x.
// For bool prime gives 1, else 0
template <typename T> class Sieve {
  private:
    vector<T> arr;
    int n;

  public:
    inline T operator[](int x) { return arr[x]; }
    Sieve(int size);
};

// c return array like object, sieve[x]==1 if prime, 0 otherwise
template <> Sieve<bool>::Sieve(int size) {
    n = size;
    arr.resize(n + 1, 1);

    for (ll i = 2; i * i <= n; i++) {
        if (arr[i] == 1)
            for (ll j = i * i; j <= n; j += i)
                arr[j] = 0;
    }
}

// for int, sieve[x] gives largest prime factor of x
template <typename T> Sieve<T>::Sieve(int size) {
    n = size;
    arr.resize(n + 1, 1);

    for (ll i = 2; i <= n; i++) {
        if (arr[i] == 1) {
            for (ll j = i; j <= n; j += i)
                arr[j] = i;
        }
    }
}

