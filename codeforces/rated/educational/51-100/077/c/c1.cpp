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

//.....................................

void suraj()
{
  int r, b, k;
  cin >> r >> b >> k;

  if (r == b)
  {
    cout << "OBEY" << endl;
    return;
  }

  int mnrb = min(r, b);
  int mxrb = max(r, b);

  int q = mxrb / mnrb;

  if ((mxrb % mnrb) == 0)
  {
    q = max(0ll, q - 1);
  }
  if (q >= k)
    cout << "REBEL" << endl;
  else
    cout << "OBEY" << endl;

  // edge case => 6 & 10.
}
