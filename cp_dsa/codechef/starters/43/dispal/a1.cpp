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
  int n, x;
  cin >> n >> x;

  int maxX = (n + 1) / 2;
  if (x > maxX)
    cout << -1 << endl;
  else
  {
    vector<char> ans;
    int cnt = 0;
    for (int i = 0; i < x; i++)
    {
      cnt++;
      ans.pb((char)('a' + i));
    }
    if (n & 1)
    {
      for (int i = x - 2; i >= 0; i--)
      {
        cnt++;
        ans.pb((char)('a' + i));
      }
    }
    else
    {
      for (int i = x - 1; i >= 0; i--)
      {
        cnt++;
        ans.pb((char)('a' + i));
      }
    }
    int rem = n - cnt;
    for (int i = 0; i < rem / 2; i++)
      cout << "a";
    for (auto el : ans)
      cout << el;
    for (int i = 0; i < rem / 2; i++)
      cout << "a";
    cout << endl;
  }
}
