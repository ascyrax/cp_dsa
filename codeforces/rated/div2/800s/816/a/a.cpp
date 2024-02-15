#include <bits/stdc++.h>

using namespace std;
void solve();
int main()
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
  int n, m;
  cin >> n >> m;
  int ans = n - 1 + m - 1;

  int mn = min(n - 1, m - 1);

  if (n == 1 && m == 1)
    cout << 0 << endl;
  else
    cout << ans + mn + 1 << endl; //+1 for teleportation
}