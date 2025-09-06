// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>

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

int n, m;
vector<vector<char>> grid;
vector<vector<int>> minSteps;
pair<int, int> startPos, endPos;

void bfs()
{

    queue<vector<int>> q;
    vector<int> vStartPos(7, 0);
    vStartPos[0] = startPos.first;
    vStartPos[1] = startPos.second;
    vStartPos[2] = 0; // up
    vStartPos[3] = 0; // down
    vStartPos[4] = 0; // left
    vStartPos[5] = 0; // right
    vStartPos[6] = 0; // carry
    q.push(vStartPos);
    while (!q.empty())
    {
        // debug((int)q.size());
        vector<int> frontVector = q.front();
        // debug(frontVector);
        q.pop();
        int a = frontVector[0];
        int b = frontVector[1];
        int up = frontVector[2];
        int down = frontVector[3];
        int left = frontVector[4];
        int right = frontVector[5];
        int carry = frontVector[6];
        if (grid[a][b] == '#')
            continue;
        if (carry + up + down + left + right > minSteps[a][b])
            continue;
        minSteps[a][b] = carry + up + down + left + right;
        if (make_pair(a, b) == endPos)
            continue;

        // go up
        if (up == 3)
            v = {a - 1, b, 2, 0, 0, 0, carry + 4};
        else if (up > 0)
            v = {a - 1, b, up + 1, 0, 0, 0, carry};
        else if (up == 0)
            v = {a - 1, b, 1, 0, 0, 0, carry + up + down + left + right};
        // debug(v);
        if (a - 1 >= 0 && grid[a - 1][b] != '#')
            q.push(v);

        // go down
        if (down == 3)
            v = {a + 1, b, 0, 2, 0, 0, carry + 4};
        else if (down > 0)
            v = {a + 1, b, 0, down + 1, 0, 0, carry};
        else if (down == 0)
            v = {a + 1, b, 0, 1, 0, 0, carry + up + down + left + right};
        if (a + 1 < n && grid[a + 1][b] != '#')
            q.push(v);

        // go left
        if (left == 3)
            v = {a, b - 1, 0, 0, 2, 0, carry + 4};
        else if (left > 0)
            v = {a, b - 1, 0, 0, left + 1, 0, carry};
        else if (left == 0)
            v = {a, b - 1, 0, 0, 1, 0, carry + up + down + left + right};
        if (b - 1 >= 0 && grid[a][b - 1] != '#')
            q.push(v);

        // go right
        if (right == 3)
            v = {a, b + 1, 0, 0, 0, 2, carry + 4};
        else if (right > 0)
            v = {a, b + 1, 0, 0, 0, right + 1, carry};
        else if (right == 0)
            v = {a, b + 1, 0, 0, 0, 1, carry + up + down + left + right};
        if (b + 1 < m && grid[a][b + 1] != '#')
            q.push(v);
    }
}

void suraj()
{
    cin >> n >> m;

    grid = vector<vector<char>>(n, vector<char>(m, '0'));
    // debug(grid);
    minSteps = vector<vector<int>>(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                startPos = make_pair(i, j);
            else if (grid[i][j] == 'T')
                endPos = make_pair(i, j);
        }
    }

    // minSteps[startPos.first][startPos.second] = 0;
    // debug(grid);
    // debug(minSteps);
    bfs();
    // debug(minSteps);
    if (minSteps[endPos.first][endPos.second] == INF)
        cout << -1 << endl;
    else
        cout << minSteps[endPos.first][endPos.second] << endl;
}

// why does this solution give TLE ?

// this solution is wrong, cz for position i,j we just store the minimum value till there,
// there can be a case where due to the directional limit thing, a higher value to reach
// location i,j can give a better value to reach the end position.