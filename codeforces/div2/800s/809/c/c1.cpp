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
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  int nCool = (n - 1) / 2;
  int ans = 0;
  if (n & 1)
  {
    for (int i = 1; i < n; i += 2)
    {
      int left = h[i - 1] - h[i];
      int right = h[i + 1] - h[i];
      if (left < 0 && right < 0)
        ans += 0;
      else
      {
        int mx = max(left, right);
        if (mx == 0)
          ans += 1;
        else
          ans += mx + 1;
      }
    }
  }
  else
  {
    vector<int> leftSum(n, 0);
    for (int i = 1; i < n; i += 2)
    {
      int left = h[i - 1] - h[i];
      int right = h[i + 1] - h[i];
      if (left < 0 && right < 0)
        ans += 0;
      else
      {
        int mx = max(left, right);
        if (mx == 0)
          ans += 1;
        else
          ans += mx + 1;
      }
      leftSum[i] = ans;
    }
    vector<int> rightSum(n, 0);
    ans = 0;
    for (int i = n - 2; i >= 0; i -= 2)
    {
      if (i == 0)
        break;
      int left = h[i - 1] - h[i];
      int right = h[i + 1] - h[i];
      if (left < 0 && right < 0)
        ans += 0;
      else
      {
        int mx = max(left, right);
        if (mx == 0)
          ans += 1;
        else
          ans += mx + 1;
      }
      rightSum[i] = ans;
    }
    ans = 0;
    ans = rightSum[2]; // leftSum Contributed 0.
    // i.e. cool are -> 2 4 6 8 ....
    // say i skip the ith building and make the i+1th building cool
    for (int i = 1; i < n; i += 2)
    {
      // cool are 1,3,5,,,,i,i+3,i+5......n-1
      if (i == n - 1)
        break;
      else if (i == n - 3)
        ans = min(ans, leftSum[i] + 0);
      else
        ans = min(ans, leftSum[i] + rightSum[i + 3]);
    }
  }
  cout << ans << endl;
}
