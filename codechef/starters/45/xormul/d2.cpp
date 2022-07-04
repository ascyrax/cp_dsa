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
  int n, a, b;
  cin >> n >> a >> b;
  int x = 0;
  int i = (1 << (n - 1));

  char flag = 'a';
  bool flagSet = false;

  while (i > 0)
  {
    if ((a & i) == 0 && (b & i) == 0)
    {
      x += i;
    }
    else if ((a & i) > 0 && (b & i) > 0)
    {
      x += 0;
    }
    else if (!flagSet)
    {
      if ((a & i) > 0)
      {
        flagSet = true;
        flag = 'a';
      }
      else if ((b & i) > 0)
      {
        flagSet = true;
        flag = 'b';
      }
    }
    else if (flagSet)
    {
      if (flag == 'a')
      {
        if ((a & i) > 0)
        {
          x += i;
        }
      }
      else if (flag = 'b')
      {
        if ((b & i) > 0)
          x += i;
      }
    }
    i = i >> 1;
  }
  cout << x << endl;
}
