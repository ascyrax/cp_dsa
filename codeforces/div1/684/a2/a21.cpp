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
//.....................................
int n, m;
vector<vector<int>> grid;
vector<vector<pair<int, int>>> ans;
vector<pair<int, int>> temp;
int cnt1 = 0, cnt0 = 0;
vector<pair<int, int>> vp1, vp0;

//.....................................
void calculate(int i, int j)
{
  cnt0 = 0, cnt1 = 0;
  vp0.clear();
  vp1.clear();
  if (grid[i][j] == 1)
  {
    cnt1++;
    vp1.pb(make_pair(i, j));
  }
  else
  {
    cnt0++;
    vp0.pb(make_pair(i, j));
  }
  if (grid[i + 1][j] == 1)
  {
    cnt1++;
    vp1.pb(make_pair(i + 1, j));
  }
  else
  {
    cnt0++;
    vp0.pb(make_pair(i + 1, j));
  }
  if (grid[i][j + 1] == 1)
  {
    cnt1++;
    vp1.pb(make_pair(i, j + 1));
  }
  else
  {
    cnt0++;
    vp0.pb(make_pair(i, j + 1));
  }
  if (grid[i + 1][j + 1] == 1)
  {
    cnt1++;
    vp1.pb(make_pair(i + 1, j + 1));
  }
  else
  {
    cnt0++;
    vp0.pb(make_pair(i + 1, j + 1));
  }
}
//.....................................

void suraj()
{
  cin >> n >> m;
  grid = vector<vector<int>>(n, vector<int>(m));
  ans.clear();
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
    {
      grid[i][j] = s[j] - '0';
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << grid[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n; i += 2)
  {
    for (int j = 0; j < m; j += 2)
    {
      // cout << "i: " << i << " , j: " << j << endl;
      if (i == n - 1)
      {
        i -= 3;
        break;
      }
      if (j == m - 1)
      {
        j -= 3;
        break;
      }

      calculate(i, j);
      // cout << "cnt0: " << cnt0 << " , cnt1: " << cnt1 << endl;
      if (cnt1 == 4)
      {
        temp.pb(vp1[0]);
        temp.pb(vp1[1]);
        temp.pb(vp1[2]);
        ans.pb(temp);
        temp.clear();

        calculate(i, j);
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[0]);
        ans.pb(temp);
        temp.clear();

        calculate(i, j);
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[0]);
        ans.pb(temp);
        temp.clear();
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[1]);
        ans.pb(temp);
        temp.clear();
      }
      else if (cnt1 == 3)
      {
        for (auto el : vp1)
        {
          temp.pb(el);
        }
        ans.pb(temp);
        temp.clear();
      }
      else if (cnt1 == 2)
      {
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[0]);
        ans.pb(temp);
        temp.clear();
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[1]);
        ans.pb(temp);
        temp.clear();
      }
      else if (cnt1 == 1)
      {
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[0]);
        ans.pb(temp);
        temp.clear();

        calculate(i, j);

        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[0]);
        ans.pb(temp);
        temp.clear();
        temp.pb(vp0[0]);
        temp.pb(vp0[1]);
        temp.pb(vp1[1]);
        ans.pb(temp);
        temp.clear();
      }
      else if (cnt1 == 0)
      {
        continue;
      }
      grid[i][j] = 0;
      grid[i + 1][j] = 0;
      grid[i][j + 1] = 0;
      grid[i + 1][j + 1] = 0;
    }
  }

  cout << ans.size() << endl;
  for (auto el : ans)
  {
    for (auto i : el)
      cout << i.first + 1 << " " << i.second + 1 << " ";
    cout << endl;
  }
}
