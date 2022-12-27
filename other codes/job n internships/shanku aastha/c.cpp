// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define pb push_back
int solution(vector<int> v, int k);
int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int ans = solution(v, k);
  cout << ans << endl;
  return 0;
}

bool check(int val, vector<int> v, int k)
{
  int cnt = 0;
  for (auto el : v)
  {
    cnt += el / val;
  }
  return cnt >= k;
}

int solution(vector<int> v, int k)
{
  sort(v.begin(), v.end());
  int lenv = v.size();
  int l = 0, r = v[lenv - 1];
  while (1)
  {
    int m = l + (r - l) / 2;
    if (check(m, v, k))
    {
      if (m == l)
      {
        if (check(r, v, k))
        {
          l = r;
          break;
        }
        else
        {
          l = l;
          break;
        }
      }
      else
        l = m;
    }
    else
    {
      r = m - 1;
    }
  }
  return l;
}