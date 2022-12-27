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

      // freopen("shell.in", "r", stdin);
      // freopen("shell.out", "w", stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

void suraj()
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int sum = 0;
  for (int i : v)
    sum += i;

  if (sum % 3 != 0)
  {
    cout << 0 << endl;
    return;
  }

  vector<int> ps(n);
  ps[0] = v[0];
  map<int, vector<int>> m;
  m[v[0]].pb(0);
  for (int i = 1; i < n; i++)
  {
    ps[i] = ps[i - 1] + v[i];
    m[ps[i]].pb(i);
  }

  int ans = 0;

  // cout << "m" << endl;
  // for (auto el : m)
  // {
  //   cout << el.first << " ";
  //   for (auto i : el.second)
  //     cout << i << " ";
  //   cout << endl;
  // }
  // cout << "time = " << gct() << endl;

  for (int i = 0; i < n; i++)
  {
    // if (i == 1e4)
    // cout << "time = " << gct() << endl;

    // cout << "i = " << i << endl;
    int cnt = 0;
    if (ps[i] == sum / 3)
    {
      // maybe copying this was taking O(n) time.
      // auto temp = m[2 * ps[i]];
      if (m[2 * ps[i]].size() == 0)
        continue;

      // cout << "m[2 * ps[i]]" << endl;
      // for (int i : m[2 * ps[i]])
      //   cout << i << " ";
      // cout << endl;

      auto loc = upper_bound(m[2 * ps[i]].begin(), m[2 * ps[i]].end(), i) - m[2 * ps[i]].begin();

      cnt += m[2 * ps[i]].size() - loc;
      if (m[2 * ps[i]][m[2 * ps[i]].size() - 1] == n - 1)
        cnt--;

      // cout << "cnt  = " << cnt << endl;
    }
    ans += max(0ll, cnt);
  }
  cout << ans << endl;
}
