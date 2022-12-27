// O(n^2) checking if this will work or not

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
int sum(int a)
{
  return (a * (a + 1)) / 2;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> k(n), h(n);
  for (int &i : k)
    cin >> i;
  for (int &i : h)
    cin >> i;

  for (int i = n - 1; i >= 0; i--)
  {
    int ka = k[i] - h[i] - 1;
    auto it = lower_bound(k.begin(), k.end(), ka) - k.begin();
    for (int j = it; j < i; j++)
    {
      int diff = k[i] - k[j];
      h[j] = max(h[j], h[i] - diff);
    }
  }
  // cout << "h" << endl;
  // for (auto el : h)
  //   cout << el << " ";
  // cout << endl;
  int ans = sum(h[0]);
  for (int i = 1; i < n; i++)
  {
    int diff = k[i] - k[i - 1];
    if (h[i] > diff)
    {
      h[i] = h[i - 1] + diff;
      ans += (sum(h[i]) - sum(h[i - 1]));
    }
    else
    {
      ans += sum(h[i]);
    }
  }

  cout << ans << endl;
}
