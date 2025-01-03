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

void reconstructPairs(vector<int> v)
{
}

void suraj()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> bitsA[32]; // bitsA[3] contains all the indices i for which a[i] is having the third bit on :) is a[i] & 8 = 1;
    for (int i = 0; i < 32; i++)
    {
        bitsA[i] = vector<int>();
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int curVal = 1;
        int bitIndex = 0;
        while (curVal <= a[i])
        {
            if (a[i] & curVal)
            {
                bitsA[bitIndex].push_back(i);
            }
            bitIndex++;
            curVal *= 2;
        }
    }

    // for x
    vector<int> bitsx(32); // this contains all the bits which are set to 1 for x
    int curVal = 1;
    int bitIndex = 0;
    while (curVal <= x)
    {
        if (x & curVal)
        {
            bitsx[bitIndex] = 1;
        }
        bitIndex++;
        curVal *= 2;
    }

    // two cases
    // a. <x
    // b. =x
    // else -1

    for (int i = 32; i >= 0; i--)
    {
        // for x
        int curBitX = bitsx[i];

        // for a
        int cntCurBitA = bitsA[i].size();
        vector<int> curBitIndicesA = bitsA[i];

        if (curBitX == 0)
        {
            if (cntCurBitA % 2 == 1) // > x
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                // pair into two
                reconstructPairs(curBitIndicesA);
            }
        }
        else if (curBitX == 1)
        {
            if (cntCurBitA % 2 == 1)
            {
                // do nothing
            }
            else
            {
                // do nothing
            }
        }
    }
}
