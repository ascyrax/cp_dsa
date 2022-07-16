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

int inf = -1e18;
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
  int n;
  cin >> n;
  vector<int> v(2 * n), indexOf(2 * n + 1);
  for (int i = 0; i < 2 * n; i++)
  {
    cin >> v[i];
    indexOf[v[i]] = i;
  }

  segmentTree st;
  st.build(v, 2 * n);
  vector<int> ssSize; // subset sizes
  int l = 0, r = 2 * n - 1;

  // print("st.segTree", st.segTree);

  while (r > l)
  {
    // cout << "l: " << l << " , r: " << r << endl;
    int mx = st.query(l, r);
    // cout << "mx: " << mx << endl;
    int ind = indexOf[mx];
    // cout << "ind: " << ind << endl;
    ssSize.pb(r - ind + 1);
    // print("ssSize", ssSize);
    r = ind - 1;
    // cout << "r: " << r << endl;
  }
  if (r == l)
    ssSize.pb(1);
  r--;

  // check if sum of any combination of ssSize = n or not.
  int lenss = ssSize.size();
  ssSize.pb(0); // so that i can 1-index this in the below loop.
  sort(ssSize.begin(), ssSize.end());
  vector<vector<bool>> dp(n + 1, vector<bool>(lenss + 1, false));
  // dp[i][j]=is it possible to form the sum i using the first j indices' values.
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= lenss; j++)
    {
      if (j == 0)
      {
        if (i == 0)
          dp[i][j] = true;
        else
          dp[i][j] = false;
      }
      else if ((i - ssSize[j] >= 0) && (j - 1 >= 0))
        dp[i][j] = dp[i - ssSize[j]][j - 1] || dp[i][j - 1];
      else if (j - 1 >= 0)
      {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }

  if (dp[n][lenss])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  // cout << "---------------" << endl;
}
