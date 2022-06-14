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
  int n, m, k;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<char> c;

  int ptrA = 0, ptrB = 0;
  int cntA = 0, cntB = 0;
  while (1)
  {
    if ((ptrA == a.size()) || (ptrB == b.size()))
    {
      break;
    }
    if (a[ptrA] < b[ptrB])
    {
      if (cntA < k)
      {
        cntA++;
        cntB = 0;
        c.pb(a[ptrA++]);
      }
      else if (cntA == k)
      {
        cntA = 0;
        cntB++;
        c.pb(b[ptrB++]);
      }
    }
    else if (a[ptrA] > b[ptrB])
    {
      if (cntB < k)
      {
        cntB++;
        cntA = 0;
        c.pb(b[ptrB++]);
      }
      else if (cntB == k)
      {
        cntB = 0;
        cntA++;
        c.pb(a[ptrA++]);
      }
    }
    // below case is not possible
    // else if (a[ptrA] == b[ptrB])
    // {
    //   if(cntA)
    // }
  }

  for (auto el : c)
    cout << el;
  cout << endl;
}
