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
vector<int> a;
int n;
map<pair<int, int>, int> converted;
int convert(int a, int b)
{
    // debug(a);
    // debug(b);
    int cnt = 0;
    while (b - a < 2)
    {
        if (a == b)
            break;
        if (a & 1)
        {
            a++;
            cnt++;
        }
        else
        {
            a /= 2;
            cnt++;
        }
    }
    if (a == b)
        return cnt;
    else
        return -1;
}

int solve(int finalVal)
{
    int cntOps = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        cnt = convert(a[i], finalVal);
        // if (converted.find({a[i], finalVal}) != converted.end())
        //     cnt = converted[{a[i], finalVal}];
        // else
        // {
        //     cnt = convert(a[i], finalVal);
        //     converted[{a[i], finalVal}] = cnt;
        // }
        // debug(cnt);
        if (cnt < 0)
            return -1;
        else
            cntOps += cnt;
    }
    return cntOps;
}

void suraj()
{
    converted.clear();
    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    debug(a);

    set<int> candidates;
    int mnVal = a[0];
    candidates.insert(mnVal);
    candidates.insert(1);
    candidates.insert(2); // even when a[0] = 1, 2 is a probable candidate :)
    while (mnVal > 1)
    {
        if (mnVal & 1)
        {
            mnVal++;
        }
        else
        {
            mnVal /= 2;
        }
        candidates.insert(mnVal);
    }
    // sort(candidates.begin(), candidates.end());
    debug(candidates);

    int mnOpCnt = 1e18;
    for (int el: candidates)
    {
        int val = solve(el);
        debug(val);
        if (val >= 0)
        {
            mnOpCnt = min(mnOpCnt, val);
        }
        else if (val < 0)
        {     // val = -1
            ; // do nothing
        }
    }
    cout << mnOpCnt << endl;
}
