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
  int minTime = -inf;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    sum += v[i];
    int q = sum / (i + 1);
    int r = sum % (i + 1);
    if (r > 0)
      minTime = max(minTime, (sum / (i + 1)) + 1);
    else
      minTime = max(minTime, sum / (i + 1));
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int time;
    cin >> time;
    if (time < minTime)
      cout << -1 << endl;
    else
    {
      int q = sum / time;
      int r = sum % time;
      if (r > 0)
        cout << q + 1 << endl;
      else
        cout << q << endl;
    }
  }
}
