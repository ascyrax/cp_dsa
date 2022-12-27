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
  int n, m;
  cin >> n >> m;

  int nDigitM = 0; // no of digits in m
  int m2 = m;
  while (m2)
  {
    nDigitM++;
    m2 /= 10;
  }
  nDigitM--;

  int rightN = 0; // rightmost non-zero digit of n
  int n2 = n;
  while (n2)
  {
    int rem = n2 % 10;
    if (rem > 0)
    {
      rightN = rem;
      break;
    }
    n2 /= 10;
  }

  int val = pow(10, nDigitM);
  // int ans = n * int(pow(10, nDigitM));
  int ans = 0;

  int mRem = m - (int)(pow(10, nDigitM)); // m after removing the most significant digit
  int mLeft2 = -1;                        // second most significant digit of m
  while (mRem)
  {
    mLeft2 = mRem % 10;
    mRem /= 10;
  }

  // ///////////////////////////

  if (rightN == 2)
  {
    if (m >= 5 * val)
      ans = n * 5 * val;
    else
    {
      ans = n * val;
      if (mLeft2 >= 5)
        ans += 1 * val;
    }
  }
  else if (rightN == 5)
  {
    if (m >= 8 * val)
      ans = n * 8 * val;
    if (m >= 4 * val)
      ans = n * 4 * val;
    else if (m >= 2 * val)
      ans = n * 2 * val;
    else
    {
      ans = n * val;
      if (mLeft2 >= 2)
        ans += 1 * val;
    }
  }
  else if (rightN == 4)
  {
    if (m >= 5 * val)
      ans = n * 5 * val;
    else if (m >= 2.5 * val)
      ans += 4 * 2.5 * val;
    else
    {
      ans = n * val;
      if (mLeft2 >= 5)
        ans += 2 * val;
    }
  }
  else
  {
    ans = n * val;
    if (val == 1)
    {
      ans = n * m;
    }
  }
  cout << ans << endl;
}
