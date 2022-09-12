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
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
    cin >> y[i];

  vector<int> diff(n);
  for (int i = 0; i < n; i++)
    diff[i] = y[i] - x[i];

  sort(diff.begin(), diff.end());

  int neg = -1, pos = n;
  int cnt0 = 0;

  for (int i = 0; i < n; i++)
    if (diff[i] == 0)
      cnt0++;

  for (int i = 0; i < n; i++)
    if (diff[i] > 0)
    {
      pos = i;
      break;
    }
  for (int i = 0; i < n; i++)
    if (diff[i] >= 0)
      break;
    else
      neg = i;

  // if (neg == -1 && pos == -1)
  // {
  //   cout << (cnt0 / 2) << endl;
  //   return;
  // }
  // else if (neg == -1)
  // {
  //   cout << (pos + cnt0) / 2 << endl;
  //   return;
  // }
  // else if (pos == -1)
  // {
  //   cout << cnt0 / 2 << endl;
  //   return;
  // }

  // cout << "diff: " << endl;
  // for (auto el : diff)
  //   cout << el << " ";
  // cout << endl;
  int ans = 0;
  int sum = 0;
  while (1)
  {
    // cout << "pos: " << pos << endl;
    // cout << "neg: " << neg << endl;
    if (pos == n || neg == -1)
      break;

    sum = 0;
    int posRef = pos;

    sum += diff[pos];
    sum += diff[neg];
    pos++;
    neg--;
    if (sum >= 0)
    {
      ans++;
      sum = 0;
    }
    else
    {
      while (sum < 0)
      {
        if (pos == n)
          break;

        sum += diff[pos];
        pos++;
      }
      if (sum >= 0)
      {
        ans++;
        sum = 0;
      }
      else
      {
        pos = posRef;

        int right = n - pos;
        ans += (right + cnt0) / 2;
        cout << ans << endl;
        return;
      }
    }
  }

  int right = n - pos;
  ans += (right + cnt0) / 2;

  cout << ans << endl;
}
