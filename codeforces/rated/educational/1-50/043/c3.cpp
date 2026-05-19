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

void suraj()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> ranges;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        ranges.push_back(make_pair(l, make_pair(r, i)));
    }
    sort(ranges.begin(), ranges.end());
    // set<int> st;
    map<int, int> indexOf;

    // int l0 = ranges[0].first;
    int r0 = ranges[0].second.first;
    int ind0 = ranges[0].second.second;

    int mxR = r0;
    indexOf[mxR] = ind0;
    for (int i = 1; i < n; i++)
    {
        // int l = ranges[i].first;
        int r = ranges[i].second.first;
        int index = ranges[i].second.second;
        if (r <= mxR)
        {
            cout << index << " " << indexOf[mxR] << endl;
            return;
        }
        else
        {
            mxR = r;
            indexOf[mxR] = index;
        }
        // indexOf[r] = index;
        // mxR = max(r, mxR);
        // else
        //     mxR = r;
    }
    int prevL = ranges[0].first;
    int prevR = ranges[0].second.first;
    int prevIndex = ranges[0].second.second;
    for (int i = 1; i < n; i++)
    {
        int l = ranges[i].first;
        int r = ranges[i].second.first;
        int index = ranges[i].second.second;
        if (l == prevL)
        {
            if (r == prevR)
                cout << index << " " << prevIndex << endl;
            else if (r < prevR)
                cout << index << " " << prevIndex << endl;
            else if (r > prevR)
                cout << prevIndex << " " << index << endl;
            return;
        }
        prevL = l;
        prevR = r;
        prevIndex = index;
    }
    cout << -1 << " " << -1 << endl;
}
