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

      // cout << setprecision(1ll5) << fixed;

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
int check(int cur, int checkVal, int a, int b, int c)
{
  int right = cur;
  if ((1ll << checkVal) & a)
    right = checkVal;
  if ((1ll << checkVal) & b)
    right = checkVal;
  if ((1ll << checkVal) & c)
    right = checkVal;
  return right;
}
//.....................................

void suraj()
{
  int a, b, c;
  cin >> a >> b >> c;

  int right = 0, righta = 0, rightb = 0, rightc = 0;
  for (int i = 0; i <= 40; i++)
  {
    if ((1ll << i) & a)
    {
      righta = i;
      right = i;
    }
    if ((1ll << i) & b)
    {
      rightb = i;
      right = i;
    }
    if ((1ll << i) & c)
    {
      rightc = i;
      right = i;
    }
  }
  // cout << "right = " << right << endl;
  if (a == b && b == c)
  {
    cout << "YES" << endl;
    return;
  }
  for (int i = 0ll; i <= max(righta, max(rightb, rightc)); i++)
  {
    // cout << "i = " << i << endl;
    if (a == b && b == c)
      break;

    int cnt = 0;
    // cout << "rights" << endl;
    // cout << righta << " " << rightb << " " << rightc << endl;
    if (i > righta)
      cnt++;
    if (i > rightb)
      cnt++;
    if (i > rightc)
      cnt++;
    // cout << "cnt = " << cnt << endl;
    if (cnt == 2)
    {
      // cout << "fuck" << endl;
      cout << "NO" << endl;
      return;
    }
    int bina = 0ll, binb = 0ll, binc = 0ll;
    bina = ((1ll << i) & (a)) ? 1ll : 0ll;
    binb = ((1ll << i) & (b)) ? 1ll : 0ll;
    binc = ((1ll << i) & (c)) ? 1ll : 0ll;
    // cout << "i = " << i << endl;

    // cout << bina << " " << binb << " " << binc << endl;
    if (bina + binb + binc == 2ll)
    {
      // added to the one which misses the 1ll at this location in its binary form
      if (bina == 0ll)
        a += (int)(pow(2ll, i));
      else if (binb == 0ll)
        b += (int)(pow(2ll, i));
      else
        c += (int)(pow(2ll, i));
    }
    else if (bina + binb + binc == 1ll)
    {
      // cout << "else if" << endl;
      if (bina == 1ll)
      {
        a += (int)(pow(2ll, i));
        righta++;
      }
      else if (binb == 1ll)
      {
        b += (int)(pow(2ll, i));
        rightb++;
      }
      else if (binc == 1ll)
      {
        c += (int)(pow(2ll, i));
        rightc++;
      }

      // right = check(right, right + 1, a, b, c);
    }
    else
    {
      cout << "NO" << endl;
      return;
    }
    // cout << "a = " << a << " , b = " << b << " , c = " << c << endl;
    if (a == b && b == c)
      break;
  }

  if (a == b && b == c)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
