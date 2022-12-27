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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;
  sort(v.begin(), v.end());
  int prod = v[0] * v[n - 1];

  set<int> divisors;
  for (int i = 2; i * i <= prod; i++)
  {
    if (prod % i == 0)
    {
      divisors.insert(i);
      divisors.insert(prod / i);
    }
  }
  vector<int> temp;
  for (auto el : divisors)
    temp.pb(el);
  // for (int i = 0; i < n; i++)
  // {
  //   int prodTemp = v[i] * v[n - 1 - i];
  //   if (prodTemp != prod)
  //   {
  //     cout << -1 << endl;
  //     return;
  //   }
  // }
  if (temp != v)
    cout << -1 << endl;
  else
    cout << prod << endl;
}
