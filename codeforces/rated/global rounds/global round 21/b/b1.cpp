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
  int cnt0 = 0;
  int left = 0, right = 0;
  for (int &i : v)
  {
    cin >> i;
    if (i == 0)
      cnt0++;
  }

  if (cnt0 == n)
  {
    cout << 0 << endl;
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (v[i] == 0)
      left++;
    else
      break;
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (v[i] == 0)
      right++;
    else
      break;
  }

  if (cnt0 == 0)
  {
    cout << 1 << endl;
  }
  else
  {
    if (cnt0 == left + right)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
