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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
struct DSU
{
    // vi e;
    vector<int> e;
    void init(int N) { e = vector<int>(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y)
    { // union by size
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void suraj()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    vector<vector<int>> grp1(31, vector<int>());
    vector<vector<int>> grp0(31, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int el = v[i];
        for (int base = 0; base <= 30; base++)
        {
            if (el % 2 == 1)
                grp1[base].pb(i);
            else
                grp0[base].pb(i);
            el /= 2;
        }
        // debug(grp0);
        // debug(grp1);
    }
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i <= 30; i++)
    {
        int first;
        if (grp0[i].size() > 0)
            first = grp0[i][0];
        for (auto el : grp0[i])
            dsu.unite(el, first);

        if (grp1[i].size() > 0)
            first = grp1[i][0];
        for (auto el : grp1[i])
            dsu.unite(el, first);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        debug(dsu.size(i));
        ans = max(ans, dsu.size(i));
    }
    cout << ans << endl;
}

/**
 * Description: Disjoint Set Union with path compression
 * and union by size. Add edges and test connectivity.
 * Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

/**tcT> T kruskal(int N, vector<pair<T,pi>> ed) {
    sort(all(ed));
    T ans = 0; DSU D; D.init(N); // edges that unite are in MST
    each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f;
    return ans;
}*/
