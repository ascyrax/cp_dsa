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
  string s;
  cin >> s;

  if (s[0] == '9')
  {
    int carry = 0;
    for (int i = n - 1; i >= 1; i--)
    {
      int val = (s[i] - '0') + carry;
      // cout << "val = " << val << endl;
      if (val >= 2)
        carry = 1;
      else
        carry = 0;
      // cout << "carry = " << carry << endl;
      s[i] = (((11 - val) % 10) + '0');
    }
    // for i=0
    // cout << "carry = " << carry << endl;
    if (carry == 1)
      s[0] = '1';
    else
      s[0] = '2';
    cout << s << endl;
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      int val = s[i] - '0';
      cout << 9 - val;
    }
    cout << endl;
  }
}
