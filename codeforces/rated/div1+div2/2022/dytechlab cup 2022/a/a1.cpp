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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> cnt(26, 0);

  for (int i = 0; i < n; i++)
  {
    cnt[s[i] - 'a']++;
  }

  vector<char> ans(k, '_');
  print("cnt", cnt);
  for (int i = 0; i < k; i++)
  {
    int val = n / k;

    while (val)
    {
      for (int j = 0; j <= 25; j++)
      {
        if (cnt[j] > 0)
        {
          cnt[j]--;
          val--;
        }
        else
        {
          if (ans[i] == '_')
          {
            ans[i] = 'a' + j;
          }
        }
        if (val == 0)
        {
          ans[i] = 'a' + j + 1;
          break;
        }
      }
    }
    // print("cnt", cnt);
  }

  for (auto el : ans)
    cout << el;
  cout << endl;
}
