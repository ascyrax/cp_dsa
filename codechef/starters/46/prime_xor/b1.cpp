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
  int x, y;
  cin >> x >> y;

  int z = x ^ y;

  int odd = 0, even = 0;
  if (x & 1)
    odd++;
  else
    even++;
  if (y & 1)
    odd++;
  else
    even++;
  if (z & 1)
    odd++;
  else
    even++;

  // 2 odd 1 even for x,y,z
  // => for a,b,c
  // => 2odd 1even OR 2even 1odd
  // 2even 1odd can happen since a,b,c are 3 distinct primes
  set<int> s;
  s.insert(2);
  if (x & 1)
    s.insert(2 ^ x);
  if (y & 1)
    s.insert(2 ^ y);
  if (z & 1)
    s.insert(2 ^ z);
  for (auto el : s)
    cout << el << " ";
  cout << endl;
}
