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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    vector<pair<int, int>> dp(n, pair<int, int>());
    dp[0].first = 0; // min penalty till now, if cur el goes to 0 (is s).
    dp[0].second = 0;

    vector<pair<int, int>> lastElIfCurGoesTo0(n, pair<int, int>());
    lastElIfCurGoesTo0[0] = make_pair(v[0], INF);
    vector<pair<int, int>> lastElIfCurGoesTo1(n, pair<int, int>());
    lastElIfCurGoesTo1[0] = make_pair(INF, v[0]);

    // debug(dp);
    // debug(lastElIfCurGoesTo0);
    // debug(lastElIfCurGoesTo1);
    for (int i = 1; i < n; i++)
    {
        int el = v[i];
        int minPenIfprevGoesTo0 = dp[i - 1].first;
        int minPenIfprevGoesTo1 = dp[i - 1].second;

        // if el goes to 0
        int val1 = dp[i - 1].first + (lastElIfCurGoesTo0[i - 1].first < v[i]);
        int val2 = dp[i - 1].second + (lastElIfCurGoesTo1[i - 1].first < v[i]);
        // debug(val1);
        // debug(val2);
        if (val1 == val2)
        {
            int a = lastElIfCurGoesTo0[i - 1].first;
            int b = lastElIfCurGoesTo0[i - 1].second;
            int c = lastElIfCurGoesTo1[i - 1].first;
            int d = lastElIfCurGoesTo1[i - 1].second;

            if (b > d)
                val2++;
            else
                val1++;
        }

        if (val1 < val2)
        {
            dp[i].first = val1;
            lastElIfCurGoesTo0[i].first = el;
            lastElIfCurGoesTo0[i].second = lastElIfCurGoesTo0[i - 1].second;
        }
        else if (val2 < val1)
        {
            dp[i].first = val2;
            lastElIfCurGoesTo0[i].first = el;
            lastElIfCurGoesTo0[i].second = lastElIfCurGoesTo1[i - 1].second;
        }

        // if el goes to 1
        val1 = dp[i - 1].first + (lastElIfCurGoesTo0[i - 1].second < el);
        val2 = dp[i - 1].second + (lastElIfCurGoesTo1[i - 1].second < el);
        // debug(val1);
        // debug(val2);

        if (val1 == val2)
        {
            int a = lastElIfCurGoesTo0[i - 1].first;
            int b = lastElIfCurGoesTo0[i - 1].second;
            int c = lastElIfCurGoesTo1[i - 1].first;
            int d = lastElIfCurGoesTo1[i - 1].second;

            if (a > c)
                val2++;
            else
                val1++;
        }

        if (val1 < val2)
        {
            dp[i].second = val1;
            lastElIfCurGoesTo1[i].second = el;
            lastElIfCurGoesTo1[i].first = lastElIfCurGoesTo0[i - 1].first;
        }
        else if (val2 < val1)
        {
            dp[i].second = val2;
            lastElIfCurGoesTo1[i].second = el;
            lastElIfCurGoesTo1[i].first = lastElIfCurGoesTo1[i - 1].first;
        }
        // debug(dp);
        // debug(lastElIfCurGoesTo0);
        // debug(lastElIfCurGoesTo1);
    }

    cout << min(dp[n - 1].first, dp[n - 1].second) << endl;
}
