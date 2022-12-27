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
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  if (n == 1)
  {
    cout << -1 << endl;
    return;
  }

  vector<int> ans = v;
  sort(ans.begin(), ans.end());
  bool flag = false;
  for (int i = 0; i < n - 1; i++)
  {
    if (v[i] == ans[i])
    {
      // if (i == n - 2)
      //   flag = true;
      swap(ans[i], ans[i + 1]);
    }
  }

  if (v[n - 1] == ans[n - 1])
  {
    swap(ans[n - 1], ans[n - 2]);
  }
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
}
