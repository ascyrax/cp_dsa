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

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
int lcs(string a, string b)
{
  int lena = a.size();
  int lenb = b.size();
  if (lena == 0 || lenb == 0)
    return 0;
  if (a[lena - 1] == b[lenb - 1])
  {
    return 1 + lcs(a.substr(0, lena - 1), b.substr(0, lenb - 1));
  }
  else
  {
    return max(lcs(a.substr(0, lena - 1), b), lcs(a, b.substr(0, lenb - 1)));
  }
}
//.....................................

void suraj()
{
  string a, b;
  cin >> a >> b;

  int llcs = lcs(a, b);
  cout << max(b.size(), a.size()) - llcs << endl;
}
