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

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    freopen("shell.out", "w", stderr);

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

int n;
vector<int> queen, king, jack;
vector<int> helperQ, helperK, helperJ;
vector<int> visited;
int found;
vector<pair<int, int>> parent[4];

void solve(int index)
{
    // if (index > 30000)
    debug(index);
    // debug(parent);
    int valQ = queen[index], valK = king[index], valJ = jack[index];
    // cout << "valQ: " << valQ << endl;
    // debug(valQ);
    // debug(valK);
    // debug(valJ);
    // in helperQ this el (index) is located at the index valQ
    for (int i = valQ - 1; i >= 1; i--)
    { // here valQ is the index of helperQ till where we are gonna go
        // helperQ[i] must be more than the index
        if (found > 0)
            return;
        int nextElIndex = helperQ[i];
        // debug(nextElIndex);
        if (nextElIndex > index)
        {
            if (!visited[nextElIndex])
            {
                parent[1][nextElIndex] = make_pair(1, index);
                visited[nextElIndex] = 1;
                if (nextElIndex == n)
                {
                    found = 1;
                    return;
                }
                solve(nextElIndex);
            }
        }
    }

    for (int i = valK - 1; i >= 1; i--)
    {
        if (found > 0)
            return;
        int nextElIndex = helperK[i];
        if (nextElIndex > index)
        {
            if (!visited[nextElIndex])
            {
                parent[2][nextElIndex] = make_pair(2, index);

                visited[nextElIndex] = 1;
                if (nextElIndex == n)
                {
                    found = 2;
                    return;
                }
                solve(nextElIndex);
            }
        }
    }

    for (int i = valJ - 1; i >= 1; i--)
    {
        if (found > 0)
            return;
        int nextElIndex = helperJ[i];
        if (nextElIndex > index)
        {
            if (!visited[nextElIndex])
            {
                parent[3][nextElIndex] = make_pair(3, index);
                visited[nextElIndex] = 1;
                if (nextElIndex == n)
                {
                    found = 3;
                    return;
                }
                solve(nextElIndex);
            }
        }
    }

    return;
}

void suraj()
{
    cin >> n;

    queen = vector<int>(n + 1, 0);
    king = vector<int>(n + 1, 0);
    jack = vector<int>(n + 1, 0);
    helperQ = vector<int>(n + 1, 0);
    helperK = vector<int>(n + 1, 0);
    helperJ = vector<int>(n + 1, 0);

    visited = vector<int>(n + 1, 0);
    parent[1] = vector<pair<int, int>>(n + 1);
    parent[2] = vector<pair<int, int>>(n + 1);
    parent[3] = vector<pair<int, int>>(n + 1);
    found = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> queen[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> king[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> jack[i];
    }

    // debug("inputs taken :)");

    for (int i = 1; i <= n; i++)
    {
        int valQ = queen[i];
        helperQ[valQ] = i;

        int valK = king[i];
        helperK[valK] = i;

        int valJ = jack[i];
        helperJ[valJ] = i;
    }

    // debug(queen);
    // debug(king);
    // debug(jack);
    // debug(helperQ);
    // debug(helperK);
    // debug(helperJ);

    parent[1][1] = make_pair(0, 0);
    parent[2][1] = make_pair(0, 0);
    parent[3][1] = make_pair(0, 0);

    // debug("solve begin");
    visited[1] = 1;
    solve(1);
    // debug(parent[1]);
    // debug(parent[2]);
    // debug(parent[3]);

    // debug("solved");

    if (found > 0)
    {
        cout << "YES" << endl;
        vector<pair<int, int>> ans;
        ans.push_back(make_pair(found, n));
        int currRow = found;
        int currIndex = n;
        while (1)
        {
            pair<int, int> nextPair = parent[currRow][currIndex];
            int nextRow = nextPair.first;
            int nextIndex = nextPair.second;
            // debug(nextRow);
            // debug(nextIndex);
            for (int row = 1; row <= 3; row++)
            {
                if (parent[row][nextIndex] != make_pair(0, 0))
                {
                    nextRow = row;
                    break;
                }
            }
            if (nextIndex == 1)
                break;
            else
            {
                ans.push_back(make_pair(nextRow, nextIndex));
                currRow = nextRow;
                currIndex = nextIndex;
            }
        }
        // debug(ans);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            pair<int, int> el = ans[i];
            int row = el.first;
            int index = el.second;

            if (row == 1)
                cout << "Q ";
            else if (row == 2)
                cout << "K ";
            else if (row == 3)
                cout << "J ";
            cout << index << endl;
        }
    }
    else
        cout << "NO" << endl;
}


// dfs wont work because for testcases like 32, stack overflow will occur
// hence we gotta use the iterative approach

// test case 32
// 1
// 200000
// 199999 199998 .... 3 2 1 200000