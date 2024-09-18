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

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);

  map<int, int> m;

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    // cout << "v[i] = " << v[i] << endl;
    int temp = 1;
    while (temp <= v[i])
    {
      // cout << "temp = " << temp << endl;
      if ((temp & v[i]) != 0)
      {
        // cout << "if" << endl;
        m[temp]++;
      }
      else
      {
        // cout << (temp & v[i]) << endl;
      }
      temp *= 2;
    }
  }

  // cout << "v" << endl;
  // for (auto el : v)
  //   cout << el << " ";
  // cout << endl;

  // cout << "m" << endl;
  // for (auto el : m)
  //   cout << el.first << " " << el.second << endl;

  int mnCntVal = 1e9, mnCnt = 0;
  // for (auto el : m)
  // {
  //   if (el.second >= 2)
  //   {
  //     if (el.first < mnCntVal)
  //     {
  //       mnCnt = el.second;
  //       mnCntVal = el.first;
  //     }
  //     else
  //   }
  // }

  vector<pair<int, int>> temp;
  for (auto el : m)
    temp.pb(make_pair(el.first, el.second));

  sort(temp.begin(), temp.end());

  // cout << "cnt" << endl;
  // for (auto el : temp)
  //   cout << el.first << " " << el.second << endl;

  for (auto el : temp)
  {
    if (el.second >= 2)
    {
      mnCntVal = el.first;
      mnCnt = el.second;
      break;
    }
  }

  // cout << "mnCntVal = " << mnCntVal << " mnCnt = " << mnCnt << endl;

  if (mnCntVal == 1e9)
  {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int, int>> ans;

  int left = 0, right = 0;
  for (int i = 0; i < n; i++)
  {
    if ((v[i] & mnCntVal) >= 1)
    {
      ans.pb(make_pair(left, i));
      left = i + 1;
      mnCnt--;
    }
    if (mnCnt == 1)
    {
      ans.pb(make_pair(left, n - 1));
      break;
    }
  }
  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (auto el : ans)
    cout << el.first + 1 << " " << el.second + 1 << endl;
}
