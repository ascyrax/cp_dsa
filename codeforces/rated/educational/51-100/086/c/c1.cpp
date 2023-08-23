// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define pb push_back

void suraj();

signed main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);

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
// int mod = 998244353;

void suraj()
{
  int a, b, q;
  cin >> a >> b >> q;

  int mn = min(a, b);
  int mx = max(a, b);

  a = mn;
  b = mx;

  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;

    int total = r - l + 1;
    // x belonging from l.....r
    // x%a%b != x%b%a
    // (0...a-1)%b != (x%b)%a
    // (0...a-1) != (0...b-1)%a
    cout << "total " << total << endl;
    int unwanted = 0;
    for (int i = 0; i < a; i++)
    {
      vector<int> temp;
      for (int j = i; j < b; j += a)
        temp.pb(j);

      cout << "i " << i << endl;
      for (auto el : temp)
      { // el will range btwn 0...b-1
        cout << "el " << el << endl;
        int cnt = 0;
        int q = r / b;
        cnt += q;
        int rem = r % b;
        if (el <= rem)
          cnt++;
        cout << "cnt a " << cnt << endl;
        // since we are not taking any x <left
        q = l / b;
        cnt -= q;
        rem = l % b;
        if (el <= rem)
          cnt--;

        cout << "cnt b " << cnt << endl;
        unwanted += cnt;
        cout << "unwanted " << unwanted << endl;
      }
    }
    cout << "ans -----------" << total - unwanted << " " << endl;
  }
  cout << endl;
}
