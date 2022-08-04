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

int k;
vector<int> v;

//.....................................

bool isOdd(int n)
{
  if (n & 1)
    return true;
  else
    return false;
}

bool solve(int n, int m)
{
  vector<pair<int, int>> cnt;
  int total = m * n;

  if (isOdd(m))
  {
    // vertical check
    cnt.pb(make_pair(1, 3 * n));
    cnt.pb(make_pair(((total - 3 * n) / (2 * n)), 2 * n));
  }
  else
  {
    // ver check
    cnt.pb(make_pair(m / 2, 2 * n)); // m/2 = total/(2*n)
  }

  if (cnt.size() == 1)
  {
    // cout << "if" << endl;
    int nVal = cnt[0].first;
    int val = cnt[0].second;
    for (int i = 0; i < k; i++)
    {
      int q = v[i] / (2 * n);
      nVal -= q;
      if (nVal <= 0)
        return true;
    }
    return false;
  }
  else if (cnt.size() == 2)
  {
    // cout << "else if" << endl;
    // cout << cnt[0].first << " " << cnt[0].second << endl;
    // cout << cnt[1].first << " " << cnt[1].second << endl;
    bool flag = false;
    // sort(v.rbegin(), v.rend());
    // first get the 2-col-width elements
    vector<int> temp;
    for (int i = 0; i < k; i++)
      temp.pb(v[i] / n);
    // temp.size == k
    // print("temp", temp);
    for (int i = 0; i < k; i++)
    {
      if (flag)
        break;
      if (((temp[i] % 2) == 1) && (temp[i] >= 3))
      {
        temp[i] -= 3;
        flag = true;
      }
    }

    if (!flag)
    {
      for (int i = 0; i < k; i++)
      {
        if (flag)
          break;
        if (temp[i] >= 3)
        {
          temp[i] -= 3;
          flag = true;
        }
      }
    }
    if (!flag)
      return false;
    int nVal = cnt[1].first;
    if (nVal == 0)
      return true;
    for (int i = 0; i < k; i++)
    {
      int q = temp[i] / 2;
      nVal -= q;
      if (nVal <= 0)
        return true;
    }
    return false;
  }
}
//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m >> k;
  v = vector<int>(k);
  for (int i = 0; i < k; i++)
    cin >> v[i];

  sort(v.begin(), v.end());

  bool ans = false;
  ans = ans || solve(n, m);
  ans = ans || solve(m, n);
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
