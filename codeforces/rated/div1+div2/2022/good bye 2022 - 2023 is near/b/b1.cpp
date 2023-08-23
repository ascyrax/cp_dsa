// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define pb push_back

void suraj();

signed main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);

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
int mod = 1e9 + 7;
// int mod = 998244353;

void suraj()
{
  int n, k;
  cin >> n >> k;

  if (k == 1)
  {
    for (int i = 1; i <= n; i++)
      cout << i << " ";
    cout << endl;
  }
  else
  {
    int q = n / k;
    int r = n % k;

    vector<int> ans(n + 1, 0);
    int left = 1, right = n;
    for (int i = 1; i <= q; i++)
    {
      for (int j = 1; j < k; j++)
      {
        ans[k * (i - 1) + j] = right--;
      }
      ans[k * (i - 1) + k] = left++;
    }
    // for (int i = 1; i <= n; i++)
    //   cout << ans[i] << " ";
    // cout << endl;
    if (r > 0)
    {
      for (int j = 1; j < r; j++)
        ans[k * ((q + 1) - 1) + j] = right--;
      ans[k * ((q + 1) - 1) + r] = left++;
    }

    for (int i = 1; i <= n; i++)
      cout << ans[i] << " ";
    cout << endl;
  }
}
