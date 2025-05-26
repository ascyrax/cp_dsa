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

// int modExp(int base, int exp, int mod)
// {
//     int result = 1;
//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//         { // If the current power is odd
//             result = (1LL * result * base) % mod;
//         }
//         base = (1LL * base * base) % mod; // Square the base
//         exp /= 2;                         // Halve the exponent
//     }
//     return result;
// }

// Function to compute gcd and extended coefficients
int extendedGCD(int a, int m, int &x, int &y)
{
    if (m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(m, a % m, x1, y1);
    x = y1;
    y = x1 - (a / m) * y1;
    return gcd;
}

// Function to get multiplicative inverse of a modulo m
int modInverse(int a, int m)
{
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1)
    {
        // Inverse doesn't exist
        return -1;
    }
    // Ensure x is positive
    return (x % m + m) % m;
}

// Fast exponentiation function to compute a^p mod m
long long modExp(long long a, long long p, long long m)
{
    long long result = 1;
    while (p > 0)
    {
        if (p & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return result;
}

// Using Fermat’s Little Theorem to compute the inverse
long long modInverseFermat(long long a, long long m)
{
    return modExp(a, m - 2, m);
}

void suraj()
{
    int n;
    cin >> n;
    // n = 300000;
    vector<int> edges(n);
    for (int &i : edges)
    {
        cin >> i;
        // i = 1;
    }

    int cntAllDistinct = 0, cntAllSame = 0, cntTwoSame = 0;

    for (int i = 0; i < n; i += 3)
    {
        int e1 = edges[i];
        int e2 = edges[i + 1];
        int e3 = edges[i + 2];

        if ((e1 == e2) && (e2 == e3))
        {
            cntAllSame++;
        }
        else if ((e1 == e2) || (e2 == e3) || (e1 == e3))
        {
            if ((e1 == e2) && (e3 > e1))
            {
                cntTwoSame++;
            }
            else if ((e2 == e3) && (e1 > e2))
            {
                cntTwoSame++;
            }
            else if ((e1 == e3) && (e2 > e1))
            {
                cntTwoSame++;
            }
        }
        else
        {
            cntAllDistinct++;
        }
    }

    // debug(cntAllDistinct);
    // debug(cntAllSame);
    // debug(cntTwoSame);

    int ans = 1;
    int mod = 998244353;

    int k = n / 6;
    // choose k from 2*k
    for (int i = 0; i < k; i++)
    {
        ans *= (2 * k - i);
        ans %= mod;
    }
    for (int i = k; i >= 1; i--)
    {
        // ans /= i;
        // ans *= modExp(i, mod - 2, mod);
        // ans %= mod;

        // ans *= modInverse(i, mod);
        // ans %= mod;

        ans *= modInverseFermat(i, mod);
        ans %= mod;
    }

    // debug(ans);

    for (int i = 0; i < cntAllSame; i++)
    {
        ans *= 3;
        ans %= mod;
    }

    for (int i = 0; i < cntTwoSame; i++)
    {
        ans *= 2;
        ans %= mod;
    }

    cout << ans << endl;
}