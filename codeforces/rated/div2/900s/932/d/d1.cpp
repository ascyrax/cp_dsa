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
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cntPairs = 0;

    for (int x = 0; x <= c; x++)
    {
        // debug(x);
        // y will go from x to c (inclusive both)
        int xPlusYMin = 2 * x; // assuming y = x
        int xPlusYMax = x + c; // assuming y = c
        // int yMinusXMin = 0;     // assuming y = x
        int yMinusXMax = c - x; // assuming y = c

        // debug(xPlusYMin);
        // debug(xPlusYMax);
        // debug(yMinusXMax);

        int cntCandidates = xPlusYMax - xPlusYMin + 1; // = c - x + 1
        // debug(cntCandidates);
        // discard the candidates (xPlusY & yMinusX) which:
        // lie in v
        // case 1. just the xPlusY lie in v
        // case 2. just the yMinusX lie in v
        // case 3. both xPlusY and yMinusX lie in v // handle this later together for all

        int ptr = lower_bound(v.begin(), v.end(), xPlusYMin) - v.begin();
        int cnt1 = n - ptr; // 1 => case 1
        // debug(cnt1);
        cntCandidates -= cnt1;

        ptr = upper_bound(v.begin(), v.end(), yMinusXMax) - v.begin();
        int cnt2 = ptr; // 2 => case 2
        // debug(cnt2);
        cntCandidates -= cnt2;

        // for a x,y pair: (x + y) - (y - x) = 2x = diff between the x+y and the y-x values
        cntPairs += cntCandidates;
        // debug(cntPairs);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int diff = v[j] - v[i];
            // debug(diff);
            if (diff % 2 == 0)
            {
                // int mn = v[i];
                int mx = v[j];
                int x = diff / 2;
                // ie for this x, we have subtraced an extra during cnt1 and cnt2 both
                int y = mx - x;
                // debug(mn);
                // debug(mx);
                // debug(x);
                // debug(y);
                if (y <= c)
                    cntPairs++;
            }
        }
    }

    cout << cntPairs << endl;
}
