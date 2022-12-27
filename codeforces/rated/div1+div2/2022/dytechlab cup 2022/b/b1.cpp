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

  cout << setprecision(15) << fixed;

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
  int l, r;
  cin >> l >> r;

  // cout << l - r << endl;

  cout << "sqrts: " << sqrt(l) << " " << sqrt(r) << endl;

  int left = sqrt(l);
  int right = sqrt(r);
  cout << left << " " << right << endl;

  int remove = 0;

  // cout << left * left << " " << left * left + left << " " << l << endl;

  if (left * left < l)
    remove++;
  if (left * left + left < l)
    remove++;

  cout << "remove: " << remove << endl;

  if (r < right * right + 2 * right)
    remove++;
  if (r < right * right + right)
    remove++;

  cout << "remove: " << remove << endl;

  cout << (right - left + 1) * 3 - remove << endl;
}
