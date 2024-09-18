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
void suraj2();

int fact[200001];

void preCalcFactorials()
{
    const int mod = 1e9 + 7;
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
}

signed main()
{

    fastio();

#ifndef ONLINE_JUDGE
    clock_t startTime = clock();
#endif

    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    // cout << setprecision(15) << fixed;

    preCalcFactorials();

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

int calcPow(int base, int pow, int mod)
{
    int res = 1;
    // visualize if pow = 13 ie 0b1101
    // then we need to return "res" which is = base^1 * base^4 * base^8
    int val = base;
    while (pow)
    {
        if (pow & 1)
        {
            res *= val;
            res %= mod;
        }
        val *= val;
        val %= mod;
        pow = pow >> 1;
    }
    return res;
}
int modInv(int a, int mod)
{
    // return the modular inverse of a % mod
    // res = pow(a, mod - 2), if a % mod != 0, which will always be the case if a < mod :)

    return calcPow(a, mod - 2, mod);
}

int nCr(int n, int r)
{
    // debug(n);
    // debug(r);
    // debug(n - r);
    const int mod = 1e9 + 7;
    int res = fact[n];
    int factR = fact[r];
    int factNMinusR = fact[n - r];
    // debug(res);
    // debug(factR);
    // debug(factNMinusR);
    res *= modInv(factR, mod);
    res %= mod;
    res *= modInv(factNMinusR, mod);
    res %= mod;
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

    if (b == w - 1)
    {
        int first = nCr(w - 1 + h - 1 - a, b);
        int second = 1;
        ans = first * second;
        ans %= mod;
        cout << ans << endl;
        return;
    }

    for (int row = 1; row <= h - a - 1; row++)
    {
        // b Rs in the first (row-1 + b)elements of the permutation VIZ Iroha ends up in [row][b+1] position in the 1-indexed grid :)
        int first = nCr(row - 1 + b, b);
        // debug(first);
        // remaining permutation of elements
        int second = 1;
        if (b == w - 1)
            second = 1;
        else
            second = nCr((h - 1 + w - 1) - ((row - 1) + (b + 1)), ((w - 1) - (b + 1))); // assuming after the moves which led to 'first', we do a R, and then any permutation :)
        // debug(second);
        ans += ((first * second));
        ans %= mod;
        // debug(ans);
    }
    for (int row = h - a; row <= h - a; row++)
    {
        int first = nCr(row - 1 + b, b);
        int second = nCr(h - 1 + w - 1 - (row - 1 + b), w - 1 - b); // assuming after the moves which led to 'first', we do a R, and then any permutation :)

        ans += (first * second);
        ans %= mod;
    }

    cout << ans << endl;
}

void suraj2()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    int ans = 0;
    const int mod = 1e9 + 7;

    for (int row = 1; row <= h - a; row++)
    {
        int first = nCr(row - 1 + b - 1, b - 1);
        int second = nCr((h - 1 + w - 1) - ((row - 1) + (b)), ((w - 1) - (b))); // assuming after the moves which led to 'first', we do a R, and then any permutation :)
        ans += ((first * second));
        ans %= mod;
    }

    cout << ans << endl;
}
