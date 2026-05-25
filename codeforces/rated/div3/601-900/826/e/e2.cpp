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
int n;
vector<int> b;
map<pair<int, int>, bool> solved;
void print()
{
    debug("print");
    for (auto el : solved)
    {
        int l = el.first.first;
        int r = el.first.second;
        bool solved = el.second;

        cout << l << " " << r << " " << solved << endl;
    }
}
bool solve(int l, int r)
{
    // debug(l);
    // debug(r);
    // print();
    // cout << solved[{l, r}] << endl;
    if (solved[{l, r}])
        return solved[{l, r}];
    if (l < 1 || l > n || r < 1 || r > n)
        return false;
    int len = r - l + 1;
    int valL = b[l];
    int valR = b[r];
    // debug(len);
    // debug(valL);
    // debug(valR);

    if (valL == len - 1 || valR == len - 1)
    {
        // solve(l + 1, r);
        solved[{l, r}] = true;
        return true;
    }

    if (solve(l + valL + 1, r))
    {
        solved[{l, r}] = true;
        return true;
    }
    if (solve(l, r - valR - 1))
    {
        solved[{l, r}] = true;
        return true;
    }

    for (int i = l; i <= r; i++)
    {
        bool result1 = false; //, result2 = false;
        int valI = b[i];
        int len = i - l + 1;
        if (len - 1 == valI)
        {
            result1 = solve(i + 1, r);
            // result2 = solve()
            // solved[{i + 1, r}] = result;
        }
        if (result1) // && result2)
        {
            // solved[{l, i}] = true;
            solved[{l, r}] = true;
            return true;
        }
    }

    // for (int i = r; i >= l; i--)
    // {
    //     int valI = b[i];
    //     int len = r - i + 1;
    //     if (len - 1 == valI)
    //     {
    //         result = solve(l, i - 1);
    //     }
    //     if (result)
    //     {
    //         solved[{l, r}] = true;
    //         return true;
    //     }
    // }
    // debug("false");
    solved[{l, r}] = false;
    return false;
}

void suraj()
{
    cin >> n;
    b = vector<int>(n + 1, 0);
    solved.clear();

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    if (solve(1, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // print();
}
