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

void suraj()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 2 to the power 0 to 2 to the power 29 exists
    vector<int> bitCnt(30, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (a[i] & (1 << j))
                bitCnt[j]++;
        }
    }

    // find xor of all bits, if its 0 => answer is yes
    int xorVal = 0;
    for (int i = 0; i < n; i++)
        xorVal = xorVal ^ a[i];
    if (xorVal == 0)
        cout << "YES" << endl;

    // xorVal = 0 suggests that the final equal elements are even in number
    // and xorVal != 0 suggests that the if the ans exists, then the final equal elements are odd in number, and the final element is xorVal itself

    // also, if any bit is set odd no of times, then the final ans must contain odd no of elements (with the same bit set),
    // and, also, this final ans must not contain any bit that was set even no of times :) cz all the elements are equal.

    // if xor is not 0, then all the elements must be equal to the end xorVal :) and they must be odd number of such elements
    vector<int> badElements, goodElements;
    for (int i = 0; i < n; i++)
    {
        int curEl = a[i];
        // if a bit is not set in xorVal, but it is set in curEl, then its a bad bit, and the curEl is a bad element
        bool isBadElement = false;
        for (int j = 0; j < 30; j++)
        {
            if ((xorVal & (1 << j)) == 0 && (curEl & (1 << j)) != 0)
            {
                isBadElement = true;
                break;
            }
        }
        if (isBadElement)
            badElements.push_back(curEl);
        else
            goodElements.push_back(curEl);
    }

    int xorBadElements = 0;
    for (int i = 0; i < badElements.size(); i++)
        xorBadElements = xorBadElements ^ badElements[i];

    // check if xorBadElements contain any bad bit, if it does, then answer is no
    for (int j = 0; j < 30; j++)
    {
        if ((xorBadElements & (1 << j)) != 0 && (xorVal & (1 << j)) == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}
