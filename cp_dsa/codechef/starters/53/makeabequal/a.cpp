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
  vector<int> a(n), b(n);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  // sort(a.begin(), a.end());
  // sort(b.begin(), b.end());

  int cnta = 0, cntb = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > b[i])
    {
      cnta += a[i] - b[i];
    }
    else
    {
      cntb += b[i] - a[i];
    }
  }
  if (cnta != cntb)
    cout << -1 << endl;
  else
  {
    cout << (cnta + cntb) / 2 << endl;
  }
}