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

  vector<int> indexOf(n + 1, 0);
  for (int i = 0; i < n; i++)
    indexOf[v[i]] = i;

  int ans = 0;
  int left = 0;
  int flag = 0; // -1 => decrease // 1 => increase
  int right = left + 1;
  if (v[right] > v[left])
    flag = 1;
  else
    flag = -1;

  int mx = 0;
  int mn = inf;

  if (n == 1)
  {
    cout << 0ll << endl;
    return;
  }

  while (1)
  {
    // std::cout << flag << " " << left << " " << right << " " << ans << endl;
    // if (right == n)
    // {
    //   ans++;
    //   break;
    // }
    if (flag == 1)
    {
      if (right == n)
      {
        left = indexOf[mx];
        ans++;
        if (left == n - 1)
        {
          break;
        }
        else
        {
          flag = -1;
          right = left + 1;
          mx = 0;
        }
        continue;
      }
      if (v[right] < v[left])
      {
        flag = -1;
        ans++;
        // left = right - 1;
        left = indexOf[mx];
        right = left + 1;
        mx = 0;
        mn = v[left];
      }
      else
      {
        mx = max(mx, v[right]);
        right++;
      }
    }
    else if (flag == -1)
    {
      if (right == n)
      {
        left = indexOf[mn];
        ans++;
        if (left == n - 1)
          break;
        else
        {
          flag = 1;
          mn = inf;
          right = left + 1;
        }
        continue;
      }
      if (v[right] < v[left])
      {
        mn = min(mn, v[right]);
        right++;
      }
      else
      {
        flag = 1;
        ans++;
        // left = right - 1;
        left = indexOf[mn];
        right = left + 1;
        mn = inf;
      }
    }
  }
  cout << ans << endl;
}
