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

//.....................................

void suraj()
{
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int ans = 0;

  vector<bool> flag(n, false);
  for (int i = 0; i < k; i++)
  {
    // cout << "i = " << i << endl;
    // cout << s[i] << endl;
    map<char, int> m;
    // for (int j = i; j <= (n - 1) / 2; j += k)
    for (int j = i; j < n; j += k)
    {
      if (!flag[j])
      {
        m[s[j]]++;
        flag[j] = true;
      }
      if (j != (n - 1 - j) && !flag[n - 1 - j])
      {
        m[s[n - 1 - j]]++;
        flag[n - 1 - j] = true;
      }
    }
    int mx = 0;
    int tot = 0;
    // cout << "m" << endl;
    for (auto el : m)
    {
      // cout << el.first << " " << el.second << endl;
      tot += el.second;
      mx = max(mx, el.second);
    }
    ans += (tot - mx);
  }

  cout << ans << endl;
}
