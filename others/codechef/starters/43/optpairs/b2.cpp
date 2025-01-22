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

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;

  vector<int> factors;
  int nFactors = 0;

  factors.pb(1); // for i=1 , we wont add n/i i.e. n to the factor cnt.
  nFactors++;

  int i = 1;
  for (i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      factors.pb(i);
      nFactors++;
      if (n % (n / i) == 0 && (n / i != i))
      {
        nFactors++;
        factors.pb(n / i);
      }
    }
  }

  int nPairs = nFactors * 2;

  if (n % 2 == 0)
  {
    // => n/2 will also be in the list of factors
    nPairs--;
    // since we counted (n/2,n/2) twice for g(a,b)=n.
  }
  cout << nPairs << endl;
}
