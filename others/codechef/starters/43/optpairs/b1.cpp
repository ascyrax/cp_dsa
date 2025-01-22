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
//.....................................

//.....................................
int g(int a, int b)
{
  // cout << "a = " << a << ", b = " << b << endl;
  return (__gcd(a, b) * __gcd(a, b) + a * b) / __gcd(a, b);
}
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  // minG will always be equal to n itself.
  int minG = n; // g(1ll, n - 1ll); // => f = minG
  int nFactors = 0;
  int i = 1;
  vector<int> factors;
  factors.pb(i); // for i=1 , we wont add n/i i.e. n to the factor cnt.
  nFactors++;
  for (i = 2; i * i < n; i++)
  {
    if (n % i == 0)
    {
      factors.pb(i);
      nFactors++;
      if (n % (n / i) == 0)
      {
        nFactors++;
        factors.pb(n / i);
      }
    }
  }
  // for (auto el : factors)
  //   cout << el << " ";
  // cout << endl;
  nFactors *= 2;
  if (i * i == n)
  {
    factors.pb(i);
    nFactors++;
  }
  cout << nFactors << endl;
}
