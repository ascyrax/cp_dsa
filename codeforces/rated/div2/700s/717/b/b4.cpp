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
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int xorAll = 0;
    for (int el : a)
    {
        xorAll ^= el;
    }

    vector<int> psLeft(n + 1, 0);
    for (int i = 1; i <= n; i++)
        psLeft[i] = psLeft[i - 1] ^ a[i];

    vector<int> psRight(n + 1, 0);
    psRight[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        psRight[i] = psRight[i + 1] ^ a[i];

    if (xorAll == 0)
    {
        // final elements cnt is even

        for (int i = 1; i <= n; i++)
        {
            int xorLeft = psLeft[i];
            int xorRight = psRight[i + 1];
            if (xorLeft == xorRight)
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
    else
    {
        // final elements cnt is odd
        int leftBoundary = 0;
        for (int i = 1; i <= n; i++)
        {
            int xorLeft = psLeft[i];
            leftBoundary = i;
            if (xorLeft == xorAll)
                break;
        }

        int rightBoundary = n + 1;
        for (int i = n; i > leftBoundary; i--)
        {
            int xorRight = psRight[i];
            rightBoundary = i;
            if (xorRight == xorAll)
                break;
        }

        int xorMid = 0;
        for (int i = leftBoundary + 1; i < rightBoundary; i++)
        {
            xorMid ^= a[i];
        }

        if (xorMid == xorAll)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
