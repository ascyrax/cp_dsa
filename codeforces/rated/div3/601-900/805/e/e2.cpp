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
int mod = 1e9 + 7;
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
void print(string s, vector<set<int>> v)
{
  cout << s << endl;
  for (auto el : v)
  {
    for (int i : el)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}
//.....................................
vector<set<int>> graph;
bool flag = true;
vector<bool> visited;
vector<int> vDepth;
//.....................................
void dfs(int node, int depth, int parent)
{
  vDepth[node] = depth;
  for (auto neigh : graph[node])
  {
    if (!visited[neigh])
    {
      visited[neigh] = true;
      dfs(neigh, depth + 1, node);
      if (!flag)
        return;
    }
    else
    {
      // if not adjacent
      set<int> adjNodes = graph[node];
      auto it = adjNodes.lower_bound(neigh);
      if (*it == neigh)
      { // if(neigh==parent)
        int cycleSize = abs(vDepth[node] - vDepth[neigh] + 1);
        int nEdges = cycleSize;
        if (nEdges > 2 && (nEdges % 2 == 1))
        {
          // cout << node << " " << depth << " " << parent << endl;
          flag = false;
          return;
        }
      }
    }
  }
  return;
}
//.....................................

void suraj() // solution using graphs
{
  int n;
  cin >> n;
  graph = vector<set<int>>(n, set<int>());
  flag = true;
  visited = vector<bool>(n, false);
  vDepth = vector<int>(n, 0);

  map<int, int> cnt;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == b)
      flag = false;
    graph[a].insert(b);
    graph[b].insert(a);
    cnt[a]++;
    cnt[b]++;
  }

  for (int i = 0; i < n; i++)
  {
    if (cnt.count(i) > 0 && cnt[i] == 2)
      ;
    else
    {
      cout << "NO" << endl;
      return;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      dfs(i, 0, -1);
    }
  }

  // print("graph", graph);
  // print("vDepth", vDepth);

  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
