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
  int j1 = 0, j2 = 0;
  if ((v[0] % 2) == (v[n - 1] % 2))
  {
    for (int i = 1; i < n; i++)
    {
      if ((v[i] % 2) == (v[0] % 2))
      {
        j1++;
      }
    }
    cout << j1 << endl;
  }
  else
  {
    // int cnt = 0;
    // int prev = 0;
    int ans = n - 1;

    vector<int> psSame(n, 0), psDiff(n, 0);
    psSame[0] = 1;

    for (int i = 1; i < n; i++)
    {
      psSame[i] = psSame[i - 1];
      psDiff[i] = psDiff[i - 1];
      if ((v[i] % 2) == (v[0] % 2))
      {
        psSame[i] += 1;
        // j1++;
      }
      else
      {
        psDiff[i] += 1;
      }
    }

    // cout << "psSame" << endl;
    // for (auto el : psSame)
    //   cout << el << " ";
    // cout << endl;
    // cout << "psDiff" << endl;
    // for (auto el : psDiff)
    //   cout << el << " ";
    // cout << endl;

    for (int i = 1; i < n; i++)
    {
      if ((v[i] % 2) != (v[0] % 2) && (v[i] % 2) != (v[i - 1] % 2))
      {
        // say we make j2 to this index.
        int right = psDiff[n - 1] - psDiff[i];
        int left = psSame[i] - psSame[0];
        ans = min(ans, left + 1 + right);

        // cout << "i = " << i << endl;
        // cout << "right = " << right << endl;
        // cout << "left = " << left << endl;
        // cout << "ans = " << ans << endl;
        // cnt = max(cnt, i - prev - 1);
        // prev = i + 1;
      }
    }
    // cout << j1 - cnt << endl;
    cout << ans << endl;
  }
}

//................................