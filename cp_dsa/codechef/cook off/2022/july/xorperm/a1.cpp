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
  if (n == 3)
  {
    cout << -1 << endl;
    return;
  }
  vector<int> a, b;
  if (n % 2 == 1)
  {
    // cout << 1 << " ";
    // for (int i = 1; i <= n / 2; i++)
    // {
    //   cout << (n / 2 + 1 + 1) + i - 1 << " " << 2 + i - 1 << " ";
    // }
    // for (int i = 1; i <= n; i += 2)
    //   a.pb(i);
    //   for(int i=2;i<)
    for (int i = 1; i <= n / 2; i++)
    {
      cout << 1 + i - 1 << " " << (n)-i + 1 << " ";
      // cout << 1 + i - 1 << " " << (n / 2 + 2) + i - 1 << " ";
    }
    cout << n / 2 + 1;
  }
  else
  {
    if (n == 4)
    {
      cout << 1 << " " << 4 << " " << 2 << " " << 3 << endl;
      return;
    }
    for (int i = 1; i <= n / 2; i++)
    {
      cout << 1 + i - 1 << " " << (n - i + 1) << " ";
    }
    // for(int i=2;i<)
  }
  cout << endl;
}
