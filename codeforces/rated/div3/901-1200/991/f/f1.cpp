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

/*
To efficiently find the GCD of all elements in a subarray [l, r] for multiple queries, you can use a Segment Tree where each node stores the GCD of its segment. This allows O(log n) query time after O(n) preprocessing.

Here's a simple Segment Tree for GCD:
*/

struct SegmentTree
{
    int n;
    vector<int> tree;

    SegmentTree(const vector<int> &a)
    {
        n = a.size();
        // debug(n);
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
        // debug(tree);
    }

    void build(const vector<int> &a, int v, int tl, int tr)
    {
        if (tl > tr)
        {
            // debug(tl);
            // debug(tr);
            tree[v] = tree[v];
        }
        else if (tl == tr)
        {
            tree[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = __gcd(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        // debug("");
        // debug(v);
        // debug(tl);
        // debug(tr);
        // debug(l);
        // debug(r);
        if (l > r)
            return 0;
        // if (l==r)return
        if (l == tl && r == tr)
        {
            // debug("Returning tree[v]");
            // debug(tree[v]);
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return __gcd(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    int range_gcd(int l, int r)
    {
        // for (int i : tree)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // debug(l);
        // debug(r);
        return query(1, 0, n - 1, l, r);
    }
};

// 1
// 5 1
// 5 14 2 6 3
// 4 5

/*
Usage:
SegmentTree st(a);
int ans = st.range_gcd(l, r); // 0-based indices
*/

void suraj()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = abs(a[i] - a[i + 1]);
    }

    debug(diff);
    SegmentTree st(diff);
    // debug("hi");
    vector<int> ps(n - 1);
    if (diff.size() > 0)
    {

        ps[0] = diff[0];
        // debug(ps);
        for (int i = 1; i < n - 1; i++)
        {
            ps[i] = ps[i - 1] + diff[i];
        }
    }
    debug(ps);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = 0;
        if (l == r)
        {
            ans = 0;
        }
        else
        {
            int sum = ps[r - 1] - 0;
            if (l - 1 >= 0)
                sum -= ps[l - 1];
            if (sum != 0)
            {
                ans = st.range_gcd(l, r - 1); // l to r-1 in diff array
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}
