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

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;

  vector<vector<int>> tree = vector<vector<int>>(n, vector<int>());
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }

  vector<int> isLeaf(n, false);
  for (int i = 0; i < n; i++)
    if (tree[i].size() == 1)
      isLeaf[i] = true;

  for (int i = 0; i < n; i++)
  {
    if (!isLeaf[i])
    {
      // if this node is not a leaf
      if (tree[i].size() == 2)
      {
        // i m trying to find a straight line consisting of 3 nodes and 2 edges.
        // if i m able to find that => these 2 edges will always have the same edge value => ans ="NO"
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
