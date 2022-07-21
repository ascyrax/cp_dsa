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
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int k1;
  cin >> k1;
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  k1--;
  // if (v[0])
  //   v[0]--;
  // if (v[1])
  //   v[1]--;
  // if (v[2])
  //   v[2]--;
  // cout << k1 << " " << v[0] << " " << v[1] << " " << v[2] << endl;
  if (v[k1] == 0)
  {
    cout << "NO" << endl;
    return;
  }
  else
  {
    k1 = v[k1];
    k1--;
  }
  if (v[k1] == 0)
  {
    cout << "NO" << endl;
    return;
  }
  else
  {
    k1 = v[k1];
  }
  cout << "YES" << endl;
}
