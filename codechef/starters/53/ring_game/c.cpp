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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int diff = 0;
  int cnt1 = 0, cnt0 = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] == 1)
      cnt1++;
    else
      cnt0++;
    int next = (i + 1) % n;
    if (v[i] != v[next])
    {
      diff++;
    }
  }
  int mn = min(cnt1, cnt0);
  int diffMax = mn * 2;
  //  after every valid move -> diff+=2;
  int nMoves = (diffMax - diff) / 2;

  if (nMoves % 2 == 0)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
}