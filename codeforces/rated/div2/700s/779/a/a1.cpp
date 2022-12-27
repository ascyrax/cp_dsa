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

//...............................

//...............................

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < n; i++)
  {
    if (s[i] == s[i - 1] && s[i] == '0')
    {
      ans += 2;
    }
  }
  for (int i = 0; i <= n - 3; i++)
  {
    if (s[i] == s[i + 2] && s[i] != s[i + 1] && s[i + 1] == '1')
      ans += 1;
  }
  cout << ans << endl;
}

//................................

// int

// int

// int

// int
