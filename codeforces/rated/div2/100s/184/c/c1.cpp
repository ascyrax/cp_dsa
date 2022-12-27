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

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int cnt = 1;
  int val = v[0];

  map<int, int> finalCnt;

  for (int i = 1; i < n; i++)
  {
    if (v[i] == val)
    {
      cnt++;
    }
    else
    {
      if (cnt % 2 != 0)
        finalCnt[val] = 1;
      cnt = cnt / 2;
      val++;

      while (cnt > 0 && val < v[i])
      {
        if (cnt % 2 == 1)
          finalCnt[val] = 1;
        cnt /= 2;
        val++;
      }
      if (cnt == 0)
      {
        val = v[i];
        cnt = 1;
      }
      else if (v[i] == val)
        cnt++;
    }
  }
  while (cnt > 0)
  {
    if (cnt % 2 != 0)
      finalCnt[val] = 1;
    val++;
    cnt = cnt / 2;
  }
  int mxVal = 0;
  for (auto el : finalCnt)
    mxVal = max(mxVal, el.first);

  cout << (mxVal + 1 - finalCnt.size()) << endl;
}
