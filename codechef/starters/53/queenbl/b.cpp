#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();
signed main()
{
  // your code goes here
  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }
  return 0;
}

void solve()
{
  int a, b;
  cin >> a >> b;

  a--;
  b--;

  vector<vector<int>> grid(8, vector<int>(8, 0));

  if (a - 1 >= 0 && a + 1 >=)

    grid[a][b] = 1;

  for (auto el : grid)
  {
    for (auto a : el)
    {
      cout << a << " ";
    }
    cout << endl;
  }
}