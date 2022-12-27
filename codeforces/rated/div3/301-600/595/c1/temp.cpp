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

int inf = 1e18;
//.....................................

//.....................................
vector<vector<int>> createSubsets(vector<int> v)
{
  vector<int> temp = v;

  if (temp.size() == 1)
  {
    return {v, {}};
  }

  // temp.erase(temp.end() - 1);
  temp.erase(temp.begin() + v.size() - 1);
  vector<vector<int>> subsets = createSubsets(temp);
  vector<vector<int>> subsets2 = subsets;
  for (auto &el : subsets2)
  {
    el.pb(v.back());
    subsets.pb(el);
  }
  return subsets;
}
//.....................................

//.....................................

void suraj()
{
  int a = 1;
  vector<int> v;
  v.pb(1);
  v.pb(2);
  v.pb(3);
  // while (a <= 1e4)
  // {
  //   v.pb(a);
  //   a *= 3;
  // }
  // v.pb(a);

  // vector<int> combinations;
  vector<vector<int>> combinations;
  // generate all subsets of v.
  // method 1

  for (int i = 0; i < v.size(); i++)
  {
    int combsize = combinations.size();
    vector<int> temp;
    for (int j = 0; j < combsize; j++)
    {
      temp = combinations[j];
      temp.pb(v[i]);
      combinations.pb(temp);
      // combinations.pb(v[i] + combinations[j]);
    }
    combinations.pb({v[i]});
  }
  sort(combinations.begin(), combinations.end());

  cout << "v" << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;

  cout << "combinations" << endl;
  for (auto el : combinations)
  {
    for (auto els : el)
      cout << els << " ";
    cout << endl;
  }

  cout << "-------------------------" << endl;

  vector<vector<int>> temp = createSubsets(v);
  for (auto el : temp)
  {
    if (el.size() == 0)
      continue;
    for (auto i : el)
      cout << i << " ";
    cout << endl;
  }

  // if (temp == combinations)
  //   cout << "found same. correct code" << endl;
  // else
  //   cout << "vectors are not same => some error" << endl;
}
