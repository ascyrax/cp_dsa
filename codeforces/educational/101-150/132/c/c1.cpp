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
  string s;
  cin >> s;
  int lens = s.size();
  int l = 0, r = 0, qm = 0;

  int i = 0;
  bool flag = false;
  for (i = 0; i < lens; i++)
  {
    if (s[i] == '(')
      l++;
    else if (s[i] == ')')
      r++;
    else if (s[i] == '?')
    {
      s[i] = '(';
      l++;
    }
    if (l == lens / 2)
    {
      for (int j = i + 1; j < lens; j++)
      {
        cout << "j: " << j << endl;
        if (s[j] == '?')
        {
          l--;
          r++;
          cout << "l: " << l << " , r: " << r << endl;
          if (l < r)
          {
            // this cant be => unique RBS only possible
            cout << "YES" << endl;
            return;
          }
          for (int k = i + 1; k <= j; k++)
          {
            if (s[i] == '(')
              l++;
            else if (s[i] == ')')
              r++;
            if (l < r)
            {
              cout << "YES" << endl;
              return;
            }
          }
          cout << "NO" << endl;
          return;
        }
      }
      cout << "YES" << endl;
      return;
    }
  }
}
