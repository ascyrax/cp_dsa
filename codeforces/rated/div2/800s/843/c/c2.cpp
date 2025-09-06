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

    cin >> t;

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

void suraj()
{
    int n, x;
    cin >> n >> x;

    if (x > n)
        cout << -1 << endl;
    else if (x == n)
        cout << n << endl;
    else
    {
        // go from left bits to right bits

        // if n has bit on, but x has it off, then => all bits after this in x must be off :)
        // if no, => ans = -1
        // else, ans = modify (n)
        // modify does this:
        // keep the bits to the left of this bit same, and turn the bit just to the left of this to 1 :)

        // go from left to right iterating over each bit of n :)
        int ans = 0;
        for (int i = 63; i >= 0; i--)
        {
            int nbit = (n >> i) & 1;
            int xbit = (x >> i) & 1;

            if (nbit == 1 && xbit == 0)
            {
                for (int j = i; j >= 0; j--)
                {
                    int bit = (x >> j) & 1;
                    // debug(bit);
                    if (bit == 1)
                    {
                        ans = -1;
                        cout << ans << endl;
                        return;
                    }
                }

                ans = n;
                ans = ans >> (i + 1);
                ans = ans << (i + 1);
                ans = ans | (1LL << (i + 1));

                // ans = n >> i;
                // ans = ans >> 1;
                // ans = ans | 1;
                // ans = ans << (i + 1);

                if (ans >= n)
                    cout << ans << endl;
                else
                {
                    // this case will take place when the bit just to the left of the current bit is already 1 in n
                    // hence the m we just produces (which is ans) is less than n
                    cout << -1 << endl;
                }
                return;
            }
            else if (nbit == 0 && xbit == 1)
            {
                cout << -1 << endl;
                return;
            }
        }
        // cout << ans << endl;
    }
}
