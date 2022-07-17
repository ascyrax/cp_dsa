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
  string s;
  cin >> s;

  map<char, int> m;
  for (int i = 0; i < n; i++)
  {
    m[s[i]]++;
  }
  for (auto el : m)
  {
    if (el.second & 1)
    {
      cout << "NO" << endl;
      return;
    }
  }

  map<char, int> m1, m2;
  for (int i = 0; i < n; i += 2)
    m1[s[i]]++;
  for (int i = 1; i < n; i += 2)
    m2[s[i]]++;
  for (int i = 0; i <= 25; i++)
  {
    char ch = 'a' + i;
    if (m1.count(ch) != m2.count(ch))
    {
      cout << "NO" << endl;
      return;
    }
    else
    {
      if (m1.count(ch))
      {
        if (m1[ch] != m2[ch])
        {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }

  cout << "YES" << endl;
}
