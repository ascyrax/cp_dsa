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
struct segmentTree
{
  vector<pair<int, int>> segTree;
  int len;

  // BUILDING THE SEG TREE IN O(N).
  void build(vector<int> &v, int n)
  {
    len = 1;
    while (len < n)
      len *= 2;
    segTree = vector<pair<int, int>>(2 * len - 1, make_pair(inf, 1));
    build(v, n, 0, 0, len - 1);
  }
  pair<int, int> build(vector<int> &v, int lenv, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      // we are dealing with the leaves
      if (lx < lenv)
        segTree[node] = make_pair(v[lx], 1);
      else
        segTree[node] = make_pair(inf, 1);
      return segTree[node];
    }
    build(v, lenv, node * 2 + 1, lx, (lx + rx) / 2);
    build(v, lenv, node * 2 + 2, (lx + rx) / 2 + 1, rx);
    if (segTree[node * 2 + 1].first < segTree[node * 2 + 2].first)
    {
      segTree[node] = segTree[node * 2 + 1];
    }
    else if (segTree[node * 2 + 2].first < segTree[node * 2 + 1].first)
    {
      segTree[node] = segTree[node * 2 + 2];
    }
    else if (segTree[node * 2 + 1].first == segTree[node * 2 + 2].first)
    {
      segTree[node].first = segTree[node * 2 + 1].first;
      segTree[node].second = segTree[node * 2 + 1].second + segTree[node * 2 + 2].second;
    }
    return segTree[node];
  }

  // POINT UPDATES IN O(LOG N)
  void update(int index, int val)
  {
    update(index, val, 0, 0, len - 1);
  }
  pair<int, int> update(int index, int val, int node, int lx, int rx)
  {
    if (lx == rx)
    {
      segTree[node] = make_pair(val, 1);
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
    if (segTree[node * 2 + 1].first < segTree[node * 2 + 2].first)
    {
      segTree[node] = segTree[node * 2 + 1];
    }
    else if (segTree[node * 2 + 2].first < segTree[node * 2 + 1].first)
    {
      segTree[node] = segTree[node * 2 + 2];
    }
    else if (segTree[node * 2 + 1].first == segTree[node * 2 + 2].first)
    {
      segTree[node].first = segTree[node * 2 + 1].first;
      segTree[node].second = segTree[node * 2 + 1].second + segTree[node * 2 + 2].second;
    }
    return segTree[node];
  }

  // RANGE QUERIES IN O(LOG N)
  pair<int, int> query(int l, int r)
  {
    return query(l, r, 0, 0, len - 1);
  }
  pair<int, int> query(int l, int r, int node, int lx, int rx)
  {
    // cout << l << " " << r << " " << node << " " << lx << " " << rx << endl;
    if (lx == rx)
    {
      if (lx >= l && lx <= r)
        return segTree[node];
      else
        return make_pair(inf, 1);
    }
    if (lx >= l && rx <= r)
      return segTree[node];
    else if (rx < l || lx > r)
      return make_pair(inf, 1); // i.e. this segment should not contribute to the ans;
    else
    {
      auto a = query(l, r, node * 2 + 1, lx, (lx + rx) / 2);
      auto b = query(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx);
      if (a.first < b.first)
      {
        return a;
      }
      else if (b.first < a.first)
      {
        return b;
      }
      else if (a.first == b.first)
      {
        return make_pair(a.first, a.second + b.second);
      }
    }
  }
};
//.....................................

//.....................................

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
    // cout << "segTree begin" << endl;
    // for (auto el : st.segTree)
    //   cout << el.first << " " << el.second << endl;
    // cout << "segTree end" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
    {
      st.update(b, c);
    }
    else if (a == 2)
    {
      c--;
      pair<int, int> ans = st.query(b, c);
      cout << ans.first << " " << ans.second << endl;
    }
  }
}
