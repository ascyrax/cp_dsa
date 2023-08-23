#include <bits/stdc++.h>

using namespace std;
void solve();
int main()
{

  // int t;cin>>t;
  int t = 1;
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
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int ans = 0;

  int cnt = -1, curr = -1;
  vector<pair<int, int>> vp;

  for (int i = 0; i < n; i++)
  {
    if (v[i] == curr)
    {
      cnt++;
    }
    else
    {
      if (curr != -1)
        vp.push_back(make_pair(curr, cnt));
      curr = v[i];
      cnt = 1;
    }
  }

  int lenvp = vp.size();

  for (int i = 0; i < lenvp; i++)
  {
    int right = lenvp - i - 1;
    ans += vp[i].second * right;
  }
}
