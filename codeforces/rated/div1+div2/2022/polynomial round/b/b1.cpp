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

//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> v(m);
  map<int, int> cnt;
  for (int i = 0; i < m; i++)
  {
    cin >> v[i];
    cnt[v[i]]++;
  }
  sort(v.rbegin(), v.rend());
  // int nGroups = (n / k) + ((n % k == 0) ? 0 : 1);
  int nGroups = (n + k - 1) / k;

  int lenLastGroup = n % k;
  if (n % k == 0)
    lenLastGroup = k;

  // cout << nGroups << " " << lenLastGroup << endl;

  if (v[0] > nGroups)
    cout << "NO" << endl;
  else if (v[0] == nGroups)
  {
    if (cnt[v[0]] > min(k, lenLastGroup))
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  else if (v[0] < nGroups)
    cout << "YES" << endl;
}
