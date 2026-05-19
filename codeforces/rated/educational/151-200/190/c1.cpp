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

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int cnt1 = 0, cnt2AndAbove = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            cnt1++;
        else if (a[i] > 1)
        {
            int q = a[i] / 2;
            // int r = a[i] % 2;
            cnt2AndAbove++;
            temp += q - 1;
        }
    }

    // check for 0
    if (n == 1)
    {
        if (a[0] < 3)
        {
            cout << 0 << endl;
            return;
        }
    }
    else if (n > 1)
    {

        if (cnt2AndAbove == 0) // => cnt1 must be >= 2
        {
            cout << 0 << endl;
            return;
        }
        else if (cnt2AndAbove == 1) // => cnt1 must be >=1
        {
            ;
        }
    }
    debug(cnt2AndAbove);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 1)
            ans += a[i];
    }
    if (cnt2AndAbove == 1)
        temp++;
    if (cnt1 < temp)
    {
        ans += cnt1;
    }
    else if (cnt1 >= temp)
    {
        ans += temp;
    }
    cout << ans << endl;
}
