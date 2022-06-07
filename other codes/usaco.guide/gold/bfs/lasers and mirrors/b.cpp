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
int n, xl, yl, xb, yb;
map<int, vector<pair<int, int>>> mx, my;

void bfs(int x, int y)
{
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  while (!q.empty())
  {
    pair<int, int> top = q.front();
    q.pop();

    for (auto neigh : mx[top.first])
    {
    }
  }
}
//.....................................

void suraj()
{
  cin >> n >> xl >> yl >> xb >> yb;

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;

    mx[x].pb(make_pair(x, y));
    my[y].pb(make_pair(x, y));
  }

  for (auto &el : mx)
    sort(el.second.begin(), el.second.end());
  for (auto &el : my)
    sort(el.second.begin(), el.second.end());

  bfs(make_pair(0, 0));
}
