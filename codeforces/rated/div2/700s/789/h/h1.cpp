#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (a > 0)
      v.push_back(a);
  }
  int len = v.size();
  int ans = v[(len - 1) / 2];
  cout << ans << endl;
  return 0;
}