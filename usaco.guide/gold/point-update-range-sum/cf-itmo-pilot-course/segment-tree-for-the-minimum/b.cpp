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

//.....................................
int inf = 1e9;
struct segmentTree
{
  vector<int> segTree;
  int len;

  // BUILDING THE SEG TREE IN O(N).
  void build(vector<int> &v, int n)
  {
    len = 1;
    while (len < n)
      len *= 2;
    segTree = vector<int>(2 * len - 1, inf);
    build(v, n, 0, 0, len - 1);
  }
  void build(vector<int> &v, int lenv, int node, int lx, int rx)
  {
    // cout << node << " " << lx << " " << rx << endl;
    // for (int i : segTree)
    //   cout << i << " ";
    // cout << endl;
    if (lx == rx)
    {
      // we are dealing with the leaves
      if (lx < lenv)
        segTree[node] = v[lx];
      else
        segTree[node] = inf;
      return; // segTree[node];
    }
    build(v, lenv, node * 2 + 1, lx, (lx + rx) / 2);
    build(v, lenv, node * 2 + 2, (lx + rx) / 2 + 1, rx);
    segTree[node] = min(segTree[node * 2 + 1], segTree[node * 2 + 2]);
    return; // segTree[node];
  }

  // POINT UPDATES IN O(LOG N)
  void update(int index, int val)
  {
    update(index, val, 0, 0, len - 1);
  }
  int update(int index, int val, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      // if (lx != index)
      //   return segTree[node];
      // else
      // {
      segTree[node] = val;
      return segTree[node];
      // }
    }
    int mid = (lx + rx) / 2;
    if (index <= mid)
    {
      update(index, val, node * 2 + 1, lx, (lx + rx) / 2);
    }
    else if (index > mid)
    {
      update(index, val, node * 2 + 2, (lx + rx) / 2 + 1, rx);
    }
    segTree[node] = min(segTree[node * 2 + 1], segTree[node * 2 + 2]);
    return segTree[node];
  }

  // RANGE QUERIES IN O(LOG N)
  int findMin(int l, int r)
  {
    return findMin(l, r, 0, 0, len - 1);
  }
  int findMin(int l, int r, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      if (lx >= l && lx <= r)
        return segTree[node];
      else
        return 1e9;
    }
    if (lx >= l && rx <= r)
      return segTree[node];
    else if (rx < l || lx > r)
      return 1e9; // i.e. this segment should not contribute to the ans;
    else
      return min(findMin(l, r, node * 2 + 1, lx, (lx + rx) / 2), findMin(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx));
  }
};
//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  segmentTree st;
  st.build(v, n);

  for (int i = 0; i < m; i++)
  {
    // for (int i : st.segTree)
    //   cout << i << " ";
    // cout << endl;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
    {
      st.update(b, c);
    }
    else if (a == 2)
    {
      cout << st.findMin(b, c - 1) << endl;
    }
  }
}
