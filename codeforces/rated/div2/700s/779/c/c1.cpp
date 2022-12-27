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

//...............................

//...............................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> cnt;
  for (int &i : v)
  {
    cin >> i;
    cnt[i]++;
  }

  if (n == 1)
  {
    if (v[0] == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }

  // n ke baad 1
  // 1 ke baad 2
  // x ke baad x+1
  // 1 must come and should come atmost 1 times too.

  if (cnt.count(1) > 0 && cnt[1] == 1)
  {
    if (v[n - 1] == n)
    {
      if (v[0] != 1)
      {
        cout << "NO" << endl;
        return;
      }
    }
    else
    {
      for (int i = 0; i < n - 1; i++)
      {

        if (v[i] == n)
        {
          if (v[i + 1] != 1)
          {
            cout << "NO" << endl;
            return;
          }
        }
      }
    }
    for (int i = 0; i <= n - 2; i++)
    {
      if (v[i + 1] - v[i] > 1)
      {
        cout << "NO" << endl;
        return;
      }
    }
    if (v[0] - v[n - 1] > 1)
    {
      cout << "NO" << endl;
      return;
    }
    for (int i = 0; i <= n - 1; i++)
    {
      if (v[i] == 1)
      {
        if (v[(i + 1) % n] != 2)
        {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  else
  {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

//................................

// int

// int

// int

// int
