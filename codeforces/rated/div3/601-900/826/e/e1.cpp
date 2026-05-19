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
map<pair<int, int>, int> mp;
vector<int> b;

bool solve(int l, int r)
{
    if (mp[make_pair(l, r)] != 0)
        return mp[make_pair(l, r)];

    if (l == r)
        return false;

    int len = r - l + 1;
    int valL = b[l];
    int valR = b[r];
    // case 1
    if (valL == len - 1)
    {
        mp[make_pair(l, r)] = 1;
        return true;
    }
    else if (valL > len - 1)
        ;
    // debug("do nothing");
    else if (valL < len - 1)
    {
        if (solve(l + valL + 1, r))
        {
            mp[make_pair(l, r)] = 1;
            return true;
        }
        else
            ;
    }

    // case 2
    if (valR == len - 1)
    {
        mp[make_pair(l, r)] = 1;
        return true;
    }
    else if (valR > len - 1)
        ;
    else if (valR < len - 1)
    {
        if (solve(l, r - valR - 1))
        {
            mp[make_pair(l, r)] = 1;
            return true;
        }
        else
            ;
    }

    // case 3
    for (int i = l; i <= r; i++)
    {
        int len = i - l + 1;
        int valI = b[i];
        if (valI == len - 1)
        {
            if (solve(i, r))
            {
                mp[make_pair(l, r)] = 1;
                return true;
            }
            else
                ;
        }
    }

    // case 4
    for (int i = r; i >= l; i--)
    {
        int len = i - l + 1;
        int valI = b[i];
        if (valI == len - 1)
        {
            if (solve(l, i))
            {
                mp[make_pair(l, r)] = 1;
                return true;
            }
            else
                ;
        }
    }

    mp[make_pair(l, r)] = -1;
    return false;
}

void suraj()
{
    mp.clear();
    cin >> n;
    b = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    // debug(mp[make_pair(1, n)]);
    if (solve(1, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
