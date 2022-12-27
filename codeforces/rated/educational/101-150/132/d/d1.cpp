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
int inf = -1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
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
    segTree[node] = max(segTree[node * 2 + 1], segTree[node * 2 + 2]);
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
    segTree[node] = max(segTree[node * 2 + 1], segTree[node * 2 + 2]);
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
      return max(query(l, r, node * 2 + 1, lx, (lx + rx) / 2), query(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx));
  }
};
//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;

  vector<int> h(m);
  for (int i = 0; i < m; i++)
  {
    cin >> h[i];
  }

  segmentTree st;
  st.build(h, m);

  int q;
  cin >> q;
  // print("st.segTree", st.segTree);
  // cout << st.query(0, 0) << endl;

  for (int i = 0; i < q; i++)
  {
    // cout << "i: " << i << endl;
    int xs, ys, xf, yf, k;
    cin >> xs >> ys >> xf >> yf >> k;
    int mxHeight = st.query(min(ys - 1, yf - 1), max(ys - 1, yf - 1));
    // cout << "mxHeight: " << mxHeight << endl;
    int diff = mxHeight - xs;
    int height = xs;
    if (diff >= 0)
    {
      int q = diff / k;
      int r = diff % k;
      // if (r == 0)
      r = 1;
      height = xs + q * k + r * k;
    }
    // cout << "height: " << height << endl;
    if (height > n)
    {
      cout << "NO" << endl;
      continue;
    }
    int dy = abs(height - xf);
    int dx = abs(ys - yf);
    if (dx % k == 0 && dy % k == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
