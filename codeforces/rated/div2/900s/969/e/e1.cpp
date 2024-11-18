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

int n, w;
vector<vector<int>> graph;
vector<int> edgeWeight;
int nLeaves;
vector<bool> visited;
int nUsefulEdges; // edesIJ where j=i+1 :)
vector<bool> isUseful;
int nUsefulEdgesWhichAreLeavesToo;
vector<int> isALeaf;

void dfs(int node)
{
    // debug(node);
    if (node != 1 && graph[node].size() == 1)
    {
        nLeaves++;
        isALeaf[node] = 1;
    }
    // debug(nLeaves);
    for (int neigh : graph[node])
    {
        if (neigh == (node % n + 1))
        {
            nUsefulEdges++;
            if (neigh < node)
                isUseful[node] = true;
            else
                isUseful[neigh] = true;
            if (neigh != 1 && graph[neigh].size() == 1)
                nUsefulEdgesWhichAreLeavesToo++;
        }
        if (!visited[neigh])
        {
            visited[neigh] = true;
            dfs(neigh);
        }
    }
    return;
}

int calculateDistIJ(int sumUsefulEdges, int sumOtherEdges, int nAssignedEdges, int nAssignedUsefulEdges)
{
    int mxSum = 0;

    // two kinds of distIJs
    // normal, and long :)

    // NORMAL DISTIJS
    // ______________________________________________________________________

    int nAssignedOtherEdges = nAssignedEdges - nAssignedUsefulEdges;
    debug(sumUsefulEdges);
    debug(sumOtherEdges);

    // max possible sum of distIJs :)
    mxSum += w * n;
    debug(mxSum);

    // marked edges with abs(j - 1) = 1, lets call them as usefulEdges
    // we counted these as w, we gotta change it to -> edgeWeight
    // hence we gotta do mxSum -= (w - edgeWeight)
    // we can do this for all such edges at once :)
    mxSum -= (nAssignedUsefulEdges * w - sumUsefulEdges);
    debug(mxSum);

    int nUnassignedUsefulEdges = nUsefulEdges - nAssignedUsefulEdges;
    debug(nUnassignedUsefulEdges);

    // now, what about other usefulEdges which are not marked with their weights yet
    // we counted them as w too, but we change it to -> w - sumUsefulEdges - sumOtherEdges
    // hence we gotta do mxSum -= w - ( w - sumUsefulEdges - sumOtherEdges)
    // lets do this for all the unassigned useful edges at once
    mxSum -= nUnassignedUsefulEdges * (sumOtherEdges + sumUsefulEdges);
    debug(mxSum);

    // whatif an edges whose abs(j - i ) != 1, lets call them the otherEdges

    // LONG DISTIJS
    // ______________________________________________________________________

    // cnt the no of cases where nodes are not adjacent :), ie where distIJ will include more
    // than one edge :) let us call these distIJs as longDistIJs
    int nLongDist = nLeaves;
    debug(nLongDist);

    vector<int> neighs = graph[1];
    for (int neigh : neighs)
        if (neigh == n)
        {
            nLongDist--;
            break;
        }

    // cz otherEdges will come under exactly two paths for longDistIJs :)
    mxSum -= max(0ll, (nLongDist - 2)) * sumOtherEdges;
    debug(mxSum);

    // cz these edges will come under exactly one paths for longDistIJs :)
    // and they will come once under the path of distIJ where i and j are adjacent nodes :)
    // its been counted in the first 'mxSum += sumUsefulEdges'+
    mxSum -= max(0ll, (nLongDist - 1)) * sumUsefulEdges;
    debug(mxSum);

    return mxSum;
}
// 1
// 10 511
// 1 2 2 4 2 1 1 8 8
// 3 2
// 6 16
// 10 256
// 9 128
// 2 1
// 5 8
// 8 64
// 4 4
// 7 32

void suraj()
{
    cin >> n >> w;

    graph = vector<vector<int>>(n + 1, vector<int>());
    edgeWeight = vector<int>(n + 1, 0);
    nLeaves = 0;
    visited = vector<bool>(n + 1, false);
    nUsefulEdges = 0;
    isUseful = vector<bool>(n + 1, false);
    nUsefulEdgesWhichAreLeavesToo = 0;
    isALeaf = vector<int>(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        graph[i].pb(p);
        graph[p].pb(i);
    }

    visited[1] = true;
    dfs(1); // to populate nLeaves
    // debug(nLeaves);
    // debug(nUsefulEdges);
    // debug(isALeaf);

    // no of edges = n - 1
    // initially all valueless
    vector<int> ans;
    int sumUsefulEdges = 0;
    int sumOtherEdges = 0;
    int nAssignedUsefulEdges = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        // edge x has a value y.
        edgeWeight[x] = y;
        if (isUseful[x])
        {
            sumUsefulEdges += y;
            nAssignedUsefulEdges++;
        }
        else
        {
            sumOtherEdges += y;
        }
        int res = calculateDistIJ(sumUsefulEdges, sumOtherEdges, i, nAssignedUsefulEdges);
        ans.push_back(res);
    }
    for (int el : ans)
        cout << el << " ";
    cout << endl;
}
