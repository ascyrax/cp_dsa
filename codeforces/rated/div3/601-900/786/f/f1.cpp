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

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}
void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................
int sum(int a, int b) { return a + b; }
int inf = 0; // since we need to sum inside the segtree.
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
  int build(vector<int> &v, int lenv, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      // we are dealing with the leaves
      if (lx < lenv)
        segTree[node] = v[lx];
      else
        segTree[node] = inf;
      return segTree[node];
    }
    build(v, lenv, node * 2 + 1, lx, (lx + rx) / 2);
    build(v, lenv, node * 2 + 2, (lx + rx) / 2 + 1, rx);
    segTree[node] = sum(segTree[node * 2 + 1], segTree[node * 2 + 2]);
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
    segTree[node] = sum(segTree[node * 2 + 1], segTree[node * 2 + 2]);
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
        return inf;
    }
    if (lx >= l && rx <= r)
      return segTree[node];
    else if (rx < l || lx > r)
      return inf; // i.e. this segment should not contribute to the ans;
    else
      return sum(query(l, r, node * 2 + 1, lx, (lx + rx) / 2), query(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx));
  }
};
//.....................................

void suraj()
{
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> v(n * m, 0);
  for (int i = 0; i < n; i++)
  {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++)
    {
      if (row[j] == '.')
      {
        v[n * j + i] = 0;
      }
      else if (row[j] == '*')
      {
        v[n * j + i] = 1;
      }
    }
  }

  // print("v", v);

  segmentTree st;
  st.build(v, n * m);

  // print("st.segTree", st.segTree);

  for (int i = 0; i < q; i++)
  {
    int r, c;
    cin >> r >> c;
    r--;
    c--;

    int index = c * n + r;

    // cout << "index: " << index << endl;

    if (v[index] == 1)
    {
      v[index] = 0;
      st.update(index, v[index]);
    }
    else if (v[index] == 0)
    {
      v[index] = 1;
      st.update(index, v[index]);
    }

    // print("st.segTree", st.segTree);

    int totalIcons = st.query(0, n * m - 1); // total no of 1s
    // cout << "totalIcons: " << totalIcons << endl;
    int goodIcons = st.query(0, totalIcons - 1);
    // cout << "goodIcons: " << goodIcons << endl;
    cout << totalIcons - goodIcons << endl;
  }
}
