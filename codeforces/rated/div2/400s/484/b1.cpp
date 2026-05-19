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
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

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

vector<vector<int>> neighborsOf;
map<int, bool> markedNodes;
map<pair<int, int>, bool> dontTouch;
map<pair<int, int>, bool> removedEdges;
vector<bool> visited;

int dfs(int node, int cnt)
{
    debug(node);
    visited[node] = true;
    for (int neigh : neighborsOf[node])
    {
        if (removedEdges[make_pair(neigh, node)])
            continue;
        else if (visited[neigh])
            continue;
        else
        {
            cnt += dfs(neigh, 1);
        }
    }
    return cnt;
}

bool checkForEven(int n)
{
    visited = vector<bool>(n, false);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        int connectedCompSize = dfs(i, 1);
        debug(connectedCompSize);
        if (connectedCompSize % 2 == 1)
        {
            return false;
        }
    }
    return true;
}
void debugPrint(map<int, bool> markedNodes)
{
    for (auto el : markedNodes)
    {
        cerr << el.first << " ";
    }
    cerr << endl;
    return;
}

void suraj()
{
    int n;
    cin >> n;
    neighborsOf = vector<vector<int>>(n + 1, vector<int>());

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        neighborsOf[u].push_back(v);
        neighborsOf[v].push_back(u);
    }
    int cntEdgesRemoved = 0;

    vector<vector<int>> fakeNeighbors(n + 1, vector<int>());
    while (1)
    {
        markedNodes.clear();
        debug((int)markedNodes.size());
        for (int node = 1; node <= n; node++)
        {
            int cntNeighbors = neighborsOf[node].size();
            int cntFakeNeigh = fakeNeighbors[node].size();
            int neighbor = neighborsOf[node][0];
            if (cntNeighbors - cntFakeNeigh == 1)
            {
                // this node is a leaf
                markedNodes[neighbor] = true;
                dontTouch[make_pair(node, neighbor)] = true;
                dontTouch[make_pair(neighbor, node)] = true;
            }
        }
        // debug(markedNodes);
        debugPrint(markedNodes);
        debug((int)markedNodes.size());
        if (markedNodes.size() == 0)
            break;
        int edgesRemovedThisLoop = 0;
        for (auto el : markedNodes)
        {
            int node = el.first;
            // int marked = el.second;
            for (int neigh : neighborsOf[node])
            {
                if (removedEdges[make_pair(neigh, node)])
                    continue;
                if (dontTouch[make_pair(node, neigh)])
                    continue;
                else
                {
                    edgesRemovedThisLoop++;
                    // remove this edge
                    removedEdges[make_pair(node, neigh)] = true;
                    removedEdges[make_pair(neigh, node)] = true;
                    fakeNeighbors[node].push_back(neigh);
                    fakeNeighbors[neigh].push_back(node);
                    cntEdgesRemoved++;

                    // remove the edges too, for the markedNodes to work correctly in the next loop :)
                    // erase(neighborsOf[node], neigh);
                }
            }
        }
        if (edgesRemovedThisLoop == 0)
            break;
    }
    if (!checkForEven(n))
    {
        cout << -1 << endl;
    }
    else
        cout << cntEdgesRemoved << endl;
}
