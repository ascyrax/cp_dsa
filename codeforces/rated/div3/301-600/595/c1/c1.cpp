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

void suraj(vector<int> v);

signed main()
{

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int a = 1;
  vector<int> v;
  while (a <= 1e4)
  {
    v.pb(a);
    a *= 3;
  }
  v.pb(a);

  int t = 1;

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj(v);
  }

  return 0;
}

int inf = 1e18;
//.....................................

//.....................................

//.....................................

//.....................................

void suraj(vector<int> v)
{
  int n;
  cin >> n;

  if (n == 1)
  {
    cout << 1 << endl;
  }
  else if (n == 2 || n == 3)
  {
    cout << 3 << endl;
  }
  else
  {
    vector<int> combinations;
    // generate all subsets of v.
    // method 1

    for (int i = 0; i < v.size(); i++)
    {
      int combsize = combinations.size();
      for (int j = 0; j < combsize; j++)
      {
        combinations.pb(v[i] + combinations[j]);
      }
      combinations.pb(v[i]);
    }
    cout << "combinations" << endl;
    for (auto el : combinations)
      cout << el << " ";
    cout << endl;

    sort(combinations.begin(), combinations.end());
    auto it = lower_bound(combinations.begin(), combinations.end(), n);
    cout << *it << endl;
    // method 2 -> generate all combinations using recursion
  }
}
