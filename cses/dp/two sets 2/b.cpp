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

  // ioss

  // startTime=(double)clock();

  // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

  // cout << setprecision(15) << fixed;

  int t = 1;

  // cin >> t;

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
// int mod = 998244353;
//.....................................

//.....................................

//.....................................
// this wont work because we are missing many cases like (1+2+4),(1+3+4),etc.
void suraj()
{
  int mod = 1e9 + 7;
  int n;
  cin >> n;

  map<int, int> cnt;
  for (int i = 1; i <= n; i++)
  {
    auto temp = cnt;
    for (auto el : temp)
    {
      // cout << "hi " << el.first << " " << el.second << endl;
      cnt[el.first + i]++;
      cnt[el.first + 1] %= mod;
    }
    cnt[i]++;
  }
  // cout << "--" << endl;
  // for (auto el : cnt)
  //   cout << el.first << " " << el.second << endl;
  int sumN = (n * (n + 1)) / 2;
  if (sumN % 2 == 1)
    cout << 0 << endl;
  else
    cout << cnt[sumN / 2] << endl;
}
