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

  // cin >> t;

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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  vector<int> ps(n);
  ps[0] = v[0];
  for (int i = 1; i < n; i++)
    ps[i] = ps[i - 1] + v[i];

  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int sum = ps[r];
    if (l > 0)
      sum -= ps[l - 1];
    int range = r - l + 1;
    int ans = 0;
    while (sum >= 10 && range > 1)
    {
      int pairs = range / 2;
      // ans += max(sum / 10, pairs);
      if (sum >= (pairs * 10))
        ans += pairs;
      sum %= (pairs * 10);
      range /= 2;
    }
    cout << ans << endl;
  }
}
