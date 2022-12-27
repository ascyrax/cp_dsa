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
vector<int> parent;
vector<pair<int, int>> range;
vector<vector<int>> tree;
int ans = 0;
//.....................................
int dfs(int node)
{
  int sum = 0;
  for (int child : tree[node])
  {
    sum += dfs(child);
  }
  if (sum > range[node].second)
  {
    return range[node].second;
  }
  else if (sum <= range[node].second && sum >= range[node].first)
  {
    return sum;
  }
  else if (sum < range[node].first)
  {
    ans++;
    return range[node].second;
  }
  return sum;
}
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;

  ans = 0;
  parent = vector<int>(n, -1);
  parent[0] = 0;
  range = vector<pair<int, int>>(n, pair<int, int>());
  tree = vector<vector<int>>(n, vector<int>());

  for (int i = 1; i < n; i++)
  {
    int a;
    cin >> a;
    a--;
    parent[i] = a;
    tree[a].pb(i);
  }

  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    range[i] = make_pair(l, r);
  }

  dfs(0);

  cout << ans << endl;
}
