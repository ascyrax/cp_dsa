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

int ans = 0;
vector<pair<int, int>> nextTarget;
int l1, l2, r1, r2;
vector<pair<int, int>> dpSolve; // stores {r1, r2}

void updateAns(int l1, int l2, int r1, int r2)
{
    // debug(l1);
    // debug(l2);
    // debug(r1);
    // debug(r2);
    // update ans using l1,l2,r1,r2
    // ans += ()
    for (int i = l1; i <= l2; i++)
    {
        int diff = r2 - i + 1;
        ans += diff;
    }
    return;
}
void updateAns(int l, int r)
{
    // debug(l);
    // debug(r);
    // update ans using i and nextIndex
    // ans += ()
    int diff = r - l + 1;
    ans += (diff * (diff + 1)) / 2;
    return;
}

void solve(int i)
{
    if (dpSolve[i] != make_pair(-1ll, -1ll))
    {
        r1 = dpSolve[i].first;
        r2 = dpSolve[i].second;
        return;
    }
    // 1,1 -> 2,2 and so on :)
    int nextIndex = nextTarget[i].first;
    bool areEqual = nextTarget[i].second;
    if (areEqual)
    {
        solve(nextIndex);
        dpSolve[i] = dpSolve[nextIndex];
    }
    else
    {
        r1 = i;
        r2 = nextIndex - 1;
        dpSolve[i] = make_pair(r1, r2);
    }
    return;
}
void print(map<int, pair<int, bool>> mp)
{
    for (auto it : mp)
    {
        cerr << it.first << " -> " << it.second.first << "," << it.second.second << endl;
    }
}

void suraj()
{
    int n;
    cin >> n;

    dpSolve = vector<pair<int, int>>(n + 1, make_pair(-1, -1));

    ans = 0;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    // debug(a);
    // debug(b);

    map<int, pair<int, bool>> mp; // value, {index, a[index] == b[index]}
    // mp.clear();
    for (int i = 1; i <= n + 1; i++)
    {
        mp[i] = make_pair(n + 1, false);
    }
    // debug(mp);
    // print(mp);
    nextTarget = vector<pair<int, int>>(n + 1, make_pair(-1, false));
    vector<pair<int, int>> nextIndexOf1(n + 1, make_pair(-1, false));
    // nextTarget[0] = mp[1];
    for (int i = n; i >= 1; i--)
    {
        int curA = a[i];
        int curB = b[i];
        if (curA == curB)
        {
            nextTarget[i] = mp[curA + 1];
            nextIndexOf1[i] = mp[1];
        }
        else if (curA != curB)
        {
            nextTarget[i] = mp[1];
            nextIndexOf1[i] = mp[1];
        }
        mp[curA] = make_pair(i, curA == curB);
        mp[curB] = make_pair(i, curA == curB);

        // print(mp);
        // debug(nextTarget);
    }
    // debug(mp);
    // print(mp);
    // debug(nextTarget);

    int i = 1;
    while (i <= n)
    {
        int curA = a[i];
        int curB = b[i];
        if (curA == curB)
        {
            if (curA == 1)
            {
                l1 = i;
                l2 = i;
                solve(i);
                updateAns(l1, l2, r1, r2);
                i = l2 + 1;
            }
            else
            {
                // neither curA nor curB is 1 :)
                int nextIndex1 = nextIndexOf1[i].first;
                bool areEqual1 = nextIndexOf1[i].second;
                if (areEqual1)
                {
                    l1 = i;
                    l2 = nextIndex1;
                    solve(nextIndex1);
                    updateAns(l1, l2, r1, r2);
                    i = l2 + 1;
                }
                else
                {
                    updateAns(i, nextIndex1 - 1);
                    i = nextIndex1 + 1;
                }
            }
        }
        else if (curA != curB)
        {
            if (curA == 1 || curB == 1)
            {
                i++;
                continue;
            }
            else
            {
                // neither curA nor curB is 1 :)
                int nextIndex1 = nextTarget[i].first;
                bool areEqual1 = nextTarget[i].second;
                if (areEqual1)
                {
                    l1 = i;
                    l2 = nextIndex1;
                    solve(nextIndex1);
                    updateAns(l1, l2, r1, r2);
                    i = l2 + 1;
                }
                else
                {
                    updateAns(i, nextIndex1 - 1);
                    i = nextIndex1 + 1;
                }
            }
        }
        // debug(ans);
    }

    cout << ans << endl;
}

// 1
// 3
// 1 2 1
// 1 2 2