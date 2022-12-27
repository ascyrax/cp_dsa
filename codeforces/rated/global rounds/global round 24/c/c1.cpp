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
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> cnt;
  for (int &i : v)
  {
    cin >> i;
    cnt[i]++;
  }

  sort(v.begin(), v.end());

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int val = v[i];
    int right = i; // index of a distinct value on the right
    int left = i;  // '' left
    int nSimilarNos = 0;
    if (i + 1 < n && v[i + 1] == v[i])
      nSimilarNos++;

    int nRight = (n - 1) - right + 1;
    int nLeft = (left)-0 + 1;
    if (nSimilarNos > max(nRight, nLeft))
    {
      ans++; // forms an edge with just one similar i.e the one on its right
      i++;
      continue;
    }
    // else

    ans += max(nRight, nLeft);
  }
  cout << ans << endl;
}
