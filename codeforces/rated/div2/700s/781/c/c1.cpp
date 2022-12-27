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

//...............................
// vector<vector<int>> tree;
vector<int> parent;
vector<vector<int>> child;
//...............................

void suraj()
{
  int n;
  cin >> n;
  set<int> setParents;
  // tree = vector<vector<int>>(n + 1, vector<int>());
  parent = vector<int>(n + 1, -1);
  child = vector<vector<int>>(n + 1, vector<int>());

  for (int i = 2; i <= n; i++)
  {
    int temp;
    cin >> temp;
    parent[i] = temp;
    setParents.insert(temp);
    child[temp].pb(i);
    // tree[i].pb(temp);
    // tree[temp].pb(i);
  }

  // first we will do 'time' no of insertions.
  int time = setParents.size();
  // cout << "time = " << time << endl;
  vector<int> healthy; // refering to healthy children of each parent
  for (int i : setParents)
  {
    healthy.pb(child[i].size());
  }
  sort(healthy.begin(), healthy.end());
  // cout << "ascending sort" << endl;
  // for (auto el : healthy)
  //   cout << el << " ";
  // cout << endl;

  for (int i = 0; i < healthy.size(); i++)
  {
    healthy[i] -= i;
  }
  sort(healthy.rbegin(), healthy.rend());

  for (int i = 0; i < healthy.size(); i++)
  {
    if (healthy[i] <= 0)
    {
      healthy.resize(i);
      break;
    }
  }
  int equal = 1;
  int aa = 0;
  while (healthy.size() > 0)
  {
    equal = 1;
    // aa++;
    // if (aa == 10)
    //   break;
    // check if any new equal
    for (int i = equal; i < healthy.size(); i++)
    {
      // cout << "healthy" << endl;
      // for (auto el : healthy)
      //   cout << el << " ";
      // cout << endl;
      if (healthy[i] == healthy[i - 1])
        equal++;
      else
        break;
    }

    if (equal == healthy.size())
    {
      // every {equal} steps, value decreases by {equal+1}.
      int quo = healthy[0] / (equal + 1);
      int rem = healthy[0] % (equal + 1);
      time += quo * equal + (rem + 1) / 2;
      break;
    }
    // first {equal} are equal.
    int diff = abs(healthy[equal] - healthy[equal - 1]);
    if (diff * equal + diff <= healthy[0])
    {
      time += diff * equal;
      for (int i = 0; i < healthy.size(); i++)
      {
        healthy[i] -= (diff * equal + diff);
        if (healthy[i] <= 0)
        {
          healthy.resize(i);
          break;
        }
      }
    }
    else
    {
      time += healthy[0];
      break;
    }
  }
  cout << time << endl;
}

//................................

// int

// int

// int

// int
