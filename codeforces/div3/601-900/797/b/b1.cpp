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
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  map<int, int> diff;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < b[i])
    {
      cout << "NO" << endl;
      return;
    }
    else
    {
      if (b[i] != 0)
        diff[a[i] - b[i]]++;
    }
    if (diff.size() > 1)
    {
      cout << "NO" << endl;
      return;
    }
  }
  // diff.size() == 1
  if (diff.size() == 0)
  {
    cout << "YES" << endl;
    return;
  }
  int val;
  for (auto el : diff)
    val = el.first;
  for (int i = 0; i < n; i++)
  {
    if (b[i] == 0)
    {
      if (a[i] - b[i] > val)
      {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
