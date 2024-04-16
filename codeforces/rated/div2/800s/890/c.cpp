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

bool isPossible(int mid, int index, vector<int> &v, vector<int> &maxPossible, int k)
{
    int n = v.size();
    int req = 0;
    int reqValAtI = mid;
    // debug(reqValAtI);
    for (int i = index; i < n; i++)
    {
        if (v[i] >= reqValAtI)
            break;
        int diff = reqValAtI - v[i];
        diff = max(0ll, diff);
        req += diff;
        reqValAtI--;
        // req += (mid - v[i]);
    }
    // debug(req);
    return req <= k;
}
void suraj()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int ans = 0;

    vector<int> maxPossible(n, 0);
    maxPossible[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxPossible[i] = max(v[i], maxPossible[i + 1] + 1);
    }

    // debug(maxPossible);

    for (int i = 0; i < n; i++)
    {
        // debug(i);
        int mn = v[i];
        int mx = maxPossible[i];

        int mid;
        while (mn < mx)
        {
            mid = mn + (mx - mn) / 2;
            // debug(mn);
            // debug(mid);
            // debug(mx);
            if (isPossible(mid, i, v, maxPossible, k))
            {
                if (mn == mid)
                { // ie. mn = mx - 1
                    if (isPossible(mx, i, v, maxPossible, k))
                    {
                        // debug("possible :)");
                        mn = mx;
                    }
                    else
                        mx = mn;
                }
                else
                    mn = mid;
            }
            else
            {
                mx = mid - 1;
            }
        }
        ans = max(ans, mn);
        // debug(ans);
    }

    cout << ans << endl;
}
