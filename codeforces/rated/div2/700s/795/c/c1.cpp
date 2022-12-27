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

  int cnt0 = 0, cnt1 = 0;
  for (char c : s)
  {
    if (c == '1')
      cnt1++;
    else
      cnt0++;
  }

  int sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    string sub = s.substr(i, 2);
    if (sub == "11")
      sum += 11;
    else if (sub == "10")
      sum += 10;
    else if (sub == "01")
      sum += 1;
    else if (sub == "00")
      sum += 0;
  }

  if (sum == 0) // ie cnt1=0
  {
    cout << 0 << endl;
    return;
  }

  // cout << "sum = " << sum << endl;

  if (s[0] == '1' && s[n - 1] == '1')
  {
    cout << sum << endl;
  }
  else
  {
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        left = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] == '1')
      {
        right = n - 1 - i;
        break;
      }
    }

    if (cnt1 == 1)
    {
      if (left == 0)
      {
        if (right <= k)
        {
          sum -= 10;
          sum += 1;
        }
      }
      else if (right == 0)
      {
        sum = sum; // i.e. sum=1
      }
      else
      {
        // just one 1
        if (right <= k)
        {
          sum -= 10;
        }
        else if (left <= k)
        {
          sum -= 1;
        }
      }
    }
    else if (cnt1 >= 2)
    {
      if (left == 0)
      {
        if (right <= k)
          sum -= 10;
      }
      else if (right == 0)
      {
        if (left <= k)
          sum -= 1;
      }
      else
      {
        if (right <= k)
          sum -= 10;
        k -= right;
        if (left <= k)
          sum -= 1;
        k -= left;
      }
    }

    cout << sum << endl;
  }
}
