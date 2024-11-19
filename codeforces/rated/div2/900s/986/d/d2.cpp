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
// #define int long long
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
    vector<int> q(n + 1), k(n + 1), j(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> j[i];
    }

    // testcase 32. why does d1 gives tle on that :(
    // if (n == 200000 && q[1] == 199999)
    // {
    //     // j
    //     cout << ".... ";
    //     for (int i = n - 9; i <= n; i++)
    //     {
    //         cout << q[i] << " ";
    //     }
    //     cout << endl;

    //     // k
    //     for (int i = 1; i <= 10; i++)
    //     {
    //         cout << k[i] << " ";
    //     }
    //     cout << ".... ";
    //     for (int i = n - 9; i <= n; i++)
    //     {
    //         cout << k[i] << " ";
    //     }
    //     cout << endl;

    //     // j

    //     for (int i = 1; i <= 10; i++)
    //     {
    //         cout << j[i] << " ";
    //     }
    //     cout << ".... ";
    //     for (int i = n - 9; i <= n; i++)
    //     {
    //         cout << j[i] << " ";
    //     }
    //     cout << endl;
    // }

    int prevQ = n, prevK = n, prevJ = n;
    vector<pair<int, int>> ptr[4];
    ptr[1] = vector<pair<int, int>>(n + 1, make_pair(0, 0));
    ptr[2] = vector<pair<int, int>>(n + 1, make_pair(0, 0));
    ptr[3] = vector<pair<int, int>>(n + 1, make_pair(0, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        // q
        if (q[i] > q[prevQ])
        {
            if (k[i] < k[prevK])
            {
                ptr[2][i] = make_pair(1, prevQ);
                prevK = i;
            }

            if (j[i] < j[prevJ])
            {
                ptr[3][i] = make_pair(1, prevQ);
                prevJ = i;
            }
            ptr[1][i] = make_pair(1, prevQ);
            // prevQ = i;
        }
        // k
        else if (k[i] > k[prevK])
        {
            if (q[i] < q[prevQ])
            {
                ptr[1][i] = make_pair(2, prevK);
                prevQ = i;
            }

            if (j[i] < j[prevJ])
            {
                ptr[3][i] = make_pair(2, prevK);
                prevJ = i;
            }
            ptr[2][i] = make_pair(2, prevK);
            // prevK = i;
        }

        // j
        else if (j[i] > j[prevJ])
        {
            if (q[i] < q[prevQ])
            {
                ptr[1][i] = make_pair(3, prevJ);
                prevQ = i;
            }

            if (k[i] < k[prevK])
            {
                ptr[2][i] = make_pair(3, prevJ);
                prevK = i;
            }
            ptr[3][i] = make_pair(3, prevJ);
            // prevJ = i;
        }
    }

    // debug(ptr[1]);
    // debug(ptr[2]);
    // debug(ptr[3]);

    if (ptr[1][1] == make_pair(0, 0) && ptr[2][1] == make_pair(0, 0) && ptr[3][1] == make_pair(0, 0))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        vector<pair<int, int>> ans;
        pair<int, int> cur;
        if (ptr[1][1] != make_pair(0, 0))
            cur = make_pair(1, 1);
        else if (ptr[2][1] != make_pair(0, 0))
            cur = make_pair(2, 1);
        else if (ptr[3][1] != make_pair(0, 0))
            cur = make_pair(3, 1);

        while (1)
        {
            pair<int, int> next = ptr[cur.first][cur.second];
            ans.push_back(next);
            if (next.second == n)
            {
                break;
            }
            cur = next;
        }
        cout << ans.size() << endl;
        for (pair<int, int> el : ans)
        {
            int row = el.first;
            int val = el.second;
            if (row == 1)
                cout << "Q ";
            else if (row == 2)
                cout << "K ";
            else if (row == 3)
                cout << "J ";
            cout << val << endl;
        }
    }
}
