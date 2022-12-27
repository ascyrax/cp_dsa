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
int mod = 1e9 + 7;
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
    segTree[node] = min(segTree[node * 2 + 1], segTree[node * 2 + 2]);
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
      return min(query(l, r, node * 2 + 1, lx, (lx + rx) / 2), query(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx));
  }
};
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  vector<pair<int, pair<int, int>>> a; // first is the length and second.first is the starting no and second.second is the index.
  vector<int> ps(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    // i / a[i] can range from b[i](inclusive) to b[i]+1(exclusive)
    // a[i] can range from (i/(b[i]+1))(exclusive) to (i/(b[i]))(inclusive).
    // => a[i] can range from (i/(b[i]+1))+1(inclusive) to (i/b[i])(inclusive)

    int mnai = i / (b[i] + 1) + 1;
    int mxai;
    if (b[i] != 0)
      mxai = min(n, i / (b[i])); // i.e = 1/b[i] basically
    else
      mxai = n;

    int rangeLength = mxai - mnai + 1;
    a.pb(make_pair(rangeLength, make_pair(mnai, i)));
    ps[mnai - 1]++;
    ps[mxai]--;
  }
  for (int i = 1; i < n + 1; i++)
  {
    ps[i] = ps[i - 1] + ps[i];
  }

  segmentTree st;
  st.build(ps, n + 1);

  sort(a.begin(), a.end());
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++)
  {
    int rangeLen = a[i].first;
    int start = a[i].second.first;
    int index = a[i].second.second;
    int mn = st.query(start - 1, start - 1 + rangeLen - 1);
    ans[i] = mn + 1;
    st.update(ind, mn - 1);
  }
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
}
