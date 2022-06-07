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
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  sort(v.rbegin(), v.rend());

  vector<int> ps(n);

  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    // cout << ps[r] << endl;
    ps[l]++;
    if (r + 1 < n)
      ps[r + 1]--;
  }

  for (int i = 0; i < n; i++)
  {
    if (i - 1 >= 0)
      ps[i] += ps[i - 1];
  }
  // cout << "ps" << endl;
  // for (int i : ps)
  //   cout << i << " ";
  // cout << endl;

  map<int, int> m;

  for (int i : ps)
    m[i]++;

  vector<pair<int, int>> cnt;
  for (auto el : m)
    cnt.pb(el);

  sort(cnt.rbegin(), cnt.rend());
  // cout << "cnt" << endl;
  // for (auto el : cnt)
  // {
  //   cout << el.first << " " << el.second << endl;
  // }

  int ans = 0;
  int ptr = 0;
  for (auto el : cnt)
  {
    for (int i = 0; i < el.second; i++, ptr++)
    {
      ans += v[ptr] * el.first;
    }
  }
  cout << ans << endl;
}
