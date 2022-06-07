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
int n, x;
vector<int> v;
//.....................................

void suraj()
{
  cin >> n >> x;

  v = vector<int>(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  vector<int> ps(n);
  ps[0] = v[0];

  for (int i = 1; i < n; i++)
  {
    ps[i] = ps[i - 1] + v[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    // check for how many days will the ith shop provide me with sugar.
    int val = ps[i];
    if (val <= x)
      ans += (1 + (x - val) / (i + 1));
    // ans += max(0ll, 1 + (x - val) / (i + 1));
  }

  cout << ans << endl;
}
