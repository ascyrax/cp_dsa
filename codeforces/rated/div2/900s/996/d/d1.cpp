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
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> v(n);
    for (int &i : v)
    {
        cin >> i;
    }

    double curCrowPos = 0;
    double totalTime = 0;

    // first teleport :)
    totalTime += v[0] - 0;
    curCrowPos = 0 + k;

    // now the crow will always have someone to its left 
    // => (we can assume a scarecrow at a distance of k towards the left is always present)
    // => every 0.5 second, it will teleport right by 0.5 respectively :)

    for (int i = 1; i < n; i++)
    {
        int scarecrowPos = v[i];
        int diff = scarecrowPos - curCrowPos;
        int actualDiff = abs(diff) - totalTime;
        if (actualDiff <= 0)
        {
            curCrowPos += k;
        }
        else if (actualDiff > 0)
        {
            if (diff > 0)
            {
                // scarecrow is to the right of the crow
                totalTime += actualDiff / 2.0;
                curCrowPos += actualDiff / 2.0 + k;
            }
            else if (diff < 0)
            {
                // scarecrow is to the left of the crow
                if (actualDiff >= k)
                {
                    // do nothing
                    // we need to move on to the next scarecrow
                }
                else
                {
                    // this scarecrow can help teleport the crow to a further location without using any time :)
                    totalTime += 0;
                    curCrowPos += (k - actualDiff);
                }
            }
            else if (diff == 0)
            {
                // then actual diff cannot be > 0
                // => this case will never be reached
            }
        }
    }
    if (curCrowPos >= l)
        cout << (int)(totalTime * 2) << endl;
    else
    {
        totalTime += (l - curCrowPos);
        cout << (int)(totalTime * 2) << endl;
    }
}
