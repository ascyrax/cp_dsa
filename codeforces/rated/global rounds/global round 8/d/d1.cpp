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

  // cin >> t;

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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  int sum = 0;
  int totOr = 0;

  for (int i = 0; i < n; i++)
  {
    totOr |= v[i];
    if (i == n - 1)
      continue;

    int a = v[i];
    int b = v[i + 1];
    v[i] = a & b;
    v[i + 1] = a | b;
  }

  for (int i = 0; i < n; i++)
  {
    int a = v[i];
    int b = v[n - 1];
    v[i] = a & b;
    v[n - 1] = a | b;
  }

  for (int i : v)
    sum += i * i;

  cout << sum << endl;
}
