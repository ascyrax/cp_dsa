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
//.....................................
int n;

void calcLeft(vector<int> &va, vector<int> &left)
{
  stack<int> st;
  int ptr = 0;
  while (ptr <= n - 1)
  {
    if (st.empty())
    {
      left[ptr] = -1;
      st.push(ptr);
    }
    else
    {
      if (va[st.top()] > va[ptr])
      {
        left[ptr] = st.top();
        st.push(ptr);
      }
      else if (va[st.top()] <= va[ptr])
      {
        st.pop();
        continue;
      }
    }
    ptr++;
  }
}
void calcRight(vector<int> &va, vector<int> &right)
{
  stack<int> st;
  int ptr = n - 1;
  while (ptr >= 0)
  {
    if (st.empty())
    {
      right[ptr] = n;
      st.push(ptr);
    }
    else
    {
      if (va[st.top()] > va[ptr])
      {
        right[ptr] = st.top();
        st.push(ptr);
      }
      else if (va[st.top()] <= va[ptr])
      {
        st.pop();
        continue;
      }
    }
    ptr--;
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
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; i++)
  {
    cin >> va[i];
  }
  // for every element va[i], find the left and the right boundaries.

  vector<int> left(n), right(n);
  // left[i] = most adjacent index on the left of index i, such that va[left[i]]>left[i].

  calcLeft(va, left);
  calcRight(va, right);

  cout << "left" << endl;
  for (auto el : left)
    cout << el << " ";
  cout << endl;
  cout << "right" << endl;
  for (auto el : right)
    cout << el << " ";
  cout << endl;

  vector<int> ps(n);
  ps[0] = va[0];
  for (int i = 1; i < n; i++)
    ps[i] = ps[i - 1] + va[i];

  vector<int> psInv(n);
  psInv[n - 1] = va[n - 1];
  for (int i = n - 2; i >= 0; i--)
    psInv[i] = psInv[i + 1] + va[i];

  segmentTree st, stInv;
  st.build(ps, n);
  stInv.build(psInv, n);

  cout << "ps" << endl;
  for (auto el : ps)
    cout << el << " ";
  cout << endl;
  cout << "psInv" << endl;
  for (auto el : psInv)
    cout << el << " ";
  cout << endl;
  cout << "segTree" << endl;
  for (auto el : st.segTree)
    cout << el << " ";
  cout << endl;
  cout << "segTreeInv" << endl;
  for (auto el : stInv.segTree)
    cout << el << " ";
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    int val = va[i];
    // we will check for all the substrings for which val is the max element.
    int lval = left[i];
    int rval = right[i];
    cout << "------" << endl;
    cout << "i = " << i << endl;
    cout << "val = " << val << endl;
    cout << "lval = " << lval << endl;
    cout << "rval = " << rval << endl;
    // int mnPsOnLeft = min(ps[lval - 1], st.query(lval, i - 1));
    int mnPsOnLeft = inf;
    if (lval >= 0)
      mnPsOnLeft = st.query(lval, i - 1);
    else
      mnPsOnLeft = st.query(0, i - 1);

    int mnPsOnRight = inf;
    if (rval <= n - 1)
      mnPsOnRight = stInv.query(i + 1, rval);
    else
      mnPsOnRight = stInv.query(i + 1, n - 1);

    cout << "mnPsOnLeft = " << mnPsOnLeft << endl;
    cout << "mnPsOnRight = " << mnPsOnRight << endl;
    // st.query(i + 1, rval);
    if ((ps[i] - mnPsOnLeft > val) || (psInv[i] - mnPsOnRight > val))
    {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}
