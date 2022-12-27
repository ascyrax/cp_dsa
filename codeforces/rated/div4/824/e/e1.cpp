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
  int n, q;
  cin >> n >> q;
  vector<int> steps(n), queries(q);
  for (int &i : steps)
    cin >> i;

  vector<int> mxStair(n);
  mxStair[0] = steps[0];
  for (int i = 1; i < n; i++)
  {
    // int height = steps[i] - steps[i - 1];
    if (steps[i] >= mxStair[i - 1])
      mxStair[i] = steps[i];
    else
      mxStair[i] = mxStair[i - 1];
  }

  vector<int> ps(n, 0);
  ps[0] = steps[0];
  for (int i = 1; i < n; i++)
    ps[i] = ps[i - 1] + steps[i];

  print("mxStair", mxStair);

  for (int &query : queries)
  {
    cin >> query;
    auto it = lower_bound(mxStair.begin(), mxStair.end(), query);
    if (*it == query)
      it = upper_bound(mxStair.begin(), mxStair.end(), query);
    else
    {
        }
  }
  cout << endl;
}
