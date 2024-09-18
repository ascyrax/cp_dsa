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
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  int l = 0, r = n - 1;
  bool flag = true;
  while (l < r)
  {
    if (flag)
    {
      while (s[l] == '0')
        l++;
      if (l >= r)
        break;
      while (s[r] == '1')
        r--;
      if (l >= r)
        break;
      else
      {
        ans++;
        l++;
        r--;
        flag = !flag;
      }
    }
    else
    {
      while (s[l] == '1')
        l++;
      if (l >= r)
        break;
      while (s[r] == '0')
        r--;
      if (l >= r)
        break;
      else
      {
        ans++;
        l++;
        r--;
        flag = !flag;
      }
    }
  }
  cout << ans << endl;
}
