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

bool check(int mid, int n, int m, vector<pair<int, int>> &vm, vector<int> &vx)
{
    vector<int> v(n, 0);
    for (int i = 0; i <= mid; i++)
    {
        int index = vx[i];
        v[index] = 1;
    }
    vector<int> ps(n, 0);
    ps[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        ps[i] = v[i] + ps[i - 1];
    }
    // debug(ps);
    for (int i = 0; i < m; i++)
    {
        int segLeft = vm[i].first;
        int segRight = vm[i].second;
        int segLen = segRight - segLeft + 1;
        // debug(segLeft);
        // debug(segRight);
        // debug(segLen);
        segLeft--;
        int cnt1 = 0;
        if (segLeft == -1)
            cnt1 = ps[segRight];
        else
            cnt1 = ps[segRight] - ps[segLeft];
        int cnt0 = segLen - cnt1;
        // debug(cnt1);
        // debug(cnt0);
        if (cnt1 > cnt0)
        {
            // debug("returning true");
            return true;
        }
    }
    // debug("returning false");
    return false;
}

void suraj()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> vm;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        vm.push_back(make_pair(l, r));
    }
    int q;
    cin >> q;
    vector<int> vx;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        vx.push_back(--x);
    }

    int left = 0, right = q - 1;
    int mid = 0;

    bool flag = false;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        // debug(left);
        // debug(mid);
        // debug(right);
        if (check(mid, n, m, vm, vx))
        {
            flag = true;
            right = mid;
        }
        else
        {
            flag = false;
            left = mid + 1;
            mid++; // incase loop breaks after this :) eg. left = 6, mid = 6, right = 7 :)
        }
    }
    // left = right currently
    if (flag)
        cout << mid + 1 << endl;
    else if (check(mid, n, m, vm, vx))
    {
        cout << mid + 1 << endl;
    }
    else
        cout << -1 << endl;
}
