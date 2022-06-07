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

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  vector<int> v2 = v;

  sort(v.begin(), v.end());
  sort(v2.rbegin(), v2.rend());

  vector<int> diff1, diff2;
  for (int i = 1; i < n; i++)
  {
    diff1.pb(v[i] - v[i - 1]);
  }

  int pos = 0, neg = 0;
  for (int i : diff1)
  {
    if (i > 0)
      pos++;
    else if (i < 0)
      neg++;
  }

  if (pos > 0 && neg > 0)
  {
    cout << "NO" << endl;
    return;
  }
  else
  {
    for (int i = 1; i < diff1.size(); i++)
    {
      int a = diff1[i - 1];
      int b = diff1[i];
      if (a * 2 == b || a == b * 2)
      {
        continue;
      }
      else
      {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
}
