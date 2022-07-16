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
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n, x;
  cin >> n >> x;
  int mxp2 = 1; // mxPowOf2
  while (mxp2 < n)
  {
    mxp2 *= 2;
  }
  if (mxp2 > n)
    mxp2 /= 2;

  int rem = n % 4;
  int mxPossible = mxp2 * 2 - 1;
  if (x > mxPossible)
  {
    cout << -1 << endl;
    return;
  }

  if (n == 2)
  {
    if (x != 3)
      cout << -1 << endl;
    else
      cout << "1 1 2" << endl;
    return;
  }
  else if (n == 3)
  {
    if (x == 1)
    {
      cout << "1 1 3" << endl;
      cout << "2 2 3" << endl;
    }
    else if (x == 2)
    {
      cout << "1 2 3" << endl;
      cout << "2 1 3" << endl;
    }
    else if (x == 3)
    {
      cout << "1 1 2" << endl;
      cout << "1 2 3" << endl;
    }
    else
      cout << -1 << endl;
    return;
  }
  // there will be some more cases for which ans = - 1. i will check those later.
  vector<vector<int>> ans;
  int left = 0, right = mxp2;
  // cout << "mxp2: " << mxp2 << endl;
  if (x > n)
  {
    // cout << "if" << endl;
    // if rem==3 => ((mxp2+1)|(mxp2+2)^(mxp2+3))=0   mxp2 -> x
    // if rem==2 => ((mxp2+1)^(mxp2+2))=3 mxp2=mxp2|3     mxp2+3->x
    // if rem==1 => (mxp2=mxp2|(mpx2+1)=>mxp2=mxp2+1)   mxp2+1 -> x
    // if rem==0 => mxp2->x
    if (rem == 3)
    {
      ans.pb({1, mxp2 + 1, mxp2 + 2});
      ans.pb({2, mxp2 + 3, mxp2 + 3});
      // ans.pb({2, mxp2, x});
      right = mxp2;
      // ans.pb({2, x, mxp2});
      // now create left in 1....(mxp2-1)
      // after creating left xor it with right
    }
    else if (rem == 2)
    {
      ans.pb({2, mxp2 + 1, mxp2 + 2});
      ans.pb({1, mxp2, 3});
      // ans.pb({2, mxp2 + 3, x});
      right = mxp2 + 3;
      // ans.pb({1, x, mxp2 + 3});
    }
    else if (rem == 1)
    {
      ans.pb({1, mxp2, mxp2 + 1});
      // ans.pb({2, mxp2 + 1, x});
      right = mxp2 + 1;
      // ans.pb({1, x, mxp2 + 1});
    }
    else if (rem == 0)
    {
      // ans.pb({2, mxp2, x});
      right = mxp2;
      // ans.pb({1, x, mxp2});
    }
  }
  else if (x <= n && x >= mxp2)
  {
    // cout << "else if" << endl;
    if (rem == 3)
    {
      ans.pb({1, mxp2 + 1, mxp2 + 2});
      ans.pb({2, mxp2 + 3, mxp2 + 3});
      // mxp2 remains
      right = mxp2;
    }
    else if (rem == 2)
    {
      ans.pb({2, mxp2, mxp2 + 1});
      // 1 left
      ans.pb({2, mxp2 + 2, 1});
      // mxp2+3 remains
      right = mxp2 + 3;
    }
    else if (rem == 1)
    {
      ans.pb({1, mxp2, mxp2 + 1});
      right = mxp2 + 1;
    }
    else if (rem == 0)
    {
      right = mxp2;
    }
  }
  else if (x < mxp2)
  {
    // cout << "else" << endl;
    // left = x;
    if (rem == 3)
    {
      ans.pb({2, mxp2, mxp2 + 1});
      ans.pb({2, 1, mxp2 + 2});
      ans.pb({2, mxp2 + 3, mxp2 + 3});
      right = 0;
    }
    else if (rem == 2)
    {
      ans.pb({1, mxp2, mxp2 + 1});
      ans.pb({2, mxp2 + 1, mxp2 + 2});
      // 3 will be obtained
      right = 3;
      // ans.pb({2, x, 3});
    }
    else if (rem == 1)
    {
      ans.pb({2, mxp2, mxp2 + 1});
      right = 1;
      // ans.pb({2, x, 2});
    }
    else if (rem == 0)
    {
      cout << -1 << endl;
      return;
    }
  }
  left = x ^ right;
  // what if this left>n-1. this will lead to an error.
  int prev = 1;
  for (int i = 2; i <= mxp2 - 1; i++)
  {
    if (i != left)
    {
      ans.pb({2, prev, i});
      prev = prev ^ i;
    }
  }
  // cout << "left: " << left << endl;
  // cout << "right: " << right << endl;
  ans.pb({1, left, left});  // e.g. n=4, x=7 ->ie. 1 2 3 4 => step 1: 1^2 => 3 3 7 => stpe 2: 3^3 => 3 4 (left,right) => step 3: left ^ right = 3^4 = 7.
  ans.pb({2, left, right}); // == {2,prev,right}
  // left ^ right will give = x.
  for (auto el : ans)
    cout << el[0] << " " << el[1] << " " << el[2] << endl;
  // cout << "-----------" << endl;
}
