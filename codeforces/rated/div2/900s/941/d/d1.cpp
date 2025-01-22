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
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    // ans.push_back(0);
    int base = 1;
    for (int i = 0; i < 22; i++)
    {
        ans.push_back(base);
        base *= 2;
    }

    //  if k belongs to ans
    auto it = lower_bound(ans.begin(), ans.end(), k);
    if (*it == k)
    {
        int val = *it;
        ans.erase(it);
        val++;
        ans.push_back(val);
        ans.push_back(val);
        if(val == 2)ans.push_back(3);
    }
    else
    {
        --it;
        int largestTwoBeforeK = *it; // largest power of 2 before k
        // ans.erase(it);
        int mxSum = largestTwoBeforeK - 1; // max sum possible if we take combinations of all powers of 2 before this largestTwoBeforeK
        int diffK = k - mxSum;
        int left = diffK - 1; // this will make sequence sum from (1) to  (k-1) possible
        int right = k + 1; // this will make sequence sum from (k+1) to (next power of two - 1) possible
        *it = left;
        ans.push_back(right);

        // since we don't have k, (next power of two + k) is not possible
        ans.push_back(largestTwoBeforeK * 2 + k);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int el : ans)
        cout << el << " ";
    cout << endl;
}
