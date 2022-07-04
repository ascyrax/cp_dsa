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

int inf = 1e18;
//.....................................
void print(string s, vector<int> &v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................

//.....................................
// i will be dealing with indices only and not the values.
void calcFirstSmallerValOnRight(vector<int> v, vector<int> &firstSmallerValOnRight)
{
  int n = v.size();
  stack<int> st; // will contain the indices, not the values.
  for (int i = n - 1; i >= 0; i--)
  {
    if (i == n - 1)
    {
      firstSmallerValOnRight[i] = inf;
      st.push(i);
      continue;
    }

    while (1)
    {
      if (st.empty())
      {
        firstSmallerValOnRight[i] = inf;
        st.push(i);
        break;
      }
      int stTop = st.top();
      if (v[i] < v[stTop])
      {
        st.pop();
      }
      else if (v[i] > v[stTop])
      {
        firstSmallerValOnRight[i] = stTop;
        st.push(i);
        break;
      }
    }
  }
}

void calcFirstLargerValOnRight(vector<int> v, vector<int> &firstLargerValOnRight)
{
  int n = v.size();
  stack<int> st; // will contain the indices, not the values.
  for (int i = n - 1; i >= 0; i--)
  {
    if (i == n - 1)
    {
      firstLargerValOnRight[i] = inf;
      st.push(i);
      continue;
    }

    while (1)
    {
      if (st.empty())
      {
        st.push(i);
        firstLargerValOnRight[i] = inf;
        break;
      }
      int stTop = st.top();
      if (v[i] < v[stTop])
      {
        firstLargerValOnRight[i] = stTop;
        st.push(i);
        break;
      }
      else
      {
        st.pop();
      }
    }
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
void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  vector<int> firstSmallerValOnRight(n, inf), firstLargerValOnRight(n, inf);
  calcFirstSmallerValOnRight(v, firstSmallerValOnRight);
  calcFirstLargerValOnRight(v, firstLargerValOnRight);

  // print("firstSmallerValOnRight", firstSmallerValOnRight);
  // print("firstLargerValOnRight", firstLargerValOnRight);

  segmentTree stMin, stMax;
  stMin.build(v, n);
  vector<int> vNeg = v;
  for (auto &el : vNeg)
    el *= -1;
  stMax.build(vNeg, n);

  vector<int> indexOf(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    indexOf[v[i]] = i;
  }

  int nSteps = 0;
  for (int i = 0; i <= n - 2;)
  {
    // cout << "i: " << i << endl;
    nSteps++;
    if (i + 1 < n)
    {
      // cout << "i + 1 < n" << endl;
      if (v[i + 1] > v[i])
      {
        // cout << "increase" << endl;
        if (firstSmallerValOnRight[i] == inf)
        {
          int largestInRange = -1 * stMax.query(i, n - 1);
          int index = indexOf[largestInRange];
          i = index;
        }
        else
        {
          int largestInRange = -1 * stMax.query(i, firstSmallerValOnRight[i] - 1);
          int index = indexOf[largestInRange];
          i = index;
        }
      }
      else
      {
        // cout << "decrease" << endl;
        if (firstLargerValOnRight[i] == inf)
        {
          int smallestInRange = stMin.query(i, n - 1);
          int index = indexOf[smallestInRange];
          i = index;
        }
        else
        {
          int smallestInRange = stMin.query(i, firstLargerValOnRight[i] - 1);
          int index = indexOf[smallestInRange];
          i = index;
        }
      }
    }
  }
  cout << nSteps << endl;
  // cout << "-------------------------" << endl;
}
