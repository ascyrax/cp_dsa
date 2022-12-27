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

  if (n == 1)
  {
    cout << 0 << endl;
    return;
  }

  vector<int> psLeft(n), psRight(n);

  psLeft[0] = v[0];
  for (int i = 1; i < n; i++)
    psLeft[i] = psLeft[i - 1] + v[i];

  // psRight[n - 1] = v[n - 1];
  // for (int i = n - 2; i >= 0; i--)
  // {
  //   psRight[i] = psRight[i + 1] + v[i];
  // }

  psRight[0] = v[n - 1];
  for (int i = 1; i < n; i++)
  {
    psRight[i] = psRight[i - 1] + v[n - 1 - i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int sumLeft = psLeft[i];
    auto temp = lower_bound(psRight.begin(), psRight.end() - 2 - i, sumLeft) - psRight.begin();
    if (psRight[temp] == sumLeft)
    {
      ans = max(ans, (i + 1) + (temp + 1));
    }
  }

  cout << ans << endl;
}

//................................