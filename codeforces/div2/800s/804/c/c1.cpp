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
int mod = 1e9 + 7;
//.....................................

//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  if (n == 1)
  {
    cout << 1 << endl;
    return;
  }

  vector<int> indexOf(n, -1);
  for (int i = 0; i < n; i++)
  {
    indexOf[v[i]] = i;
  }
  vector<int> b(n, -1);
  b[indexOf[0]] = 0;
  b[indexOf[1]] = 1;
  int left = min(indexOf[0], indexOf[1]);
  int right = max(indexOf[0], indexOf[1]);
  vector<pair<int, int>> range(n);
  range[0] = make_pair(indexOf[0], indexOf[0]);
  range[1] = make_pair(indexOf[1], indexOf[1]);
  int ans = 1;
  for (int i = 2; i < n; i++)
  {
    if (indexOf[i] < right && indexOf[i] > left)
    {
      range[i] = make_pair(left, right); // exclusive boundaries
      ans *= ((right - left + 1ll) - i); // - i becz all elements from 0 to i-1 occupyt this range only
      ans %= mod;
    }
    else
    {
      range[i] = make_pair(indexOf[i], indexOf[i]); // i.e. this element will be exactly where it was in a.
      ans *= 1;
      left = min(left, indexOf[i]);
      right = max(right, indexOf[i]);
    }
    // cout << "i : " << i << endl;
    // cout << "ans : " << ans << endl;
  }
  cout << ans << endl;
}
