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
int calc2(int n)
{
  int cnt2 = 0;
  while (n % 2 == 0)
  {
    cnt2++;
    n /= 2;
  }
  return cnt2;
}
int calc5(int n)
{
  int cnt5 = 0;
  while (n % 5 == 0)
  {
    cnt5++;
    n /= 5;
  }
  return cnt5;
}
int findDigits(int n)
{
  int cnt = 0;
  while (n)
  {
    cnt++;
    n /= 10;
  }
  return cnt;
}
//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;

  int n2 = 0, n5 = 0;
  n2 = calc2(n);
  n5 = calc5(n);

  int mVal = 1ll; // value of the best multiplier for n.
  while (1)
  {
    if (n5)
    {
      if (mVal * 2ll <= m)
      {
        mVal *= 2ll;
        n5--;
      }
      else
        break;
    }
    else if (n2)
    {
      if (mVal * 5 <= m)
      {
        mVal *= 5;
        n2--;
      }
      else
        break;
    }
    else
      break;
  }

  int q = m / mVal;
  int nDigitsQ = findDigits(q);
  nDigitsQ--;
  int val = 1;
  while (nDigitsQ--)
    val *= 10;
  q = q / val;
  val *= q;
  cout << (n * mVal * val) << endl;
}
