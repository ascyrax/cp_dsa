// dp

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
const int N = 2e5 + 7;
pair<int, int> dp[N][2];
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '0')
      v[i] = 0;
    else
      v[i] = 1;
  }
  // print("v", v);
  // pair<int, int> dp[N][2];
  // dp[i][0].first = min no of steps required to convert the the first i nos into a good subsegment
  // dp[i][1].second = min no of continguous subsegments (each bit same)
  int ptr = -1;
  for (int i = 0; i < n; i += 2)
  {
    // cout << "i: " << i << endl;
    if (v[i] == v[i + 1])
    {
      ptr = v[i];
      break;
    }
  }
  if (ptr == -1)
    ptr = 1;

  // cout << "ptr: " << ptr << endl;

  if (v[0] == v[1])
  {
    if (v[0] == 0)
    {
      dp[1][0] = make_pair(0, 1);
      dp[1][1] = make_pair(2, 1);
    }
    else if (v[0] == 1)
    {
      dp[1][0] = make_pair(2, 1);
      dp[1][1] = make_pair(0, 1);
    }
  }
  else if (v[0] != v[1])
  {
    dp[1][0] = make_pair(1, 1);
    dp[1][1] = make_pair(1, 1);
  }

  // cout << dp[1][0].first << " " << dp[1][0].second << endl;
  // cout << dp[1][1].first << " " << dp[1][1].second << endl;

  for (int i = 3; i < n; i += 2)
  {
    int cost0 = 0, cost1 = 0;
    if (v[i] == v[i - 1])
      if (v[i] == 0)
        cost1 = 2;
      else
        cost0 = 2;
    else
      cost0 = 1, cost1 = 1;
    // cout << "i: " << i << endl;
    // cout << "cost0: " << cost0 << " , cost1: " << cost1 << endl;
    // 0
    dp[i][0].first = min(dp[i - 2][0].first, dp[i - 2][1].first) + cost0;
    if (dp[i - 2][0].first <= dp[i - 2][1].first)
      dp[i][0].second = dp[i - 2][0].second;
    else
      dp[i][0].second = dp[i - 2][1].second + 1;
    // 1
    dp[i][1].first = min(dp[i - 2][0].first, dp[i - 2][1].first) + cost1;
    if (dp[i - 2][1].first <= dp[i - 2][0].first)
      dp[i][1].second = dp[i - 2][1].second;
    else
      dp[i][1].second = dp[i - 2][0].second + 1;
  }

  if (dp[n - 1][0].first < dp[n - 1][1].first)
  {
    cout << dp[n - 1][0].first << " " << dp[n - 1][0].second << endl;
  }
  else if (dp[n - 1][0].first > dp[n - 1][1].first)
  {
    cout << dp[n - 1][1].first << " " << dp[n - 1][1].second << endl;
  }
  else
  {
    cout << dp[n - 1][0].first << " " << min(dp[n - 1][0].second, dp[n - 1][1].second) << endl;
  }
}
