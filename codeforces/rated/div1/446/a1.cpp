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

    // cin >> t;

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
vector<int> a;
bool check(int len)
{
    debug(len);
    for (int i = 0; i <= n - len; i++)
    {
        int gcd = a[i];
        for (int j = i; j < i + len; j++)
        {
            gcd = __gcd(gcd, a[j]);
        }
        if (gcd == 1)
            return true;
        debug(gcd);
    }
    return false;
}

void suraj()
{
    cin >> n;
    a = vector<int>(n);
    for (int &i : a)
        cin >> i;

    int left = 1, right = n;

    if (!check(n))
    {
        cout << -1 << endl;
        return;
    }
    int mid = left + (right - left) / 2;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        // debug(left);
        // debug(mid);
        // debug(right);
        if (check(mid))
        {
            // we need min no of oprations
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    // we can be sure that left = right at this point :)

    int cnt1 = 0;
    for (int el : a)
    {
        if (el == 1)
        {
            cnt1++;
        }
    }
    int firstOne = left - 1;
    int cntOthers = n - cnt1;
    // after creating the firstOne, from the len-length adjacent elements
    if (left == 1)
        ;
    else
        cntOthers--;
    // if (cntOthers < 0)
    //     cntOthers = 0;
    // now in just one step we can convert each non1s to 1 :)
    cout << firstOne + cntOthers << endl;
}
