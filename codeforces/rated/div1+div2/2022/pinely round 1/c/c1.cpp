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
int n;
vector<string> grid;
vector<vector<int>> graph;
vector<vector<int>> ans;

//.....................................
vector<int> modify(vector<int> arr, int index)
{
  vector<int> modArr;
  for (int i = 0; i < arr.size(); i++)
  {
    if (i != index)
      modArr.pb(arr[i]);
  }
  return modArr;
}
void bfs(int root, vector<int> perm)
{
  queue<pair<int, vector<int>>> q;
  q.push(make_pair(root, perm));

  while (!q.empty())
  {
    auto top = q.front();
    q.pop();
    int node = top.first;
    vector<int> arr = top.second;
    ans[node] = arr;
    for (int i = 0; i < graph[node].size(); i++)
    {
      q.push(make_pair(graph[node][i], modify(arr, i)));
    }
  }
  return;
}
//.....................................

void suraj()
{
  cin >> n;
  grid = vector<string>(n);
  graph = vector<vector<int>>(n, vector<int>());
  ans = vector<vector<int>>(n, vector<int>());

  for (int i = 0; i < n; i++)
    cin >> grid[i];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] == '1')
      {
        graph[j].pb(i);
      }
    }
  }

  // assuming only one row in grid with all zeros
  vector<int> roots;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] == '1')
        cnt++;
    }
    if (cnt == 0)
    {
      roots.pb(i);
      break;
    }
  }

  // cout << "root " << root + 1 << endl;
  vector<int> perm;
  for (int i = 0; i < n; i++)
    perm.pb(i);
  for (auto root : roots)
    bfs(root, perm);

  for (int i = 0; i < n; i++)
  {
    cout << ans[i].size() << " ";
    for (auto el : ans[i])
      cout << el + 1 << " ";
    cout << endl;
  }
}
