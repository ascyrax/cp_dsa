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

//...............................

//...............................

void suraj()
{
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; i++)
  {
    string a;
    cin >> a;
    grid[i] = a;
  }

  for (int col = 0; col < m; col++)
  {
    int bottom = n - 1;
    for (int row = n - 1; row >= 0; row--)
    {
      if (grid[row][col] == '*')
      {
        // swap(row, col, bottom);
        grid[row][col] = '.';
        grid[bottom][col] = '*';
        bottom--;
      }
      else if (grid[row][col] == 'o')
      {
        bottom = row - 1;
      }
    }
  }
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < m; col++)
    {
      cout << grid[row][col];
    }
    cout << endl;
  }
}

//................................