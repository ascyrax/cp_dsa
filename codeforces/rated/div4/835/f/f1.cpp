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
  int n, c, d;
  cin >> n >> c >> d;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  sort(v.rbegin(), v.rend());

  int sumN = 0;
  for (int i : v)
    sumN += i;

  vector<int> ps(n + 1, 0);
  ps[1] = v[0];
  for (int i = 2; i <= n; i++)
  {
    ps[i] = ps[i - 1] + v[i - 1];
  }

  if (ps[min(n, d)] >= c)
    cout << "Infinity" << endl;
  else
  {
    // check for k=0
    if (v[0] * d < c)
    {
      cout << "Impossible" << endl;
      return;
    }
    int ans = 0;
    // check for k<=n-1
    for (int k = n - 1; k > 0; k++)
    {
      int sum = ps[k + 1] - ps[0];
      int sReq = c;
      int nDays = (sReq / sum) * (k + 1);
      sReq -= (nDays / (k + 1)) * sum;
      auto it = lower_bound(ps.begin(), ps.end(), sReq) - ps.begin();
      nDays += it;
      if (nDays <= d)
      {
        ans = k;
        break;
      }
    }
    if (ans < n - 1)
    {
      cout << ans << endl;
      return;
    }
    // check for k >= n.
    // for (int i = n - 1; i >= 0; i--)
    // {
    //   int nDays = (c / sum) * (i + 1) + (c - (c / sum) * sum) % ;
    // }

    cout << ans << endl;
  }
}
