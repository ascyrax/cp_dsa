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

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
int n, m;
vector<int> vAdjCats;
vector<vector<int>> tree;
vector<int> cats;
vector<int> leaves;

void dfs(int node, int parent, int adjCats, int maxAdjCats)
{

  // cout << node << " " << parent << " " << adjCats << " " << maxAdjCats << endl;
  vAdjCats[node] = maxAdjCats;

  if (tree[node].size() == 1)
  {
    // node is a leaf
    leaves.pb(node);
  }

  for (auto neigh : tree[node])
  {
    if (neigh == parent)
      continue;
    if (cats[neigh] == 1)
      dfs(neigh, node, adjCats + 1, max(maxAdjCats, adjCats + 1));
    else
      dfs(neigh, node, 0, maxAdjCats);
  }
  return;
}
//.....................................

void suraj()
{
  cin >> n >> m;

  tree = vector<vector<int>>(n, vector<int>());
  vAdjCats = vector<int>(n, 0);
  cats = vector<int>(n, 0);

  for (int &i : cats)
    cin >> i;

  for (int i = 1; i <= n - 1; i++)
  {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    tree[a].pb(b);
    tree[b].pb(a);
  }

  if (cats[0] == 1)
    dfs(0, 0, 1, 1);
  else
    dfs(0, 0, 0, 0);

  int ans = 0;
  // iterate on leaves
  for (int i : leaves)
  {
    if (i == 0)
      continue;
    if (vAdjCats[i] <= m)
      ans++;
  }
  cout << ans << endl;

  leaves.clear();
}
