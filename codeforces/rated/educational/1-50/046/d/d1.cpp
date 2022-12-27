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
int mod = 998244353;
//.....................................
int fact(int n)
{
  // cout << "FACT: " << n << endl;
  int result = 1;
  while (n > 0)
  {
    result *= n;
    result %= mod;
    n--;
  }
  // cout << "result: " << result << endl;
  return result;
}
int binExp(int base, int exp)
{
  int ans = 1;
  // expBin = 1010010111101 sth
  int a = 1;
  while (a <= exp)
  {
    // cout << "a: " << a << endl;
    if ((a & exp) == a)
    {
      ans *= base;
      ans %= mod;
    }
    a *= 2;
    base *= base;
    base %= mod;
  }
  return ans;
}
int modInv(int num)
{
  // cout << "modInv: " << num << endl;
  int result = 1;
  //  since mod and num are prime
  // => modInv of num wrt modulus of mod = (num)to the power(mod-2)
  result = binExp(num, mod - 2);
  return result % mod;
}
int ncr(int n, int r)
{
  // cout << "ncr: " << n << " " << r << endl;
  if (r > n)
    return 0;
  else if (r == n)
    return 1;
  else if (r < n)
  {
    // int result = fact(n) / (fact(r) * fact(n - r));
    // cout << "r<n" << endl;
    // cout << "fact(" << n << "): " << fact(n) << endl;
    // cout << "modInv(fact(" << r << ")): " << modInv(fact(r)) << endl;
    // cout << "modInv(fact(" << n - r << ")): " << modInv(fact(n - r)) << endl;
    int result = (fact(n) * modInv(fact(r))) % mod;
    result = (result * modInv(fact(n - r))) % mod;
    return result;
  }
}
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
  // print("v", v);

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    // cout << "i: " << i << endl;
    // cout << "n: " << n - 1 - i << " , c: " << v[i] << endl;
    ans += ncr(n - 1 - i, v[i]);
    // cout << "ans: " << ans << endl;
    ans %= mod;
  }
  cout << ans << endl;
}
