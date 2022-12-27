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
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    m[v[i]].pb(i + 1);
  }

  for (auto &el : m)
  {
    if (el.second.size() == 1)
    {
      cout << -1 << endl;
      return;
    }
    else if ((el.second.size() % 2) == 1)
    {
      // cout << "hi" << endl;
      int last = el.second.back();
      int mid = el.second[el.second.size() / 2];
      // cout << "last = " << last << endl;
      // cout << "mid = " << mid << endl;
      // cout << el.second.size() << endl;
      el.second.erase(el.second.begin() + (el.second.size() / 2));
      // cout << el.second.size() << endl;
      el.second.pb(mid);
    }
  }

  // cout << "m" << endl;
  // for (auto el : m)
  // {
  //   cout << "el.first = " << el.first << endl;
  //   cout << "el.second.size = " << el.second.size() << endl;
  //   for (auto i : el.second)
  //     cout << i << " ";
  //   cout << endl;
  // }

  vector<int> ans(n);

  for (int i = 0; i < n; i++)
  {
    ans[i] = m[v[i]].back();
    m[v[i]].pop_back();
  }
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
}
