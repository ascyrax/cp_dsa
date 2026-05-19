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
    string s;
    cin >> s;

    int len = s.size();

    // 4 12 24 32 44
    int ans = 0;
    int cnt4 = 0;
    for (char c : s)
    {
        if (c == '4')
        {
            cnt4++;
        }
    }
    ans += cnt4;

    // 12 32
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '3')
            s[i] = '1';
    }

    // 12
    int leftmost1 = len;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
        {
            leftmost1 = i;
            break;
        }
    }

    int rightmost2 = -1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '2')
        {
            rightmost2 = i;
            break;
        }
    }
    // debug(leftmost1);
    // debug(leftmost3);
    // int cnt1 = 0, cnt2 = 0;
    vector<int> v1, v2;

    vector<char> s2;
    for (int i = leftmost1; i <= rightmost2; i++)
    {
        if (s[i] == '1' || s[i] == '2')
            s2.push_back(s[i]);
    }
    debug(s2);
    len = s2.size();
    int cnt2 = 0;
    vector<int> ps2(len);
    for (int i = len - 1; i >= 0; i--)
    {
        if (s2[i] == '2')
            cnt2++;

        ps2[i] = cnt2;
    }
    int cost = len;
    int cnt1 = 0;
    for (int i = 0; i < len; i++)
    {
        cost = min(cost, ps2[i] + cnt1);
        if (s2[i] == '1')
        {
            // if this is the ans case,
            cnt1++;
        }
    }
    cost = min(cost, 0 + cnt1);

    cout << ans + cost << endl;
}
