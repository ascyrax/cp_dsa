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
int mod = 1e9 + 7;
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
//.....................................
bool flag = true;
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  flag = true;

  map<int, int> cnt;
  map<pair<int, int>, int> cntPairs;
  vector<vector<int>> temp(n, vector<int>());
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == b)
      flag = false;
    cnt[a]++;
    cnt[b]++;
    int mn = min(a, b);
    int mx = max(a, b);
    cntPairs[make_pair(mn, mx)]++;
    temp[mn].pb(mx);
    temp[mx].pb(mn);
  }

  set<int> sa, sb;
  sa.insert(temp[0][0]);
  sb.insert(temp[0][1]);
  temp[0].clear();

  while (1)
  {
    int vala = *sa.begin();
    int valb = *sb.begin();
  }

  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
