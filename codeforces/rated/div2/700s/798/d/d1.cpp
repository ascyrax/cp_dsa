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
  vector<string> grid;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    grid.pb(s);
  }
  int l = m, r = 0, t = n, b = 0;
  int cntb = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'B')
      {
        // cout << "i = " << i << " , j = " << j << endl;
        cntb++;
        l = min(l, j);
        r = max(r, j);
        t = min(t, i);
        b = max(b, i);
      }
    }
  }
  l++, r++, t++, b++;
  // cout << l << " " << r << " " << t << " " << b << endl;
  cout << (t + b) / 2 << " " << (l + r) / 2 << endl;
}
