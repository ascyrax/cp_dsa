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

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  // int flag = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (v[i] == 0)
    {
      if (v[i + 1] == 2 || v[i + 1] == 3)
      {
        // flag = -1;
        // break;
        cout << "NO" << endl;
        return;
      }

      if (v[i + 1] == 1)
      {
        if (i + 2 < n && v[i + 2] == 0)
        {
          // flag = -1;
          // break;
          cout << "NO" << endl;
          return;
        }
      }
    }
    else if (v[i] == 2)
    {
      if (v[i + 1] == 2 || v[i + 1] == 3)
      {
        // flag = -1;
        // break;
        cout << "NO" << endl;
        return;
      }
      if (v[i + 1] == 1)
      {
        if (i + 2 < n && v[i + 2] == 0)
        {
          // flag = -1;
          // break;
          cout << "NO" << endl;
          return;
        }
      }
    }
    else if (v[i] == 3)
    {
      if (v[i + 1] == 0)
      {
        // flag = -1;
        // break;
        cout << "NO" << endl;
        return;
      }

      if (v[i + 1] == 1)
      {
        if (i + 2 < n && (v[i + 2] == 2 || v[i + 2] == 3))
        {
          // flag = -1;
          // break;
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  // if (flag == -1)
  //   cout << "NO" << endl;
  // else
  //   cout << "YES" << endl;

  cout << "YES" << endl;
}
