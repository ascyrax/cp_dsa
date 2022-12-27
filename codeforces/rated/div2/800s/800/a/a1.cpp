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
  int a, b;
  cin >> a >> b;

  vector<int> ans;
  for (int i = 0; i < min(a, b); i++)
  {
    if (a > b)
    {
      ans.pb(0);
      ans.pb(1);
    }
    else
    {
      ans.pb(1);
      ans.pb(0);
    }
  }
  for (int i = 0; i < abs(a - b); i++)
  {
    if (a > b)
      ans.pb(0);
    else
      ans.pb(1);
  }
  for (auto el : ans)
    cout << el;
  cout << endl;
}
