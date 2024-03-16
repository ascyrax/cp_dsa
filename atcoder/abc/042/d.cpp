// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using lld = long double;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void suraj();

signed main()
{

    fastio();

#ifndef ONLINE_JUDGE
    clock_t startTime = clock();
#endif

    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    // cout << setprecision(15) << fixed;

    int t = 1;

    // cin>>t;

    for (int i = 1; i <= t; i++)
    {

        // cout<<"Case #"<<i<<": ";

        suraj();

        debug("---");
    }

#ifndef ONLINE_JUDGE
    cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

    return 0;
}

int nCr(int n, int r)
{
    // debug(n);
    // debug(r);
    const int mod = 1e9 + 7;
    int res = 1;
    r = min(r, n - r);
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res %= mod;
    }
    for (int i = 1; i <= r; i++)
    {
        res /= i;
    }
    // debug(res);
    return res % mod;
}
void suraj()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    // cnt the no of permutations of R (right) & D (down) satisfying the problem constraints

    // no of Rs = w -1 ;
    // no of Ds = h-1;

    // in the first ((h-1-a) + (b)) elements of this permutation, there can only be (h-1-a) Ds and rest should be Rs.

    // int ans = nCr(((h - 1 - a) + (b)), h - 1 - a) * nCr(h - 1 + w - 1 - ((h - 1 - a) + (b)), h - 1 - (h - 1 - a));
    int ans = 0;
    const int mod = 1e9 + 7;

    for (int row = 1; row <= h - a; row++)
    {
        // b Rs in the first (row-1 + b)elements of the permutation
        int first = nCr(row - 1 + b, b);
        // debug(first);
        // remaining permutation of elements
        int second = nCr(h - 1 + w - 1 - (row - 1 + b), w - 1 - b);
        // debug(second);
        ans += (first * second % mod);
        // debug(ans);
    }

    cout << ans << endl;
}
