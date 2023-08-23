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

void solve(vector<int> &a, vector<int> bLeft)
{
  int indA = 0;

  sort(bLeft.rbegin(), bLeft.rend());

  bool flag = false;

  for (int i = 0; i < (int)bLeft.size(); i++)
  {
    if (indA == a.size())
      break;
    if (a[indA] > bLeft[i])
      break;
    else
    {
      a[indA++] = bLeft[i];
      flag = true;
    }
  }
  if (!flag)
  {
    a[0] = bLeft[0];
  }
}

void suraj()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  sort(a.begin(), a.end());

  while (b.size() > 0)
  {
    vector<int> bLeft, bRight;
    int mxB = 0;
    for (auto el : b)
      mxB = max(mxB, el);
    int ptrMax = b.size();
    for (int i = b.size() - 1; i >= 0; i--)
    {
      if (b[i] == mxB)
      {
        ptrMax = i;
        break;
      }
    }

    for (int i = 0; i <= ptrMax; i++)
      bLeft.pb(b[i]);
    for (int i = ptrMax + 1; i < b.size(); i++)
      bRight.pb(b[i]);

    solve(a, bLeft);
    b = bRight;
  }

  int sum = 0;
  for (auto el : a)
    sum += el;
  cout << sum << endl;
}
