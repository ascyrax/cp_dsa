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
  string s;
  cin >> s;
  int lens = s.size();

  int alice = 0, bob = 0, total = 0;

  for (int i = 0; i < lens; i++)
  {
    total += (s[i] - 'a' + 1);
  }

  if (lens == 1)
  {
    cout << "Bob " << total << endl;
    return;
  }

  if (lens & 1)
  {
    if (s[0] > s[lens - 1])
    {
      alice = total - (s[lens - 1] - 'a' + 1);
    }
    else
    {
      alice = total - (s[0] - 'a' + 1);
    }
    bob = total - alice;
    cout << "Alice " << alice - bob << endl;
  }
  else
  {
    cout << "Alice " << total << endl;
  }
}
