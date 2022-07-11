#ifndef LOADED_TEMPLATE
#define LOADED_TEMPLATE
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define index(i, n) for (ll i = 0; i < ll(n); i++)
#define index1(i, n) for (ll i = 1; i <= ll(n); i++)
#define range(i, a, b) for (ll i = a; i < ll(b); i++)
#define indexD(i, n) for (ll i = ll(n) - 1; i >= 0; i--)
#define index1D(i, n) for (ll i = n; i >= 1; i--)
#define rangeD(i, a, b) for (ll i = (ll)a - 1; i >= b; i--)
#define ceild(a, b) (((a) + (b)-1) / (b))
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define print(x) cout << (x) << '\n'
#define all(v) (v).begin(), (v).end()
#define popcount(n) __builtin_popcountll(n)
#define ff first
#define ss second
#ifndef mod
#define mod 1000000007
#endif
#define inf (0x3F3F3F3F3F3F3F3FLL)
#define iinf (0x3F3F3F3F)
#ifndef trace_stream
#define trace_stream cout
#endif
#define COLOR_START "\e[1;31m"
#define COLOR_END "\e[0m"
using namespace std;

// using namespace __gnu_pbds;
// template <class T>
// using ordered_set =
//     tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;

// template <class T>
// using unordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
//                            tree_order_statistics_node_update>;

#ifndef SUBMIT

#define trace(args...)                                                         \
    {                                                                          \
        vector<string> arg_list = debug::_parse_args(#args);                   \
        debug::_print_err(__LINE__, arg_list.begin(), args);                   \
    }

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  Container const &c);

// output pair
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &m) {
    os << '(' << m.first << ", " << m.second << ')';
    return os;
}
// output container
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  Container const &c) {
    os << "{";
    if (!c.empty()) {
        os << *c.begin();
        for (auto i = ++c.begin(); i != c.end(); i++)
            os << ", " << *i;
    }
    return os << "}";
}

// input pair
template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &m) {
    is >> m.first >> m.second;
    return is;
}

// output __int128
/* std::ostream &operator<<(std::ostream &o, const __int128 &x) {
    if (x == std::numeric_limits<__int128>::min())
        return o << "-170141183460469231731687303715884105728";
    if (x < 0)
        return o << "-" << -x;
    if (x < 10)
        return o << (char)(x + '0');
    return o << x / 10 << (char)(x % 10 + '0');
} */

// trace
namespace debug {
// argument parser for trace
const vector<pair<char, char>> _BRACKETS{{'(', ')'}, {'{', '}'}, {'[', ']'}};
vector<string> _parse_args(string arg_string) {
    vector<string> res;
    int stack_size = 0;
    int last = 0, len = 0;
    for (int i = 0; i < arg_string.size(); i++) {
        if (arg_string[i] == ',' && stack_size == 0) {
            res.push_back(arg_string.substr(last, len));
            last = i + 1;
            len = 0;
        } else {
            for (auto bp : _BRACKETS) {
                if (bp.first == arg_string[i])
                    stack_size++;
                else if (bp.second == arg_string[i])
                    stack_size--;
            }
            if (len || arg_string[i] != ' ')
                len++;
            else
                last = i + 1;
        }
    }
    if (len > 0)
        res.push_back(arg_string.substr(last, len));
    return res;
}
template <typename T> void _print_err_util(vector<string>::iterator it, T a) {
    trace_stream << *it << ':' << a << endl;
}
template <typename T, typename... Args>
void _print_err_util(vector<string>::iterator it, T a, Args... args) {
    trace_stream << *it << ':' << a << " | ";
    _print_err_util(++it, args...);
}
template <typename... Args>
void _print_err(int lineNumber, vector<string>::iterator it, Args... args) {
    trace_stream << COLOR_START << lineNumber << "> " << COLOR_END;
    _print_err_util(it, args...);
}
} // namespace debug

#else

#define trace(args...) // args...

#endif
typedef long long int ll;
// typedef __int128 el;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
#endif
