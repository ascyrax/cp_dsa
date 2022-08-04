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
int m;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<vector<bool>> flag;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int r, int c)
{
  if (r < 0 || r > 1)
    return false;
  if (c < 0 || c >= m)
    return false;
  return true;
}
//.....................................
void dfs(int r, int c, int t)
{
  if (visited[r][c] <= t)
    return;
  cout << "dfs of : " << r << " " << c << " " << t << endl;
  // flag[r][c] = true;
  visited[r][c] = t;

  for (int i = 0; i <= 3; i++)
  {
    if (check(r + dx[i], c + dy[i]))
    {
      // cout << "neigh: " << r + dx[i] << " " << c + dy[i] << endl;
      if (grid[r + dx[i]][c + dy[i]] <= t + 1)
        dfs(r + dx[i], c + dy[i], t + 1);
      else
        dfs(r + dx[i], c + dy[i], grid[r + dx[i]][c + dy[i]]);
    }
  }
}
//.....................................

void suraj()
{
  cin >> m;
  grid = vector<vector<int>>(2, vector<int>(m, -1));
  visited = vector<vector<int>>(2, vector<int>(m, inf));
  // flag = vector<vector<bool>>(2, vector<bool>(m, false));
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  dfs(0, 0, 0);

  int ans = 0;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < m; j++)
    {
      ans = max(ans, visited[i][j]);
    }
  }
  cout << ans << endl;
}
