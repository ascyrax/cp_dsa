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

      // cout << setprecision(1ll5) << fixed;

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
  int a, b, c;
  cin >> a >> b >> c;

  int right = 0;
  for (int i = 0; i <= 40; i++)
  {
    if ((1ll << i) & a)
      right = i;
    if ((1ll << i) & b)
      right = i;
    if ((1ll << i) & c)
      right = i;
  }
  // why 40? why not i<=right only. becz for cases when bina+binb+binc==1 => one of these three ka binary format will shift to the right by one. Now since max value of right is ~ 30. => in 30 operations if a,b and c shift by 10 then these three will reach till i=40 at max. For any other case, ans will be NO if we reach past the last set bit of a/b/c and other two still have set bits left. Hence checking till i=40 is enough.
  for (int i = 0; i <= 40; i++)
  {
    if (a == b && b == c)
      break;

    int bina = 0, binb = 0, binc = 0;
    bina = ((1ll << i) & (a)) ? 1ll : 0;
    binb = ((1ll << i) & (b)) ? 1ll : 0;
    binc = ((1ll << i) & (c)) ? 1ll : 0;
    if (bina + binb + binc == 2)
    {
      // added to the one which misses the 1ll at this location in its binary form
      if (bina == 0)
        a += (int)(pow(2, i));
      else if (binb == 0)
        b += (int)(pow(2, i));
      else
        c += (int)(pow(2, i));
    }
    else if (bina + binb + binc == 1ll)
    {
      if (bina == 1ll)
        a += (int)(pow(2, i));
      else if (binb == 1ll)
        b += (int)(pow(2, i));
      else if (binc == 1ll)
        c += (int)(pow(2, i));
    }
    else
    {
      cout << "NO" << endl;
      return;
    }
  }
  if (a == b && b == c)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
