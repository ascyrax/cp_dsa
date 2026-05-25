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
    vector<int> temp;
    int i = 0;
    while (i < n)
    {
        debug(i);
        if (v[i] == 0)
        {
            if (temp.empty())
            {
                i++;
                continue;
            }
            // populate ranges
            int l = temp[0];
            int r = temp.back();
            ranges.push_back({l, r});
            // clear temp
            temp.clear();
        }
        else
            temp.push_back(i);
        i++;
    }
    debug(i);
    debug(temp);
    if (temp.size())
    {
        int l = temp[0];
        int r = temp.back();
        debug(l);
        debug(r);
        ranges.push_back({l, r});
    }

    debug(ranges);
    map<pair<int, int>, int> mp;
    for (auto el : ranges)
    {
        int prod = 1;
        int l = el.first;
        int r = el.second;
        for (int i = l; i <= r; i++)
            prod *= v[i];

        if (prod > 0)
        {
            mp[{l, r}] = {prod};
            continue;
        }

        // prod < 0
        // l to r
        int prodLeft = 1;
        int iLeft = l;
        for (int i = l; i <= r; i++)
        {
            prodLeft *= v[i];
            if (v[i] < 0)
            {
                // mp[{l, r}] = {prod / prodLeft, i};
                iLeft = i + 1;
                break;
            }
        }

        // if (iLeft > r)
        // {
        //     // we have sth like
        //     // 1 2 1 -2
        //     mp[{l, r - 1}] = prod / v[r];
        //     continue;
        // }
        // // what about this case: -1

        // r to l
        int prodRight = 1;
        int iRight = r;
        for (int i = r; i >= l; i--)
        {
            prodRight *= v[i];
            if (v[i] < 0)
            {
                iRight = i - 1;
                break;
            }
        }
        // if (iRight < l)
        // {
        //     // we have sth like
        //     // -1 2 1 1
        //     mp[{l + 1, r}] = prod / v[l];
        //     continue;
        // }
        // // what about cases like these : -2
        debug(prodLeft);
        debug(prodRight);

        if (abs(prodLeft) < abs(prodRight))
        {
            prod /= prodLeft;
            mp[{iLeft, r}] = {prod};
        }
        else if (abs(prodLeft) > abs(prodRight))
        {
            prod /= prodRight;
            mp[{l, iRight}] = {prod};
        }
        else
        { // for cases like these : 1 2 -1 2, where prodLeft & prodRight are equal
            prod /= prodLeft;
            mp[{iLeft, r}] = prod;
        }
    }

    int ans = 1;
    int left = n, right = 0;
    debug(mp);
    for (auto el : mp)
    {
        int l = el.first.first;
        int r = el.first.second;
        if (l > r)
            continue;
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
