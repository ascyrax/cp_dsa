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
  vector<int> v(n);
  int odd = 0, even = 0;
  for (int &i : v)
  {
    cin >> i;
    if (i & 1)
      odd++;
    else
      even++;
  }
  if (even == n || odd == n)
  {
    cout << 0 << endl;
  }
  else
  {
    // int ans = n;
    // convert all to odd
    // if (even <= odd)
    //   ans = min(ans, even);
    // below is equivalent to ,i.e. cnt=even-1
    // int cnt = even - 1;
    // now we are left with 1 even no
    // ans = min(ans, cnt + 1);
    // now, no even no left.
    // while (even > 1)
    // {
    //   if (even & 1)
    //   {
    //     cnt += even / 2;
    //     even = (even / 2) + 1;
    //   }
    //   else
    //   {
    //     cnt += even / 2;
    //     even /= 2;
    //   }
    // }

    // convert all to odd
    int ans = even;

    // convert all to even
    if (odd & 1)
    {
      // all cannot be converted to even
      cout << ans << endl;
      return;
    }
    else
    {
      ans = min(ans, odd / 2);
    }
    cout << ans << endl;
  }
}

//................................

// int

// int

// int

// int
