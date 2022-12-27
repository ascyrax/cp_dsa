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
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;
  vector<int> ps(n, 0);
  if (s[0] == 'B')
    ps[0]++;
  for (int i = 1; i < n; i++)
  {
    if (s[i] == 'B')
      ps[i] = ps[i - 1] + 1;
    else
      ps[i] = ps[i - 1];
  }
  int nBlacks = ps[k - 1];
  for (int i = k; i < n; i++)
  {
    nBlacks = max(nBlacks, ps[i] - ps[i - k]);
  }
  cout << k - nBlacks << endl;
}
