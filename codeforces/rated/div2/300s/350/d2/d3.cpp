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

//...............................
unsigned int n, k;
vector<int> a, b;
bool check(int m)
{
  cout << "checking for m = " << m << endl;
  int req = 0;
  for (int i = 0; i < n; i++)
  {
    req += max(0ll, a[i] * m - b[i]);
  }
  cout << "req = " << req << endl;
  if (req <= k)
    return true;
  else
    return false;
}
//...............................

void suraj()
{
  cin >> n >> k;

  a = vector<int>(n, 0);
  b = vector<int>(n, 0);

  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  int l = 0, r = 1e10;
  while (l < r)
  {
    int m = l + (r - l) / 2;
    cout << l << " " << m << " " << r << endl;
    if (check(m))
    {
      if (l == m)
      {
        // l==r-1
        if (check(r))
          l = r;
        else
          l = l;
        break;
      }
      l = m;
    }
    else
    {
      r = m - 1;
    }
  }
  cout << l << endl;
}

//................................