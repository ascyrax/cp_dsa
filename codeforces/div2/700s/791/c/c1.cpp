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

//.....................................
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
    segTree = vector<int>(2 * len - 1, 0);
    build(v, n, 0, 0, len - 1);
  }
  int build(vector<int> &v, int lenv, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      // we are dealing with the leaves
      if (lx < lenv)
        segTree[node] = v[lx];
      else
        segTree[node] = 0;
      return segTree[node];
    }
    build(v, lenv, node * 2 + 1, lx, (lx + rx) / 2);
    build(v, lenv, node * 2 + 2, (lx + rx) / 2 + 1, rx);
    segTree[node] = min(segTree[node * 2 + 1], segTree[node * 2 + 2]);
    return segTree[node];
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
      segTree[node] = val;
      return segTree[node];
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
    segTree[node] = segTree[node * 2 + 1] + segTree[node * 2 + 2];
    return segTree[node];
  }

  // RANGE QUERIES IN O(LOG N)
  int query(int l, int r)
  {
    return query(l, r, 0, 0, len - 1);
  }
  int query(int l, int r, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      if (lx >= l && lx <= r)
        return segTree[node];
      else
        return 0;
    }
    if (lx >= l && rx <= r)
      return segTree[node];
    else if (rx < l || lx > r)
      return 0; // i.e. this segment should not contribute to the ans;
    else
      return query(l, r, node * 2 + 1, lx, (lx + rx) / 2) + query(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx);
  }
};
//.....................................

//.....................................

void suraj()
{
  int n, q;
  cin >> n >> q;

  vector<int> vx(n, 0), vy(n, 0);

  segmentTree stx, sty;
  stx.build(vx, n);
  sty.build(vy, n);

  map<int, int> mx, my;

  for (int i = 0; i < q; i++)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      mx[x]++;
      my[y]++;
      stx.update(x, 1);
      sty.update(y, 1);
    }
    else if (t == 2)
    {
      int x, y;
      cin >> x >> y;
      x--;
      y--;

      if (mx[x] == 1)
        stx.update(x, 0);
      mx[x]--;

      if (my[y] == 1)
        sty.update(y, 0);
      my[y]--;
    }
    else
    {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--, y1--, x2--, y2--;
      int qx = stx.query(x1, x2);
      int qy = sty.query(y1, y2);
      // cout << qx << " " << qy << endl;
      if (qx == (abs(x1 - x2) + 1) || qy == (abs(y1 - y2) + 1))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    // cout << "stx segTree" << endl;
    // for (int el : stx.segTree)
    //   cout << el << " ";
    // cout << endl;
    // for (int el : sty.segTree)
    //   cout << el << " ";
    // cout << endl;
  }
}
