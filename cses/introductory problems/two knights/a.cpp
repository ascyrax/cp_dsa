// @author: ascyrax

#include <bits/stdc++.h>

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

void _print(int t)
{
    cerr << t;
}
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

    // cin >> t;

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
    vector<int> ans(n + 1);
    ans[1] = 0;
    ans[2] = 6;
    ans[3] = 28;
    ans[4] = 96;
    ans[5] = 252;
    ans[6] = 550;
    ans[7] = 1056;
    ans[8] = 1848;
    for (int i = 9; i <= n; i++)
    {
        // debug(i);
        // both knight inside the (n-1)*(n-1)
        ans[i] = ans[i - 1];
        // both knights in the newly added (nth row & nth col)
        ans[i] += ((i + i - 1) * (i + i - 1 - 1)) / 2;
        ans[i] -= 2;
        // one knight in the newly added row/col and other in the (n-1)*(n-1) grid
        ans[i] += (i - 1) * (i - 1) * (i + i - 1);
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                ans[i] -= (2 * 2);
            if (j == 2)
                ans[i] -= (3 * 2);
            if (j >= 3 && j <= i - 3)
                ans[i] -= (4 * 2);
            if (j == i - 2)
                ans[i] -= (3 * 2);
            if (j == i - 1)
                ans[i] -= (2 * 2);
            if (j == i)
                ans[i] -= 2;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}
