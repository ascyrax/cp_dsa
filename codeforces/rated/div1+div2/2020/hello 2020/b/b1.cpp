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

  // ioss

  // startTime=(double)clock();

  // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

  // cout << setprecision(15) << fixed;

  int t = 1;

  // cin >> t;

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
bool check(vector<int> v)
{
  int mn = v[0];
  for (int i = 1; i <= v.size() - 1; i++)
  {
    if (v[i] > mn)
      return true;
    mn = min(mn, v[i]);
  }
  return false;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> mnArr(1e6 + 1, 0), mxArr(1e6 + 1, 0);
  int nAscent = 0;
  for (int i = 0; i < n; i++)
  {
    int len;
    cin >> len;
    int mn = 1e9;
    int mx = 0;
    vector<int> tempArr(len);
    for (int j = 0; j < len; j++)
    {
      cin >> tempArr[j];
      mn = min(mn, tempArr[j]);
      mx = max(mx, tempArr[j]);
    }

    // check if tempArr has an ascent
    if (check(tempArr))
    {
      // mnArr[0]++;
      nAscent++;
      // mxArr[mx + 1]++;
    }
    else
    {
      mnArr[mn]++;
      mxArr[mx]++;
    }
  }

  for (int i = 1e6 - 1; i >= 0; i--)
    mxArr[i] += mxArr[i + 1];
  int ans = 0;
  ans += nAscent * n;
  for (int i = 0; i <= 1e6; i++)
  {
    int right = mxArr[i + 1];
    ans += mnArr[i] * (right + nAscent);
  }
  cout << ans << endl;
}
