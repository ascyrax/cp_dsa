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
  int n;
  cin >> n;
  vector<int> v(2 * n);
  int odd = 0, even = 0;
  for (int &i : v)
  {
    cin >> i;
    if (i & 1)
      odd++;
    else
      even++;
  }
  if (even < odd)
  {
    cout << (odd - even) / 2 << endl;
  }
  else
  {
    for (int i = 0; i < 2 * n; i++)
    {
      if (v[i] & 1)
        v[i] = inf;
      else
      {
        int cnt = 0;
        while (v[i] % 2 == 0)
        {
          v[i] /= 2;
          cnt++;
        }
        v[i] = cnt;
      }
    }
    sort(v.begin(), v.end());
    int diff = (even - odd) / 2;
    int sum = 0;
    for (int i = 0; i < diff; i++)
      sum += v[i];
    cout << sum << endl;
  }
}
