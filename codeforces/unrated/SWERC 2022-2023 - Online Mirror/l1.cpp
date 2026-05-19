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

bool solve(int na, int nb, int cntSignLess, int cntSignMore)
{
    // debug(cntSignLess);
    // debug(cntSignMore);
    if (cntSignLess == cntSignMore)
        return true;

    // swap cntSignLess and cntSignMore, lower is cntSignLess
    if (cntSignLess > cntSignMore)
    {
        swap(cntSignLess, cntSignMore);
    }
    // now cntSignLess is the smaller one

    if (cntSignMore < na || cntSignLess < nb)
    {
        // debug("Not enough signs");
        return false;
    }
    else
    {
        // debug("Enough signs");
        cntSignMore -= na;
        cntSignLess -= nb;
        return solve(na, nb, cntSignLess, cntSignMore);
    }
}

void suraj()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntSignLess = 0, cntSignMore = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            cntSignLess++;
        }
        else if (s[i] == '-')
        {
            cntSignMore++;
        }
    }
    if (cntSignLess > cntSignMore)
    {
        swap(cntSignLess, cntSignMore);
    }
    // debug(cntSignLess);
    // debug(cntSignMore);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        // swap such that a is the smaaaeb one
        if (a > b)
            swap(a, b);
        int lcm = a * b / __gcd(a, b);
        int na = lcm / a;
        int nb = lcm / b;

        // debug(a);
        // debug(b);
        // debug(na);
        // debug(nb);

        bool ans = solve(na, nb, cntSignLess, cntSignMore);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
