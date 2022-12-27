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
int n;
vector<int> v;
vector<int> color;
int col = 0;
vector<bool> visited;
int days = 0;
map<int, int> m;

void dfs(int node)
{
  days++;
  color[node] = col;
  int next = v[node];
  if (!visited[next])
  {
    visited[next] = true;
    dfs(next);
  }
  return;
}
//.....................................

void suraj()
{
  cin >> n;
  v = vector<int>(n + 1);
  color = vector<int>(n + 1, 0);
  visited = vector<bool>(n + 1, false);

  for (int i = 1; i <= n; i++)
    cin >> v[i];

  for (int i = 0; i <= n; i++)
  {
    if (!visited[i])
    {
      col++;
      days = 0;
      visited[i] = true;
      dfs(i);
      m[col] = days;
    }
  }
  vector<int> nDays(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    nDays[i] = m[color[i]];
  }
  for (int i = 1; i <= n; i++)
    cout << nDays[i] << " ";
  cout << endl;

  m.clear();
}
