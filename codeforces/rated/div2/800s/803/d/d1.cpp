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

  // ioss

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
  int n;
  cin >> n;
  int l = 1, r = n;
  int m = l + (r - l) / 2;
  while (l < r)
  {
    m = l + (r - l) / 2;
    cout << "? " << l << " " << m << endl;
    vector<int> v(m - l + 1, 0);
    int cnt = 0;
    vector<int> good, bad;
    for (int &i : v)
    {
      cin >> i;
      if (i < l || i > m)
        cnt++;
      else
        good.pb(i);
    }
    // cout << "v" << endl;
    // for (auto el : v)
    //   cout << el << " ";
    // cout << endl;
    // cout << "cnt: " << cnt << endl;
    if (m - l + 1 == 2)
    {
      if (cnt % 2 == 1)
      {
        l = good[0];
        break;
      }
    }
    int len = m - l + 1;

    if ((len - cnt) % 2 == 1)
    {
      r = m;
    }
    else
    {
      l = m + 1;
    }
  }
  cout << "! " << l << endl;
}
