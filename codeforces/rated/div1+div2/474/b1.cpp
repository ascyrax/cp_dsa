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

    // cin>>t;

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

    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<int> diffs(n);
    for (int i = 0; i < n; i++)
    {
        diffs[i] = abs(a[i] - b[i]);
    }
    debug(diffs);
    sort(diffs.rbegin(), diffs.rend());
    debug(diffs);

    vector<int> temp; // difference between the sorted diffs' elements
    for (int i = 1; i <= n - 1; i++)
    {
        int delta = diffs[i - 1] - diffs[i];
        temp.push_back(delta * i);
    }
    temp.push_back((diffs[n - 1] - 0) * n);
    debug(temp);
    vector<int> ps(n, 0);
    ps[0] = temp[0];
    for (int i = 1; i <= n - 1; i++)
        ps[i] = ps[i - 1] + temp[i];
    debug(ps);

    int index = upper_bound(ps.begin(), ps.end(), k1 + k2) - ps.begin();
    // int carry = ps[index] - k1 - k2;
    
    debug(index);
    int val = diffs[index];
    if (index >= n)
        val = 0;

    int kLeft = k1 + k2 - (index - 1 >= 0 ? ps[index - 1] : 0);
    debug(val);
    debug(kLeft);
    int q = kLeft / (index + 1);
    int r = kLeft % (index + 1);
    debug(q);
    debug(r);
    for (int i = 0; i < r; i++)
        diffs[i] = val - q;
    debug(diffs);
    for (int i = r; i < index; i++)
        diffs[i] = val - q + 1;
    debug(diffs);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (diffs[i] * diffs[i]);

    cout << ans << endl;
}
