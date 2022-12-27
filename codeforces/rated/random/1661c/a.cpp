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
  for (int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  int one = 0, two = 0;
  int mx = v[n - 1];

  int ans = 0;

  for (int el : v)
  {
    int diff = mx - el;
    int q3 = diff / 3;
    int r3 = diff % 3;
    ans += q3 * 2;
    if (r3 == 2)
      two++;
    else if (r3 == 1)
      one++;
  }
  // cout << "ans = " << ans << endl;
  // cout << "one = " << one << " , two = " << two << endl;

  if (one < two)
  {
    ans += one + one;
    two -= one;
    ans += 2 * two;
  }
  else if (one > two)
  {
    ans += two;
    ans += (two + 1);
    one -= (two + 1);
    ans += 2 * one;
  }
  else if (one == two)
  {
    ans += one + two;
  }

  cout << ans << endl;
}

//................................

// int

// int

// int

// int
