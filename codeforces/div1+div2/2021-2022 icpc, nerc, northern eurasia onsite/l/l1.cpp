// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  // ioss

  // startTime=(double)clock();

  // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

  // cout << setprecision(15) << fixed;

  int t = 1;

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................
int n, m, s;
vector<vector<int>> graph;
vector<int> visitor;
int vis1 = -1, vis2 = -1, endNode = -1;
vector<int> parent;
//.....................................
int par1, par2;
void dfs(int node, int index, int par)
{
  // if (visitor[node] == index)
  // {
  //   // i.e. if we found a cycle
  //   return;
  // }
  // cout << node << " " << index << " " << par << endl;
  if (visitor[node] != -1 && visitor[node] != index)
  {
    endNode = node;
    vis1 = visitor[node];
    vis2 = index;
    par1 = parent[node];
    par2 = par;
    return;
  }
  visitor[node] = index;
  parent[node] = par;
  for (auto neigh : graph[node])
  {
    if (neigh == par || neigh == s)
      continue;
    if (visitor[neigh] != index)
    {
      // cout << "neigh: " << neigh << endl;
      // if not the starting and ending edge of a cycle
      dfs(neigh, index, node);
    }
    if (endNode != -1)
      return;
  }
  return;
}
vector<int> path;
void findPath(int node, int target)
{
  if (node == target)
  {
    path.pb(target);
    path.pb(s);
    return;
  }
  // cout << "node: " << node << " , target: " << target << endl;
  path.pb(target);
  target = par1;
  while (target != node)
  {
    // cout << "target: " << target << endl;
    path.pb(target);
    target = parent[target];
  }
  path.pb(target); // path.pb(node);
  path.pb(s);
}
//.....................................

void suraj()
{
  cin >> n >> m >> s;
  graph = vector<vector<int>>(n + 1, vector<int>());
  visitor = vector<int>(n + 1, -1);
  parent = vector<int>(n + 1, -1);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
  }

  if (graph[s].size() < 2)
  {
    cout << "Impossible" << endl;
    return;
  }

  for (int i = 0; i < graph[s].size(); i++)
  {
    // parent[graph[s][i]] = s;
    dfs(graph[s][i], i, s);
    if (endNode != -1)
      break;
  }
  if (endNode == -1)
    cout << "Impossible" << endl;
  else
  {
    cout << "Possible" << endl;
    // cout << endNode << endl;
    // cout << graph[s][vis1] << " " << graph[s][vis2] << endl;
    vector<int> p1, p2;
    // find path from vis1 to p1
    findPath(graph[s][vis1], endNode);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto el : path)
      cout << el << " ";
    cout << endl;
    path.clear();
    // find path from vis2 to p2
    par1 = par2;
    findPath(graph[s][vis2], endNode);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto el : path)
      cout << el << " ";
    cout << endl;
    path.clear();
  }
}
