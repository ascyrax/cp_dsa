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

void suraj(int n);
vector<int> good, bad;

signed main()
{

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

  cin >> t;

  for (int i = 5; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj(i);
  }
  cout << "good.size()= " << good.size() << endl;
  cout << "bad.size() = " << bad.size() << endl;
  for (auto el : good)
    cout << el << " ";
  cout << endl;
  for (auto el : bad)
    cout << el << " ";
  cout << endl;

  return 0;
}

int inf = 1e18;
//.....................................
void print(vector<int> v)
{
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................
void check(vector<int> v)
{

  int first = v[0];
  int lenv = v.size();
  cout << "lenv = " << lenv << endl;
  cout << "v" << endl;
  print(v);
  set<int> sgcd;
  vector<int> vgcd;
  // for 3 and 5
  sgcd.insert(__gcd(3, 5));
  vgcd.pb(__gcd(3, 5));
  cout << "v[0] = " << v[0] << endl;
  for (int i = 1; i < lenv; i++)
  {
    int gcd = __gcd(v[i], v[0]);
    cout << "i = " << i << endl;
    cout << "v[i] = " << v[i] << endl;
    cout << "gcd = " << gcd << endl;
    if (gcd == i + 1)
    {
      vgcd.pb(__gcd(v[0], v[i]));
      sgcd.insert(__gcd(v[0], v[i]));
    }
  }
  if (sgcd.size() == lenv)
  {
    cout << "if" << endl;
    print(vgcd);
    good.pb(lenv);
  }
  else
  {
    cout << "else" << endl;
    print(vgcd);
    bad.pb(lenv);
  }
}
//.....................................

//.....................................

void suraj(int n)
{
  // int n;
  // cin >> n;
  if (n == 3)
    cout << 2 << " " << 3 << " " << 6 << endl;
  else if (n == 4)
    cout << 4 << " " << 24 << " " << 10 << " " << 15 << endl;
  else if (n >= 5)
  {
    // 3 and 5 produces the gcd 1.
    int a = 1;
    int sum = a;
    while (a <= n)
    {
      a *= 2;
      sum += a;
    }
    // a *= 2;
    // sum += a;
    // cout << "sum = " << sum << endl;
    vector<int> ans;
    ans.pb(sum);
    for (int i = 2; i <= n; i++)
    {
      ans.pb(i);
    }
    check(ans);
    // for (auto el : ans)
    //   cout << el << " ";
    // cout << endl;
  }
  // cout << __gcd(3, 5) << endl;
}
