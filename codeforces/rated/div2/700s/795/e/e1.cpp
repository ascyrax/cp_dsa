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
int inf = -1e9;
//.....................................
void print(vector<int> v)
{
  // cout << "segTree" << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
struct segmentTree
{
  vector<int> segTree;
  int len;

  // BUILDING THE SEG TREE IN O(N).
  void build(vector<int> &v, int n)
  {
    // cout << "n = " << n << endl;
    len = 1;
    while (len < n)
      len *= 2;
    // cout << "len = " << len << endl;
    segTree = vector<int>(2 * len - 1, inf);
    // cout << "1st" << endl;
    // print(segTree);
    build(v, n, 0, 0, len - 1);
    // cout << "2nd" << endl;
    // print(segTree);
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
struct box
{
  int col, l, r, index;
};
//.....................................
void print(string s, vector<box> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el.col << " " << el.l << " " << el.r << " " << el.index << endl;
}
void print(box b)
{
  cout << b.col << " " << b.l << " " << b.r << " " << b.index << endl;
}
void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
bool custom(box &a, box &b)
{
  // cout << "a = ";
  // print(a);
  // cout << "b = ";
  // print(b);
  // inside the vector ... b , a ..... is the order.
  // if we return true => .... a , b .... will be the new order
  if (a.l < b.l) // => whichevers l is smaller will be on the left after the array is sorted => ascending
  {
    // cout << "if" << endl;
    return true;
  }
  else if (a.l == b.l)
  {
    // cout << "else if" << endl;
    if (a.r < b.r)
      return true;
    else
      return false;
  }
  else
  {
    // cout << "else" << endl;
    return false;
  }
}
//.....................................

//...............................
void suraj()
{
  int n;
  cin >> n;
  vector<box> v;
  vector<box> blue, red;
  for (int i = 0; i < n; i++)
  {
    box temp;
    cin >> temp.col >> temp.l >> temp.r;
    temp.index = i;
    // col = 0 => red,
    // col = 1 => blue.
    v.pb(temp);
    if (temp.col == 1)
      blue.pb(temp);
    else if (temp.col == 0)
      red.pb(temp);
  }

  sort(v.begin(), v.end(), custom);
  sort(blue.begin(), blue.end(), custom);
  sort(red.begin(), red.end(), custom);

  print("v", v);
  print("blue", blue);
  print("red", red);

  vector<int> vBlue, vRed;
  for (int i = 0; i < blue.size(); i++)
    vBlue.pb(blue[i].l);
  for (int i = 0; i < red.size(); i++)
    vRed.pb(red[i].l);

  print("vBlue", vBlue);
  print("vRed", vRed);

  segmentTree stBlue, stRed;
  vector<int> temp;
  for (auto el : blue)
    temp.pb(el.r);
  stBlue.build(temp, blue.size());
  // stBlue.build(temp, n);

  temp.clear();

  for (auto el : red)
    temp.pb(el.r);
  stRed.build(temp, red.size());
  // stRed.build(temp, n);

  print("stBlue", stBlue.segTree);
  print("stRed", stRed.segTree);

  vector<int> parent(n, -1);
  for (int i = 0; i < n; i++)
    parent[i] = i;

  for (int i = 0; i < n; i++)
  {
    box b = v[i];
    cout << "-------------------------" << endl;
    cout << "i = " << i << endl;
    cout << "current box = ";
    print(b);
    // blue box
    if (b.col == 1)
    {
      // last red box which begins before the ending of this blue box
      int loc = upper_bound(vRed.begin(), vRed.end(), b.r) - vRed.begin();
      cout << "loc = " << loc << endl;
      // the red with the rightmost ending point, among all these red boxes
      int rightmostRed = stRed.query(0, loc - 1);
      cout << "rightmostRed = " << rightmostRed << endl;

      if (red[rightmostRed].r >= b.l)
      { // if this blue and any(i.e. rightmostRed) intersect
        parent[b.index] = parent[red[rightmostRed].index];
      }
    }
    // red box
    else
    {
      int loc = upper_bound(vBlue.begin(), vBlue.end(), b.r) - vBlue.begin();
      int rightmostBlue = stBlue.query(0, loc - 1);
      if (blue[rightmostBlue].r >= b.l)
      {
        parent[b.index] = parent[blue[rightmostBlue].index];
      }
    }
    cout << "parent" << endl;
    print(parent);
  }

  set<int> parentSet;
  for (auto el : parent)
    parentSet.insert(el);
  cout << parentSet.size() << endl;
}
