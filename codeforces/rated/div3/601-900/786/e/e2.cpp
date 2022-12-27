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

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
int n;
vector<int> v;
int ans = 1e18;
int solve(int i, int j)
{
  int result = 1e18, result2 = 1e18, result3 = 1e18;

  if (i == j - 2)
  {
    result = max(v[i], v[j]);
  }
  else if (i == j - 1)
  {
    result2 = 0;
    result = 0;
    int vi = v[i];
    int vj = v[j];

    int a = vi, b = vj;
    int ab = (max(a, b) + 1) / 2;
    result2 += ab;
    if (a > b)
    {
      a = max(0ll, a - 2 * ab);
      b = max(0ll, b - ab);
      result2 += b;
    }
    else
    {
      a = max(0ll, a - ab);
      b = max(0ll, b - 2 * ab);
      result2 += a;
    }

    // cout << "vi = " << vi << " , vj = " << vj << endl;
    int q = min(vi / 3, vj / 3);
    vi -= q * 3;
    vj -= q * 3;
    result += 2 * q;
    int temp = (max(vi, vj) + 1) / 2;
    result += temp;
    // cout << "result = " << result << endl;
    if (vi > vj)
    {
      vi = max(0ll, vi - 2 * temp);
      vj = max(0ll, vj - temp);
      result += vj;
    }
    else
    {
      vi = max(0ll, vi - temp);
      vj = max(0ll, vj - 2 * temp);
      result += vi;
    }
    // cout << "result2  = " << result2 << endl;
    result = min(result, result2);
  }

  int a = (v[i] + 1) / 2;
  int b = (v[j] + 1) / 2;
  result3 = a + b;

  return min(result, result3);
}
//.....................................

void suraj()
{
  cin >> n;
  v = vector<int>(n);
  for (int &i : v)
    cin >> i;

  // for i=0;

  ans = min(ans, solve(0, 1));
  // cout << "ans = " << ans << endl;
  for (int i = 1; i < n - 1; i++)
  {
    // say bomb is thrown at i.
    ans = min(ans, solve(i - 1, i));
    ans = min(ans, solve(i, i + 1));
    ans = min(ans, solve(i - 1, i + 1));
    // cout << "i = " << i << endl;
    // cout << "ans = " << ans << endl;
  }
  // for i=n-1;
  ans = min(ans, solve(n - 2, n - 1));
  // cout << "ans = " << ans << endl;

  // whatif broken gates are not adjacent.
  vector<pair<int, int>> temp;
  for (int i = 0; i < n; i++)
  {
    temp.pb(make_pair(v[i], i));
  }
  sort(temp.begin(), temp.end());

  // cout << "hi" << endl;
  // cout << temp[0].second << " " << temp[1].second << endl;
  ans = min(ans, solve(temp[0].second, temp[1].second));

  cout << ans << endl;
}
