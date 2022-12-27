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

//.....................................
void print(stack<pair<int, int>> st)
{
  while (!st.empty())
  {
    cout << st.top().first << " " << st.top().second << " , ";
    st.pop();
  }
  cout << endl;
}

void print(vector<int> v)
{
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}

vector<int> findGreaterOnLeft(vector<int> v)
{
  int len = v.size();
  stack<pair<int, int>> st;
  vector<int> result(len);
  for (int i = 0; i < len; i++)
  {
    // cout << "i = " << i << endl;
    // print(st);
    while (1)
    {
      if (st.empty())
      {
        result[i] = -1;
        st.push(make_pair(v[i], i));
        break;
      }
      if (st.top().first > v[i])
      {
        result[i] = st.top().second;
        st.push(make_pair(v[i], i));
        break;
      }
      else if (st.top().first == v[i])
      {
        result[i] = result[st.top().second];
        st.push(make_pair(v[i], i));
        break;
      }
      else
        st.pop();
      // cout << "inside while" << endl;
      // print(st);
      // cout << "inside while" << endl;
    }
    // cout << "after while" << endl;
    // print(st);
  }
  // cout << "end" << endl;
  return result;
}

vector<int> findGreaterOnRight(vector<int> v)
{
  int len = v.size();
  stack<pair<int, int>> st;
  vector<int> result(len);
  for (int i = 0; i < len; i++)
  {
    // cout << "i = " << i << endl;
    while (1)
    {
      // print(st);
      if (st.empty())
      {
        st.push(make_pair(v[i], i));
        break;
      }
      if (st.top().first < v[i])
      {
        result[st.top().second] = i;
        st.pop();
      }
      else if (st.top().first == v[i])
      {
        st.push(make_pair(v[i], i));
        break;
      }
      else
      {
        st.push(make_pair(v[i], i));
        break;
      }
    }
  }
  while (!st.empty())
  {
    result[st.top().second] = len;
    st.pop();
  }
  return result;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  // cout << "v" << endl;
  // for (auto el : v)
  //   cout << el << " ";
  // cout << endl;

  vector<int> greaterOnLeft = findGreaterOnLeft(v);
  // cout << "greaterOnLeft" << endl;
  // for (auto el : greaterOnLeft)
  //   cout << el << " ";
  // cout << endl;

  vector<int> greaterOnRight = findGreaterOnRight(v);
  // cout << "greaterOnRight" << endl;
  // for (auto el : greaterOnRight)
  //   cout << el << " ";
  // cout << endl;

  // prefix sums
  vector<int> prefixSum(n);
  prefixSum[0] = v[0];
  for (int i = 1; i < n; i++)
    prefixSum[i] = prefixSum[i - 1] + v[i];
  // soimilarly suffix sums
  vector<int> suffixSum(n);
  suffixSum[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--)
    suffixSum[i] = suffixSum[i + 1] + v[i];

  // cout << "prefix sum" << endl;
  // print(prefixSum);
  // cout << "suffix sum" << endl;
  // print(suffixSum);

  segmentTree suffixSegTree, prefixSegTree;

  prefixSegTree.build(prefixSum, n);
  suffixSegTree.build(suffixSum, n);

  // cout << "prefix segment tree" << endl;
  // print(prefixSegTree.segTree);
  // cout << "suffix segment tree" << endl;
  // print(suffixSegTree.segTree);

  // cout << prefixSegTree.query(0, 0) << endl;
  // cout << prefixSegTree.query(1, 1) << endl;
  // cout << prefixSegTree.query(2, 2) << endl;
  // cout << prefixSegTree.query(3, 3) << endl;

  // cout << prefixSegTree.query(0, n) << endl;
  // cout << prefixSegTree.query(0, n / 2) << endl;
  // cout << prefixSegTree.query(n / 2, n) << endl;
  // cout << prefixSegTree.query(0, n / 4) << endl;
  // cout << prefixSegTree.query(n / 4, n / 2) << endl;
  // cout << prefixSegTree.query(n / 2, 3 * n / 4) << endl;
  // cout << prefixSegTree.query(n * 3 / 4, n / 4) << endl;

  // find if all possible substrings has max>sum or not.
  for (int i = 0; i < n; i++)
  {
    // iterating over each element
    int curEl = v[i];
    // cout << "curEl ->" << curEl << endl;
    // we need to know the left greater and the right greater values.
    int left = greaterOnLeft[i];
    int right = greaterOnRight[i];
    // cout << "left ->" << left << endl;
    // cout << "right ->" << right << endl;

    // substrings for which v[i] is max and max>sum of the  substring
    // are the ones that begin between [left+1,i] and end between [i,right-1] indices.
    int mxLeft, mxRight;
    if (left >= 0)
      mxLeft = prefixSegTree.query(left + 1, i) - prefixSum[left];
    else if (left == -1)
      mxLeft = prefixSegTree.query(left + 1, i) - 0;
    if (right <= n - 1)
      mxRight = suffixSegTree.query(i, right - 1) - suffixSum[right];
    else if (right == n)
      mxRight = suffixSegTree.query(i, right - 1) - 0;
    // cout << "mxLeft: " << mxLeft << endl;
    // cout << "mxRight: " << mxRight << endl;
    if (max(mxLeft, mxRight) > v[i])
    {
      // => sum > max
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
