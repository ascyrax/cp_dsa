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
  vector<int> v(101, 0);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v[a]++;
  }

  // print("v", v);

  vector<int> ps(101, 0);
  for (int i = 1; i <= 100; i++)
  {
    ps[i] = ps[i - 1] + v[i];
  }

  // print("ps", ps);

  int ans = 0;

  for (int k = 1; k <= 100; k++)
  {
    // check if k is correct or not
    int flag = 0;
    for (int i = 1; i <= k; i++)
    { // (k-1) because of bob and  + i because of alice
      // e.g. bob removes 1 (k-1) times
      // bob removes 2 0 times, 3 also 0 times and so on.
      // viz. for a valid k, bob always removes 1 in every step
      if (ps[i] >= (k - 1) + i)
      {
        continue;
      }
      else
      {
        flag = -1;
        break;
      }
    }
    if (flag == -1)
      break;
    else
      ans = k;
  }
  cout << ans << endl;
}
