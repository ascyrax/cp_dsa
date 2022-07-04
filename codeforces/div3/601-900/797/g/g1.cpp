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

  // ioss

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
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  set<int> engines;
  engines.insert(1);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (i >= 1)
      if (v[i] < v[i - 1])
        engines.insert(i + 1);
  }

  cout << "engines" << endl;
  for (auto el : engines)
    cout << el << " ";
  cout << endl;

  for (int i = 0; i < m; i++)
  {
    int index, delta;
    cin >> index >> delta;
    // index--;
    // change v[index]
    cout << "i: " << i << endl;
    // cout << index << " " << v[index] - delta << endl;
    int newVal = v[index - 1] - delta;

    // check whether this index's value acts as the engine of a new train or not.
    auto left = engines.lower_bound(index);
    left--;
    cout << "*left = " << *left << endl;
    if (v[*left - 1] <= newVal)
    {
      cout << "v[*left] <= newVal" << endl;
      // do nothing as no new train/engine is formed
    }
    else if (newVal < (v[*left - 1]))
    {
      cout << "newVal < v[*left]" << endl;
      engines.insert(index);
      // currntly *left > newVal as the index corresponding to (left) < index . so we wont modify these values.
      ++left; // now left represents the index == index
      ++left; // now left represents the indices > index
      while (1)
      {
        if (left == engines.end())
          break;
        if (v[*left - 1] >= newVal)
        {
          engines.erase(left);
        }
        else
          break;
      }
    }
    cout << "engines" << endl;
    for (auto el : engines)
      cout << el << " ";
    cout << endl;
    cout << "-------------------------" << endl;
    // cout << engines.size() << " ";
    v[index - 1] = newVal;
  }
  cout << endl;
}
