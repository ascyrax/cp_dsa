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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
int n;
int box[128][128][128];

void suraj()
{
    cin >> n;

    // n = 101;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                box[i][j][k] = 0;
                // cerr << box[i][j][k] << " ";
            }
            // cerr << endl;
        }
        // cerr << "---" << endl;
    }

    int type;
    while (cin >> type)
    {
        if (type == 3)
            break;
        if (type == 1)
        {
            int x, y, z, k;
            cin >> x >> y >> z >> k;

            // box[x][y][z] += k;
            for (int i = x; i < n; i++)
            {
                // for (int j = y; j < n; j++)
                // {
                box[i][y][z] += k;
                // }
            }
        }
        else if (type == 2)
        {
            int x1, x2, y1, y2, z1, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

            int cnt = 0;
            for (int k = z1; k <= z2; k++)
            {
                if (y1 == 0 && x1 == 0)
                {
                    cnt += box[x2][y2][k] - 0 - 0 + 0;
                }
                else if (y1 == 0)
                {
                    cnt += box[x2][y2][k] - 0 - box[x1 - 1][y2][k] + 0;
                }
                else if (x1 == 0)
                {
                    cnt += box[x2][y2][k] - box[x2][y1 - 1][k] - 0 + 0;
                }
                else
                    cnt += box[x2][y2][k] - box[x2][y1 - 1][k] - box[x1 - 1][y2][k] + box[x1 - 1][y1 - 1][k];
            }
            cout << cnt << endl;
        }
    }
}
