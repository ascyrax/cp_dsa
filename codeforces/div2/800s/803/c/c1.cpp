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
  vector<int> v(n);

  int nPos = 0, nNeg = 0, nZer = 0;
  vector<int> pos, neg;
  map<int, int> m;
  int sum = 0;
  for (int &i : v)
  {
    cin >> i;
    m[i]++;
    if (i > 0)
    {
      nPos++;
      pos.pb(i);
    }
    else if (i < 0)
    {
      nNeg++;
      neg.pb(i);
    }
    else
      nZer++;
    sum += i;
  }

  sort(v.begin(), v.end());

  // cout << m[10] << " " << m[5] << " " << m[1] << endl;

  if (nPos >= 3 || nNeg >= 3)
  {
    cout << "NO" << endl;
    return;
  }
  // if (nPos == 2 || nNeg == 2)
  // {

  if (nPos == 2)
  {
    // if (m[-1 * pos[0]] > 0 || m[-1 * pos[1]] > 0)
    //   cout << "YES" << endl;
    // else
    //   cout << "NO" << endl;
    for (auto el : v)
    {
      if (el <= 0)
      {
        if (m[pos[0] + pos[1] + el] == 0)
        {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  if (nNeg == 2)
  {
    // if (m[-1 * neg[0]] > 0 || m[-1 * neg[1]] > 0)
    //   cout << "YES" << endl;
    // else
    //   cout << "NO" << endl;
    for (auto el : v)
    {
      if (el >= 0)
      {
        if (m[neg[0] + neg[1] + el] == 0)
        {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  // }
  // else
  // {

  if (nPos == 1)
  {
    if (m[-pos[0]] == 0)
    {
      cout << "NO" << endl;
      return;
    }
  }

  // else
  // {
  // nZer = 1  OR nZer = 0.
  if (nNeg == 1)
  {
    if (m[-neg[0]] == 0)
    {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  // => nZer = 2 . below cases wont occur
  // else if (nPos == 1 && nNeg == 0)
  // {
  // }
  // else if (nPos == 0 && nNeg == 1)
  // {
  // }
  // else if (nPos == 0 && nNeg == 0)
  // {
  // }
  // }
  // }
}
