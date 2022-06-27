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

//.....................................

//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid;
  int mx = -1e18;
  for (int i = 0; i < n; i++)
  {
    vector<int> row(m);
    for (int &i : row)
    {
      cin >> i;
      mx = max(mx, i);
    }
    grid.pb(row);
  }

  int hor = 0, ver = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == mx)
      {
        hor = max(j - 0 + 1, m - 1 - j + 1);
        ver = max(i - 0 + 1, n - 1 - i + 1);
        break;
      }
    }
  }
  cout << hor * ver << endl;
}
