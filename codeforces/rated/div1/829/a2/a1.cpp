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
  vector<int> v(n);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    sum += v[i];
  }

  // check for possibility
  // cout << (sum % 2) << endl;
  if (sum % 2 != 0)
  {
    cout << -1 << endl;
    return;
  }

  sum /= 2;

  vector<pair<int, int>> ans;
  if (sum == 0)
  {
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
      cout << i << " " << i << endl;
    }
    return;
  }
  else
  {
    // change |sum| no of 1 to -1 greedily from the left to right
    for (int i = 0; abs(sum) > 0 && i <= n - 2; i++)
    {
      if (v[i + 1] == sum / abs(sum))
      {
        ans.pb(make_pair(i, i + 1));
        if (sum > 0)
          sum--;
        else if (sum < 0)
          sum++;
        i++;
      }
      else
        ans.pb(make_pair(i, i));
    }
    int last = ans[ans.size() - 1].second;
    for (int i = last + 1; i < n; i++)
    {
      ans.pb(make_pair(i, i));
    }
  }

  cout << ans.size() << endl;
  for (auto el : ans)
    cout << el.first + 1 << " " << el.second + 1 << endl;
}
