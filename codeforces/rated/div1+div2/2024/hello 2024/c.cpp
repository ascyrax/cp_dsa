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

    // debug(v);

    vector<vector<int>> mp(n, vector<int>(6, INF)); // mp = minimum penalty
    // mp[0][0] = minimum penalty for s & t if first element goes to s
    // mp[0][1] = minimum penalty for s & t if first element goes to t
    // mp[0][2] = last element of s if 0th elmeent goes to s
    // mp[0][3] = last element of t if 0th element goes to s
    // mp[0][4] = last element of s if 0th elmeent goes to t
    // mp[0][5] = last element of t if 0th element goes to t

    mp[0][0] = 0;
    mp[0][1] = 0;
    mp[0][2] = v[0];
    mp[0][3] = INF;
    mp[0][4] = INF;
    mp[0][5] = v[0];
    for (int i = 1; i < n; i++)
    {
        // debug(i);
        mp[i][2] = v[i];
        // ith element goes to s
        mp[i][0] = min(mp[i - 1][0] + (mp[i - 1][2] < v[i]), mp[i - 1][1] + (mp[i - 1][4] < v[i]));
        if (mp[i - 1][0] + (mp[i - 1][2] < v[i]) < mp[i - 1][1] + (mp[i - 1][4] < v[i]))
            mp[i][3] = mp[i - 1][3];
        else if (mp[i - 1][0] + (mp[i - 1][2] < v[i]) < mp[i - 1][1] + (mp[i - 1][4] < v[i]))
            mp[i][3] = mp[i - 1][5];
        else // if both are equal
        {
            
        }

        // ith element goes to t
        mp[i][5] = v[i];
        mp[i][1] = min(mp[i - 1][0] + (mp[i - 1][3] < v[i]), mp[i - 1][1] + (mp[i - 1][5] < v[i]));
        if (mp[i - 1][0] + (mp[i - 1][3] < v[i]) < mp[i - 1][1] + (mp[i - 1][5] < v[i]))
            mp[i][4] = mp[i - 1][2];
        else
            mp[i][4] = mp[i - 1][4];
    }

    int ans = min(mp[n - 1][0], mp[n - 1][1]);
    cout << ans << endl;
}
