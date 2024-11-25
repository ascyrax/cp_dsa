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

void suraj(int);

int t = 1;
signed main()
{

    fastio();

#ifndef ONLINE_JUDGE
    clock_t startTime = clock();
#endif

    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    // cout << setprecision(15) << fixed;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {

        // cout<<"Case #"<<i<<": ";

        suraj(i);
        debug("---");
    }

#ifndef ONLINE_JUDGE
    cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

    return 0;
}

int n;
int totalLower, totalUpper;
vector<int> a, b;
int nextIndex;
vector<int> visited;
int ans;
int mxIndex;
set<int> sNextIndices;

void updateNextIndex(int curIndex)
{
    // while (visited[nextIndex])
    // {
    //     if (nextIndex == 0)
    //         return;
    //     nextIndex--;
    // }
    auto itr = sNextIndices.upper_bound(curIndex);
    if (itr == sNextIndices.begin())
        return;
    --itr;
    nextIndex = *itr;
    return;
}

void dfs(int index)
{
    if (visited[index])
        return;
    visited[index] = true;
    sNextIndices.erase(index);

    if (b[index] <= index)
    {
        // accept the problem
        totalLower += a[index];
        ans = max(ans, totalLower + totalUpper);
        updateNextIndex(mxIndex);
        dfs(nextIndex);

        // never skip such problems :)
    }
    else if (b[index] > index)
    {
        // accept
        totalUpper += a[index];
        ans = max(ans, totalLower + totalUpper);
        updateNextIndex(mxIndex);
        dfs(nextIndex);

        // skip the problem only if or else its just not optimal to skip :) viz its useless to skip :)
        if (b[index] > mxIndex)
        {
            mxIndex = b[index];
            totalUpper -= a[index];
            nextIndex = mxIndex; // updated next index
            dfs(nextIndex);
        }
    }
    return;
}

void suraj(int ti)
{
    cin >> n; // input

    totalLower = 0, totalUpper = 0;
    ans = 0;
    mxIndex = 0;
    visited = vector<int>(n, 0);
    a = vector<int>(n);
    b = vector<int>(n);
    for (int i = 0; i < n; i++)
        sNextIndices.insert(i);

    // input
    for (int &i : a)
        cin >> i;
    for (int &i : b)
    {
        cin >> i;
        --i;
    }

    vector<int> ps;
    ps = vector<int>(n, 0);
    ps[0] = a[0];
    for (int i = 1; i < n; i++)
        ps[i] = a[i] + ps[i - 1];

    // two cases
    // b[i] <= i, => case lower
    // and b[i] > i => case greater

    ans = a[0];
    nextIndex = 0;
    dfs(nextIndex);

    cout << ans << endl;
}
