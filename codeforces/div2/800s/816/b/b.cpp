#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve();
signed main()
{

  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}

void solve()
{
  int n, k, b, s;
  cin >> n >> k >> b >> s;

  // if(b*k > s){
  //   cout<<-1<<endl;return;
  // }

  int bEl = (b) / n;
  int r = (b) % n;

  vector<int> ans(n, bEl * k);
  // cout << "ans" << endl;
  // for (auto el : ans)
  //   cout << el << " ";
  // cout << endl;
  for (int i = 0; i < r; i++)
  {
    ans[i] = ans[i] + 1 * k;
  }

  for (int i = 0; i < n; i++)
    s -= ans[i];

  if (s < 0)
  {
    cout << -1 << endl;
  }
  else
  {
    bEl = s / n;
    r = s % n;
    // cout << bEl << " " << r << endl;
    if (r > 0)
    {
      if ((bEl + 1) / k > 0)
      {
        cout << -1 << endl;
        return;
      }
    }
    else
    {
      if ((bEl) / k > 0)
      {
        cout << -1 << endl;
        return;
      }
    }
    for (int i = 0; i < n; i++)
      ans[i] += bEl;
    for (int i = 0; i < r; i++)
      ans[i] += 1;

    for (auto el : ans)
      cout << el << " ";
    cout << endl;
  }
}