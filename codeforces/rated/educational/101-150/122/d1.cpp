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
vector<int> minOps;

void modify(int a, int nOps)
{
    if (a > 1e3)
        return;
    // debug(a);
    // debug(nOps);
    minOps[a] = nOps;
    for (int i = 1; i <= a; i++)
    {
        // debug(i);
        int q = a / i;
        // debug(q);
        // debug(minOps[a + q]);
        if (a + q > 1e3)
            continue;
        if (minOps[a + q] > nOps + 1)
        {
            // minOps[a + q] = nOps + 1;
            modify(a + q, nOps + 1);
        }
    }
    return;
}

void print(vector<vector<int>> dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void suraj()
{
    int n, k;
    cin >> n >> k;
    minOps = vector<int>(1e3 + 1, 1000000);
    // debug(minOps);
    minOps[0] = 0;

    vector<int> b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    // debug(b);
    // minOps[1] = 0;
    modify(1, 0);

    // debug(b);
    for (int i = 1; i <= n; i++)
    {
        // debug(b[i]);
        // debug(minOps[b[i]]);
        b[i] = minOps[b[i]];
    }

    // debug(k);
    // debug(b);
    // debug(c);

    int maxOpsPossible = 0;
    for (int i = 1; i <= n; i++)
    {
        maxOpsPossible += b[i];
    }
    int maxCoinsPossible = 0;
    for (int i = 1; i <= n; i++)
        maxCoinsPossible += c[i];

    // debug(maxOpsPossible);
    // debug(maxCoinsPossible);
    if (k >= maxOpsPossible)
    {
        cout << maxCoinsPossible << endl;
    }
    else
    {
        // do a knapsack on n * maxOpsPossible :)
        // note that this maxOpsPossible will be <= 12000, ie. 12 * 1000, where 1000 represent the max value of n :)
        // int dp[n + 1][maxOpsPossible + 1];
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(maxOpsPossible + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= maxOpsPossible; j++)
            {
                // if the ith element is chosen
                if (j - b[i] >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - b[i]] + c[i]);
                // if not chosen :)
                // for (int x = 0; x <= j; x++)
                //     dp[i][j] = max(dp[i][j], dp[i - 1][j - x]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        int ans = 0;
        for (int j = 1; j <= maxOpsPossible; j++)
        {
            ans = max(ans, dp[n][k]);
        }
        cout << ans << endl;
    }

    // now for b and c, we just gotta do the knapsack :)
    // vector<vector<int>> dp(n + 1, );
    // int dp[n + 1][2];

    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    //     dp[i][1] =
    // }
}
