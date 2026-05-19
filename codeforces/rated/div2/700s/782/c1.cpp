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

void suraj()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> positions(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> positions[i];
    }
    // note that making capital = positions[i] => making each position from 1 to i, as the capital one by one :)

    // case 1. capital = 0 always

    // case 2.  capital = positions[i], which will cost a*(positions[i]);

    vector<int> ps(n + 1, 0);
    ps[0] = 0;
    ps[1] = positions[1];
    for (int i = 2; i <= n; i++)
        ps[i] = ps[i - 1] + positions[i];

    vector<int> costB(n + 1, 0); // costB[i] = if i is the last capital, then total cost of conquering till the nth city :)
    // note that we have not multiplied this by b yet :)
    costB[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        costB[i] = costB[i + 1] + (n - i) * (positions[i + 1] - positions[i]);
    }

    // case 1
    int ans1 = b * costB[0];

    // case 2
    int ans2 = 0;
    int minAns2 = 1e14;
    for (int i = 1; i <= n; i++)
    {
        // final capital location = positions[i]
        int costCapital = a * positions[i];
        int costConquerAfterCapital = b * costB[i];
        int costConquerBeforeCapital = b * positions[i];
        ans2 = costCapital + costConquerAfterCapital + costConquerBeforeCapital;
        minAns2 = min(minAns2, ans2);
    }

    cout << min(ans1, minAns2) << endl;
}
