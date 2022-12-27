// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  ioss

      // startTime=(double)clock();

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
//.....................................

//.....................................

//.....................................
void print(vector<int> v)
{
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................

void suraj()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  int ans = 0;
  for (int &i : v)
  {
    cin >> i;
    ans += i / k;
    i %= k;
  }
  sort(v.begin(), v.end());

  // cout << "ans = " << ans << endl;
  // print(v);

  int l = 0, r = n - 1;
  for (l = 0; l < r;)
  {
    if (v[l] + v[r] > k)
      r--;
    else if (v[l] + v[r] < k)
      l++;
    else if (v[l] + v[r] == k)
    {
      ans++;
      v[l++] = 0;
      v[r--] = 0;
    }
  }
  // cout << "ans = " << ans << endl;
  sort(v.begin(), v.end());
  // print(v);
  // sort(v.rbegin(), v.rend());

  // for (int i = 0; i < n; i += 2) // n is even
  // {
  //   if (v[i] + v[i + 1] >= k)
  //     ans++;
  //   else
  //     break;
  // }
  l = 0, r = n - 1;
  for (l = 0; l < r;)
  {
    if (v[l] + v[r] >= k)
    {
      ans++;
      v[l++] = 0;
      v[r--] = 0;
    }
    else if (v[l] + v[r] < k)
      l++;
    // else if (v[l] + v[r] == k) // maybe this case will exist but i dont think so
    // {
    // }
  }
  cout << ans << endl;
}
// 0 3 3 1 3 2
