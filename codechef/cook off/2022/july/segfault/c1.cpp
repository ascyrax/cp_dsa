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
  vector<int> ps(n, 0);
  vector<bool> thief(n, true);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    // if i is the thief then he wont tell the truth about himself.
    if (a <= i && b >= i)
      thief[i] = false;
    ps[a]++;
    if (b + 1 < n)
      ps[b + 1]--;
  }
  for (int i = 1; i < n; i++)
  {
    ps[i] = ps[i - 1] + ps[i];
  }

  for (int i = 0; i < n; i++)
    if (ps[i] == 0 || ps[i] == n)
      thief[i] = false;

  int cnt = 0;
  for (auto el : thief)
    if (el)
      cnt++;
  cout << cnt << endl;

  for (int i = 0; i < n; i++)
  {
    if (thief[i])
      cout << i + 1 << endl;
  }
}
