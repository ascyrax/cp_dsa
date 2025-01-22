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
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;
    int gcd = __gcd((int)u, (int)v);
    int lcm = (u * v) / gcd;
    int pathGcd = u + v;
    int pathLcm = lcm / u + lcm / v;
    if (lcm == max(u, v))
    {
      pathLcm = v / u;
    }
    cout << min(pathGcd, pathLcm) << endl;
  }
}
