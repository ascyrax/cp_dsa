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

//.....................................
int n, m;
vector<vector<int>> dg; // directed graph
vector<int> visited;
int compNo = 0;
vector<int> leaves;
bool cycle = false;

// if leftTime=2 => we can travel 2 edges.

void dfs(int node, int leftTime)
{
  if (cycle)
    return;

  // if (dg[node].size() == 0 || leftTime == 0)
  if (dg[node].size() == 0)
  {
    leaves.pb(node);
    return;
  }

  for (int neigh : dg[node])
  {
    if (cycle)
      return;
    if (visited[neigh] != compNo)
    {
      visited[neigh] = true;
      dfs(neigh, leftTime - 1);
    }
    else
    {
      cycle = true;
      return;
    }
  }

  return;
}
//.....................................

void suraj()
{
  cin >> n;
  cin >> m;

  visited = vector<int>(n, 0);
  dg = vector<vector<int>>(n, vector<int>());

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    dg[a].pb(b);
  }

  for (int i = 0; i < n; i++)
  {
    if (visited[i] == 0)
    {
      compNo++;
      visited[i] = compNo;
      dfs(i, n);
      if (cycle)
      {
        cout << -1 << endl;
        return;
      }
    }
  }

  // int nLeaves = 0;
  // for (int i = 0; i < n; i++)
  // {
  //   if (dg[i].size() == 0)
  //     nLeaves++;
  // }

  // cout << nLeaves - 1 << endl;
  cout << leaves.size() - 1 << endl;

  leaves.clear();
}
