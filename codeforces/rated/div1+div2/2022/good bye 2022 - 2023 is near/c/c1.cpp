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
  int n;
  cin >> n;
  vector<int> v(n);
  int even = 0, odd = 0;
  map<int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    cnt[v[i]]++;
    if (v[i] % 2 == 0)
      even++;
    else
      odd++;
  }

  bool goodArr = true;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (__gcd(v[i], v[j]) > 1)
        goodArr = false;
    }
  }

  bool equalsFound = false;
  for (auto el : cnt)
    if (el.second >= 2)
    {
      equalsFound = true;
      break;
    }

  if (equalsFound)
  {
    cout << "NO" << endl;
    return;
  }

  if (even >= 2 && odd >= 2)
  {
    cout << "NO" << endl;
    return;
  }

  // e1 o1 =   // o1 e1
  if (even == 1 && odd == 1)
    cout << "YES" << endl;
  else if (even == 1 && odd == 2)
  {
    // e1 o2 =   // o1 e2
    cout << "YES" << endl;
  }
  else
  {
    // e1 o2+ =  // o1 e2+
    cout << "NO" << endl;
  }
}
