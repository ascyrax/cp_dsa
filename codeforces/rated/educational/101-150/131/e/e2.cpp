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
int lens, lent;
string s, t;
vector<vector<int>> dp;
//.....................................
bool check()
{
  // if t is a subsequence of s, return true.
  int ptrS = 0; // ptrS will go till lens.
  for (int i = 0; i < lent; i++)
  {
    if (ptrS == lens)
      return false;
    while (t[i] != s[ptrS])
    {
      if (ptrS == lens - 1)
      {
        return false;
      }
      ptrS++;
    }
    if (t[i] == s[ptrS])
    {
      cout << "i : " << i + 1 << " , ptrS: " << ptrS + 1 << endl;
      ptrS++;
    }
  }
  return true;
}
//.....................................

void suraj()
{
  cin >> lens >> lent;
  cin >> s >> t;
  dp = vector<vector<int>>(lens, vector<int>(lent, inf));

  // if t is not a subsequence of s => print -1;
  if (check())
  {
    for (int i = 0; i < lens; i++)
    {
      for (int j = 0; j < lent; j++)
      {
        if (s[i] == t[j])
        {
          if (i - 1 >= 0 && j - 1 >= 0)
          {
            if (dp[i - 1][j - 1] > 0)
              dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
            else
              dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // deleting the ith char of s.
          }
          else if (i - 1 >= 0)
          {
            // i.e. j==0
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // deleting the ith char of s.
            dp[i][j] = min(dp[i][j], i + 1);            // shifting 1 to the left and deleting all chars before the ith char of s.
          }
          else if (j - 1 >= 0)
          {
            // i.e. i==0
            if (j > i)
              dp[i][j] = dp[i][j];
            // else if (j == i)
            // {
            //   // i.e. j==0
            //   dp[i][j] = 0;
            // }
          }
          else
          {
            // i.e. i==0 and j==0
            dp[i][j] = 0; // they are already equal
          }
        }
        else if (s[i] != t[j])
        {
          if (i - 1 >= 0)
          {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // deleting the last char of s.
          }
          else if (i == 0)
          {
            // i.e. i==0
            if (j > i)
              dp[i][j] = dp[i][j];
            else if (j == i)
            {
              // i.e. j==0
              dp[i][j] = inf;
            }
          }
        }
      }
    }
    cout << dp[lens - 1][lent - 1] << endl;
  }
  else
    cout << -1 << endl;
  // cout << "-----" << endl;
  // for (int i = 0; i < lens; i++)
  //   cout << dp[i][0] << " ";
  // cout << endl;
  // for (int i = 0; i < lens; i++)
  //   cout << dp[i][1] << " ";
  // cout << endl;
  // for (int i = 0; i < lens; i++)
  //   cout << dp[i][2] << " ";
  // cout << endl;
  // for (int i = 0; i < lens; i++)
  //   cout << dp[i][3] << " ";
  // cout << endl;
  // // cout << dp[2][1] << endl;
  // cout << "-----" << endl;
  // for (int i = 0; i < lens; i++)
  //   cout << dp[i][lent - 1] << endl;
}
