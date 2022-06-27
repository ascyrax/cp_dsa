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
  set<int> s;

  for (int i = 0; i < 30; i++)
  {
    cout << "i = " << i << endl;
    bool flag = false;
    for (int j = 0; j < n; j++)
    {
      // cout << "j  = " << j << endl;
      // cout << "v[j] = " << v[j] << endl;
      // cout << "1<<i = " << (1 << i) << endl;
      if ((v[j] & (1 << i)) == 0)
      {
        cout << "found = " << j << endl;
        flag = true;
        break;
      }
    }

    cout << "flag = " << flag << endl;

    if (!flag)
      continue;

    for (int j = 0; j < n; j++)
    {
      if ((v[j] & (1 << i)))
      {
        cout << "j = " << j << endl;
        s.insert(j);
      }
    }

    cout << "s" << endl;
    for (auto el : s)
      cout << el << " ";
    cout << endl;
  }

  if (s.size() == n)
    cout << s.size() - 1 << endl;
  else
    cout << s.size() << endl;
}
