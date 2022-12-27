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

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
//.....................................

//.....................................
vector<vector<int>> tree;
vector<bool> visited;
vector<int> degree;
vector<int> depth;
int minDepth; // initialize inside main
bool leaf = false;
//.....................................
void dfs(int node, int d) // d represent the depth
{
  depth[node] = d;
  visited[node] = true;
  if (degree[node] == 1)
  {
    // a leaf
    if (depth[node] <= minDepth)
      leaf = true;
    minDepth = min(minDepth, depth[node]);
    // minDepth deleted
  }
  else if (degree[node] == 2 && node != 0)
  {
    if (depth[node] < minDepth)
      leaf = false;
    minDepth = min(minDepth, depth[node]);
    // minDepth + 1 deleted
  }
  for (int neigh : tree[node])
  {
    if (!visited[neigh])
    {
      dfs(neigh, d + 1);
    }
  }
  return;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;

  minDepth = 1e9;
  tree = vector<vector<int>>(n, vector<int>());
  visited = vector<bool>(n, false);
  degree = vector<int>(n, 0);
  depth = vector<int>(n, 0);

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].pb(b);
    tree[b].pb(a);
    degree[a]++;
    degree[b]++;
  }

  if (degree[0] == 1)
  {
    cout << n - 2 << endl;
    return;
  }

  dfs(0, 0);

  int infected = minDepth + 1; // +1 for root
  int deleted = minDepth;
  if (!leaf)
    deleted++;

  cout << n - infected - deleted << endl;
}
