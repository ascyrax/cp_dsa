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
int find_gcd(int a, int b)
{
    if (a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    if (a == 0)
        return b;
    else
        return find_gcd(b % a, a);
}

int find_lcm(int a, int b)
{
    return (a * b) / find_gcd(a, b);
}

int n;
vector<int> v;
int ans;
void calc(int lcm)
{
    vector<int> temp;
    for (int i : v)
    {
        if (lcm % i == 0)
        {
            temp.push_back(i);
        }
    }
    if (temp.size() == 0)
    {
        ans = max(ans, 0ll);
        return;
    }
    int lcm2 = 1;
    for (int el : temp)
        lcm2 = find_lcm(lcm2, el);
    if (lcm2 == lcm)
        ans = max(ans, (int)temp.size());
}

void suraj()
{
    cin >> n;
    ans = 0;
    v = vector<int>(n);
    for (int &i : v)
        cin >> i;

    int lcm = v[0];
    int mx = v[0];
    for (int i : v)
        mx = max(mx, i);
    for (int i : v)
    {
        lcm = find_lcm(lcm, i);
        if (lcm > mx)
        {
            cout << n << endl;
            return;
        }
    }

    map<int, int> m;
    for (int i : v)
        m[i]++;

    if (lcm > mx)
    {
        cout << n << endl;
        return;
    }
    // else if lcm == mx
    for (int i = 1; i * i <= mx; i++)
    {
        if (mx % i == 0)
        {
            int divisor1 = i;
            int divisor2 = mx / i;

            if (m.count(divisor1))
            {
                // do nothing
            }
            else
            {
                calc(divisor1);
            }

            if (m.count(divisor2))
            {
                // do nothing
            }
            else
            {
                calc(divisor2);
            }
        }
    }
    cout << ans << endl;
}
