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
int n;
vector<int> v;

//.....................................
bool check(int index, int val)
{
  int adjLeft = v[(index == 0) ? n - 1 : index - 1];
  int adjRight = v[(index == n - 1) ? 0 : index + 1];
  // go right first
  for (int i = index + 1;; i++)
  {
    if (i == n)
      i = 0;
    if (v[i] == val)
      break;
    else
    {
      if (v[i] != adjLeft)
        return true;
    }
  }
  // go left
  for (int i = index - 1;; i--)
  {
    if (i == -1)
      i = n - 1;
    if (v[i] == val)
      return false;
    else
    {
      if (v[i] != adjRight)
        return true;
    }
  }
}
//.....................................

void suraj()
{
  cin >> n;
  v = vector<int>(n, 0);
  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    mp[v[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int el = v[i];
    int cntEl = mp[el];
    int nOps = n - cntEl;
    for (int j = 0; j < n; j++)
    {
      if (v[j] == el)
      {
        if (v[(j < n - 1) ? (j + 1) : 0] != v[(j > 0) ? (j - 1) : n - 1])
        {
          cntEl--;
          nOps++;
        }
        else if (check(j, el))
        {
          cntEl--;
          nOps++;
        }
      }
    }
    if (cntEl > 0)
      nOps++;
    ans = max(ans, nOps);
  }

  cout << ans << endl;
}
