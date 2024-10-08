// @author: ascyrax

#include <bits/stdc++.h>

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
    int n, m, k;
    cin >> n >> m >> k;

    int shortest = n - 1 + m - 1;
    int diff = k - shortest;

    char horGrid[n][m - 1];
    char verGrid[n - 1][m];

    // horiz
    for (int j = 0; j < m - 1; j++)
    {
        if (j & 1)
            horGrid[0][j] = 'R';
        else
            horGrid[0][j] = 'B';
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
            horGrid[i][j] = 'B';
    }

    if (diff < 0)
    {
        cout << "NO" << endl;
        return;
    }
    else if (diff % 4 == 1 || diff % 4 == 3)
    {
        cout << "NO" << endl;
        return;
    }
    else if (diff % 4 == 2)
    {
        cout << "YES" << endl;

        // vert
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == m - 1)
                {
                    if ((i + (m - 1)) & 1)
                        verGrid[i][j] = 'R';
                    else
                        verGrid[i][j] = 'B';
                }
                else
                    verGrid[i][j] = 'B';
            }
        }
        char ch = verGrid[n - 3][m - 1];
        if (ch == 'R')
        {
            horGrid[n - 2][m - 2] = 'B';
            horGrid[n - 1][m - 2] = 'B';
            verGrid[n - 2][m - 2] = 'R';
            verGrid[n - 2][m - 1] = 'R';
        }
        else
        {
            horGrid[n - 2][m - 2] = 'R';
            horGrid[n - 1][m - 2] = 'R';
            verGrid[n - 2][m - 2] = 'B';
            verGrid[n - 2][m - 1] = 'B';
        }
    }
    else if (diff % 4 == 0)
    {
        cout << "YES" << endl;

        // vert
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == m - 1)
                {
                    if ((i + (m - 1)) & 1)
                        verGrid[i][j] = 'R';
                    else
                        verGrid[i][j] = 'B';
                }
                else
                    verGrid[i][j] = 'B';
            }
        }

        char ch = verGrid[n - 3][m - 1];
        if (ch == 'B')
        {
            horGrid[n - 2][m - 2] = 'B';
            horGrid[n - 1][m - 2] = 'B';
            verGrid[n - 2][m - 2] = 'R';
            verGrid[n - 2][m - 1] = 'R';
        }
        else
        {
            horGrid[n - 2][m - 2] = 'R';
            horGrid[n - 1][m - 2] = 'R';
            verGrid[n - 2][m - 2] = 'B';
            verGrid[n - 2][m - 1] = 'B';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
            cout << horGrid[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
            cout << verGrid[i][j] << " ";
        cout << endl;
    }
}
