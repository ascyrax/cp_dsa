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

vector<int> neighOf, visited;
int acyclicGraphCnt, cyclicGraphCnt = 0;

void dfs(int beginNode, int node, int graphNo, int graphSize)
{
    visited[node] = graphNo;
    int neigh = neighOf[node];
    if (visited[neigh] == 0)
    {
        dfs(beginNode, neigh, graphNo, graphSize + 1);
    }
    else if (visited[neigh] < graphNo) // part of some other graph (should be acyclic since prob statemetn suggests that the test cases are correct)
    {
        // acyclicGraphCnt--;
        // acyclicGraphCtn++;
        return;
    }
    else if (visited[neigh] == graphNo)
    {
        if (neigh == beginNode && graphSize > 2)
        {
            // debug(graphSize);
            cyclicGraphCnt++;
        }
        else
        {
            acyclicGraphCnt++;
        }
        return;
    }
}

void suraj()
{
    int n;
    cin >> n;
    int mn = n, mx = 0;
    acyclicGraphCnt = 0, cyclicGraphCnt = 0;

    neighOf = vector<int>(n + 1, 0);
    visited = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int neigh = 0;
        cin >> neigh;
        neighOf[i] = neigh;
    }

    int graphNo = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0) // ie not visited even once yet :)
        {
            dfs(i, i, graphNo, 1);
            // debug(cyclicGraphCnt);
            // debug(acyclicGraphCnt);
            graphNo++;
        }
    }

    // debug(visited);
    // debug(cyclicGraphCnt);
    // debug(acyclicGraphCnt);

    mn = cyclicGraphCnt;
    if (acyclicGraphCnt > 0)
        mn++;

    mx = cyclicGraphCnt;
    if (acyclicGraphCnt > 0)
        mx += acyclicGraphCnt;

    cout << mn << " " << mx << endl;
}
