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
int toOdd(int a)
{
  int cnt = 0;
  while (a % 2 == 0)
  {
    cnt++;
    a /= 2;
  }
  return cnt;
}
int toEven(int a)
{
  int cnt = 0;
  while (a % 2 != 0)
  {
    cnt++;
    a /= 2;
  }
  return cnt;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;
  for (int &i : v)
  {
    cin >> i;
    sum += i;
  }
  int minCnt = 1e9;
  for (auto el : v)
  {
    if (el % 2 == 1)
      minCnt = min(minCnt, toEven(el));
    else
      minCnt = min(minCnt, toOdd(el));
  }
  if (sum % 2 == 0)
    cout << 0 << endl;
  else
    cout << minCnt << endl;
}
