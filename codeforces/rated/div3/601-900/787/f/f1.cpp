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

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}
void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
int inf = 1e18;
//.....................................
vector<vector<int>> tree;
vector<bool> houses;
int x, y;
vector<int> parent;
vector<bool> visited;
vector<int> path; // this is the path from x to y.
//.....................................
int dfs1(int node)
{
  int val = 0;
  if (node == y)
  {
    path.pb(node);
    return 1;
  }
  for (int neigh : tree[node])
  {
    if (!visited[neigh])
    {
      visited[neigh] = true;
      val = dfs1(neigh);
    }
    if (val == 1)
    {
      path.pb(node);
      return 1;
    }
  }
  return 0;
}
void dfs2(int node, int pNode)
{
  // cout << node << " " << pNode << endl;
  parent[node] = pNode;
  for (int neigh : tree[node])
  {
    // cout << "neigh: " << neigh << endl;
    if (parent[neigh] == -1 || visited[neigh])
      continue; // since this neigh lies on the pathXY.
    visited[neigh] = true;
    dfs2(neigh, node);
  }
  return;
}
//.....................................

set<pair<int, int>> edgeSet;

int dfs3(int node, int pNode)
{
  int flag = 0;
  if (houses[node])
  {
    edgeSet.insert(make_pair(min(node, pNode), max(node, pNode)));
    flag = 1;
  }
  for (int neigh : tree[node])
  {
    if (parent[neigh] == -1 || neigh == pNode)
      continue;
    if (dfs3(neigh, node))
    {
      flag = 1;
      edgeSet.insert(make_pair(min(node, pNode), max(node, pNode)));
    }
  }
  return flag;
}
//.....................................

void suraj()
{
  // inputs
  int n, k;
  cin >> n >> k;
  tree = vector<vector<int>>(n, vector<int>());
  houses = vector<bool>(n, false);
  parent = vector<int>(n, -2);
  visited = vector<bool>(n, false);
  path.clear();
  vector<int> time(n, 0);

  cin >> x >> y;
  x--;
  y--;
  for (int i = 0; i < k; i++)
  {
    int temp;
    cin >> temp;
    houses[--temp] = true;
  }
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }

  // logic
  visited = vector<bool>(n, false);
  visited[x] = true;
  dfs1(x); // find path btwn x and y.
  reverse(path.begin(), path.end());

  // print("path", path);

  for (auto el : path)
    parent[el] = -1;
  visited = vector<bool>(n, false);
  for (auto el : path)
  {
    visited[el] = true;
    dfs2(el, -1);
  } // find the parent of each node. parent[el]=-1 if el lies on the path from x to y.
  // print("parent", parent);

  // for each node on pathXY:-
  // find the edges which are traversed when we try to reach the houses.
  // final time taken inside a subtree = no of edges*2

  for (auto el : path)
  {
    dfs3(el, -1);
    // cout << "edgeSet" << endl;
    // for (auto el : edgeSet)
    // {
    //   cout << el.first << " " << el.second << " , ";
    // }
    // cout << endl;

    if (edgeSet.size() > 0)
      time[el] = ((edgeSet.size() - 1) * 2); // -1 becz we dont want the (-1,el) edge.
    else
      time[el] = 0;
    edgeSet.clear();
  }
  // print("time", time);
  // ans = sum of final time for all subtrees of the pathXY
  int ans = 0;
  for (auto el : path)
    ans += time[el];

  // output
  cout << ans + path.size() - 1 << endl;
}
