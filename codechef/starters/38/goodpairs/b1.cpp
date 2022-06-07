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
  vector<int> a(n), b(n);
  vector<pair<int, int>> c(n), d(n);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  map<pair<int, int>, vector<int>> m1, m2;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    c[i] = make_pair(a[i] * b[i], a[i] - b[i]);
    d[i] = make_pair(a[i] * b[i], b[i] - a[i]);
    m1[c[i]].pb(i);
    m2[d[i]].pb(i);
  }

  for (int i = 0; i < n; i++)
  {
    if (m2.count(c[i]) == 0)
      continue;
    int itr = upper_bound(m2[c[i]].begin(), m2[c[i]].end(), i) - m2[c[i]].begin();
    int cnt = m2[c[i]].size() - itr;
    ans += cnt;
  }
  cout << ans << endl;
}
