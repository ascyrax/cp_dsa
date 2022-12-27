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
int mod = 1e9 + 7;
//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  cout << 2 << endl;
  vector<int> v(n + 1, true); // true means we gotta do sth.
  vector<int> ans;

  for (int i = 1; i <= n; i++)
  {
    if (v[i] == true)
    {
      int temp = i;
      while (temp <= n && v[temp] == true)
      {
        ans.pb(temp);
        v[temp] = false;
        temp *= 2;
      }
    }
    // print("ans", ans);
  }

  // for (int i = 2; i <= n; i += 2)
  // {
  //   if (v[i / 2] == true)
  //   {
  //     ans.pb(i / 2);
  //     ans.pb(i);
  //     v[i / 2] = false;
  //     v[i] = false;
  //   }
  //   else
  //   {
  //     ans.pb(i);
  //     v[i] = false;
  //   }
  // }
  // for (int i = 1; i <= n; i++)
  // {
  //   if (v[i])
  //     ans.pb(i);
  // }
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
}
