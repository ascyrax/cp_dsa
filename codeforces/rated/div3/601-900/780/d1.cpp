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
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    vector<pair<int, int>> ranges;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            r = i - 1;
            if (l <= r)
            {
                ranges.push_back(make_pair(l, r));
            }
            l = i + 1;
        }
    }
    r = n - 1;
    if (l <= r)
        ranges.push_back({l, r});

    map<pair<int, int>, int> mp;
    for (auto el : ranges)
    {
        int cntNeg = 0;
        int prod = 1;
        l = el.first;
        r = el.second;
        for (int i = l; i <= r; i++)
        {
            prod *= v[i];
            if (v[i] < 0)
                cntNeg++;
        }
        if (prod > 0)
        {
            mp[{l, r}] = {prod};
            continue;
        }

        // prod < 0
        // l to r
        int divideByLeft = 1;
        int iLeft = l;
        for (int i = l; i <= r; i++)
        {
            divideByLeft *= v[i];
            if (v[i] < 0)
            {
                // mp[{l, r}] = {prod / divideByLeft, i};
                iLeft = i + 1;
                break;
            }
        }
        // r to l
        int divideByRight = 1;
        int iRight = r;
        for (int i = r; i >= l; i--)
        {
            divideByRight *= v[i];
            if (v[i] < 0)
            {
                iRight = i - 1;
                break;
            }
        }
        if (abs(divideByLeft) < abs(divideByRight))
        {
            prod /= divideByLeft;
            mp[{iLeft, r}] = {prod};
        }
        else
        {
            prod /= divideByRight;
            mp[{l, iRight}] = {prod};
        }
    }

    int ans = 1;
    int left = n, right = 0;
    // debug(mp);
    for (auto el : mp)
    {
        int l = el.first.first;
        int r = el.first.second;
        int prod = el.second;

        if (prod > ans)
        {
            ans = prod;
            left = l;
            // debug(l);
            // debug(r);
            right = n - r - 1;
        }
    }
    // debug(ans);
    cout << left << " " << right << endl;
}
