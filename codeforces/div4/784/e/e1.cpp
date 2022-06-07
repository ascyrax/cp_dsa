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

//...............................

//...............................

void suraj()
{
  int n;
  cin >> n;
  vector<string> vs(n);
  map<char, int> beginsWith, endsWith;
  map<string, int> cnt;
  for (int i = 0; i < n; i++)
  {
    cin >> vs[i];
    beginsWith[vs[i][0]]++;
    endsWith[vs[i][1]]++;
    cnt[vs[i]]++;
  }

  int ans = 0;
  for (auto el : beginsWith)
  {
    ans += (el.second * (el.second - 1)) / 2;
  }
  // cout << "ans = " << ans << endl;
  for (auto el : endsWith)
  {
    ans += (el.second * (el.second - 1)) / 2;
  }
  // cout << "ans = " << ans << endl;
  for (auto el : cnt)
  {
    ans -= 2 * (el.second * (el.second - 1)) / 2;
  }
  cout << ans << endl;
}

//................................