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

bool check(int len, vector<int> &bitCnt, vector<int> &a)
{
    // all bitcnt value less than len must be reduced to 0, and
    // all bitcnt value greater than or equal to len must be reduced to len

    vector<int> modifiedArr = a;

    vector<int> lowerBits, higherbits;
    for (int i = 0; i < bitCnt.size(); i++)
    {
        if (bitCnt[i] < len)
        {
            if (bitCnt[i] % 2 == 1)
                return false;
        }

        if (bitCnt[i] < len)
            lowerBits.push_back(i);
        else
            higherbits.push_back(i);
    }

    // find all the elements having the lower bits
    int xorVal = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int currentEl = a[i];
        for (int j = 0; j < lowerBits.size(); j++)
        {
            if (currentEl & (1 << j))
            {
                xorVal = xorVal ^ currentEl;
                break;
            }
        }
    }


    return true;
}

void suraj()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
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

    for (int i = 2; i <= n; i++)
    {
        // i = no of equal elements in the final array :)

        // all bitcnt value less than i must be reduced to 0, and
        // all bitcnt value greater than or equal to i must be reduced to i

        if (check(i, bitCnt, a))
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}
