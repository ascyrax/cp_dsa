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

  ioss

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
int n, m;
vector<vector<int>> tree;
vector<int> dist;
vector<int> parent;

void dfs(int node, int d, int par)
{ // d is the distance of the node from the root.
  for (auto neigh : tree[node])
  {
    if (neigh != par)
    {
      parent[neigh] = node;
      dist[neigh] = dist[node] + 1;
      dfs(neigh, dist[neigh], node);
    }
  }
  return;
}
//.....................................

void suraj()
{
  cin >> n >> m;
  tree = vector<vector<int>>(n, vector<int>());
  dist = vector<int>(n, 0);
  parent = vector<int>(n, 0);

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }

  dfs(0, 0, 0); // to get dist of each node from the root and also to create a vector where each node is represented by its immediate parent

  for (int i = 0; i < m; i++)
  {
    int len;
    cin >> len;

    vector<int> v(len);
    int mxDist = 0, endNode = 0;
    for (int &i : v)
    {
      cin >> i;
      i--;
      if (dist[i] >= mxDist)
      {
        mxDist = max(mxDist, dist[i]);
        endNode = i;
      }
    }
    // now the path will be from root to this node.
    // map<int, int> mp;
    // instead of mp
    vector<int> vtemp(n, 0);
    for (int i = 0; i < n; i++)
      vtemp[i] = parent[i];

    vector<int> path;
    // endNode -> root
    while (endNode != 0)
    {
      path.pb(endNode);
      endNode = parent[endNode];
    }
    path.pb(0);

    for (int i : path)
      // mp[i]++;
      vtemp[i] = true;

    int flag = 0;

    for (int i : v)
    {
      if (vtemp[parent[i]] == false)
      {
        flag = -1;
        break;
      }
    }

    if (flag == -1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
