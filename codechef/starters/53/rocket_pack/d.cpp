#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
  // your code goes here
  int n, target;
  cin >> n >> target;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  int ans = 1e18;
  int minDiff = 1e18;

  // cout << "v" << endl;
  // for (auto el : v)
  //   cout << el << " ";
  // cout << endl;

  for (int i = 0; i < n; i++)
  {
    int sum = v[i];
    for (int j = i + 1; j <= n - 2; j++)
    {
      sum += v[j];
      int diff = target - sum;
      // cout << "diff: " << diff << endl;
      auto itr = upper_bound(v.begin() + j + 1, v.end(), diff);
      // cout << "*itr = " << *itr << endl;
      int right = 1e18, left = 1e18;
      if (itr == v.end())
      {
        --itr;
        left = *itr;
      }
      else if (itr == v.begin())
      {
        right = *itr;
      }
      else
      {
        right = *itr;
        --itr;
        left = *itr;
      }
      // cout << "left: " << left << " , right: " << right << endl;
      if (abs(right - diff) < abs(diff - left))
        sum += right;
      else
        sum += left;

      diff = abs(sum - target);
      if (diff < minDiff)
      {
        minDiff = diff;
        ans = sum;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
