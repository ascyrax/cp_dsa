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

void _print(int t)
{
    cerr << t;
}
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

vector<string> grid(8);
vector<pair<int, int>> queenLocs(8, make_pair(-1, -1)); // this contains a position of the queen <row,col> on the chessboard

int solve(int queensToPlace)
{
    int cnt = 0;
    // base case
    if (!queensToPlace)
        return 1;
    vector<pair<int, int>> pastLocs;

    while (1)
    {
        for (int row = 0; row < 8; row++)
        {
            bool validRow = true;
            for (auto queenLoc : queenLocs)
            {
                if (row == queenLoc.first)
                {
                    validRow = false;
                    break;
                }
            }
            for (auto queenLoc : pastLocs)
            {
                if (row == queenLoc.first)
                {
                    validRow = false;
                    break;
                }
            }
            int temp = queenLocs[queensToPlace - 1].second;
            if (validRow)
                queenLocs[queensToPlace - 1] = make_pair(row, temp);
        }
        for (int col = 0; col < 8; col++)
        {
            bool validCol = true;
            for (auto queenLoc : queenLocs)
            {
                if (col == queenLoc.second)
                {
                    validCol = false;
                    break;
                }
            }
            for (auto queenLoc : pastLocs)
            {
                if (col == queenLoc.second)
                {
                    validCol = false;
                    break;
                }
            }
            int temp = queenLocs[queensToPlace - 1].first;
            if (validCol)
                queenLocs[queensToPlace - 1] = make_pair(temp, col);
        }

        cnt += solve(queensToPlace - 1);

        pastLocs.pb(queenLocs[queensToPlace - 1]);
        queenLocs[queensToPlace - 1] = make_pair(-1, -1);
    }

    return cnt;
}

void suraj()
{
    // vector<vector<char>> grid;
    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }

    int ans = solve(8);
    debug(queenLocs);
    cout << ans << endl;
}
