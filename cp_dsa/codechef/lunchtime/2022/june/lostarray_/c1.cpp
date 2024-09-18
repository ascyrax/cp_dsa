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
  vector<int> b(n + 1, 0);
  for (int &i : b)
    cin >> i;

  vector<int> ans;

  if (n & 1)
  {
    int xorAll = 0;
    for (int i = 0; i < n + 1; i++)
      xorAll ^= b[i];
    // cout << "xorAll = " << xorAll << endl;
    for (int i = 0; i < n + 1; i++)
    {
      if ((b[i] ^ xorAll) == 0)
        continue;
      else
        ans.pb(b[i] ^ xorAll);
    }
  }
  else
  {
    // cout << "hi" << endl;
    for (int i = 1; i < n + 1; i++)
      ans.pb((b[i] ^ b[i - 1]));
  }
  sort(ans.begin(), ans.end());
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
}
