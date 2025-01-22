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
  set<int> s;
  for (int &i : v)
  {
    cin >> i;
    s.insert(i);
  }

  int mex = 0, mexLoc = 0;
  sort(v.begin(), v.end());

  for (auto el : s)
  {
    if (el == mex)
      mex++;
    else
      break;
  }

  // for (int i = 0; i < n; i++)
  // {
  //   if (v[i] == mex)
  //   {
  //     mex++;
  //   }
  //   else if (v[i] > mex)
  //   {
  //     mexLoc = i;
  //     break;
  //   }
  //   mexLoc = i + 1;
  // }

  if (mex == 0)
  {
    cout << v[0] - 1 << endl;
    return;
  }
  if (mex == 1)
  {
    cout << -1 << endl;
    return;
  }

  int ans = 0;
  for (int i = 0; i < n;)
  {
    int len = 1;
    int j = i + 1;
    for (; j < n; j++)
    {
      if (v[j] == v[j - 1] + 1)
      {
        len++;
      }
      else if (v[j] == v[j - 1])
      {
        ;
      }
      else
        break;
    }
    i = j;
    if (len >= mex - 1)
    {
      ans++;
    }
  }
  cout << ans - 1 << endl;
}

//................................

// int

// int

// int

// int
