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

  // cin>>t;

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
  string a, b;
  cin >> a >> b;

  if (a == b)
  {
    cout << "YES" << endl;
    return;
  }

  int lena = a.size();
  int lenb = b.size();

  if (lena != lenb)
  {
    cout << "NO" << endl;
    return;
  }

  int a1 = 0, a0 = 0, b1 = 0, b0 = 0;
  for (int i = 0; i < lena; i++)
  {
    if (a[i] == '1')
      a1++;
    else
      a0++;
    if (b[i] == '1')
      b1++;
    else
      b0++;
  }

  if (a1 == 0)
  {
    cout << "NO" << endl;
    return;
  }

  if (b1 == 0)
  {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;

  // a1>0
  // int l = -1, r = lena + 1;
  // for (l = 0; l < lena; l++)
  // {
  //   if (b[l] == '1')
  //     break;
  // }
  // for (r = lena - 1; r >= 0; r--)
  // {
  //   if (b[r] == '1')
  //     break;
  // }

  // 11 -> 01 or 10
  // 01 -> 11
  // 10 -> 11
  // 00 -> 00
}
