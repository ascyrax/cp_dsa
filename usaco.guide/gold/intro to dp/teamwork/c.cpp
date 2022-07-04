// // @author: ascyrax
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// #define endl "\n"
// #define ioss                   \
//   ios::sync_with_stdio(false); \
//   cin.tie(0);
// #define int long long
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front

// double startTime;

// double gct() // get_current_time
// {
//   return ((double)clock() - startTime) / CLOCKS_PER_SEC;
// }

// void suraj();

// signed main()
// {

//   ioss

//       // startTime=(double)clock();

//       freopen("teamwork.in", "r", stdin);
//   freopen("teamwork.out", "w", stdout);

//   // cout << setprecision(15) << fixed;

//   int t = 1;

//   // cin >> t;

//   for (int i = 1; i <= t; i++)
//   {

//     // cout<<"Case #"<<i<<": ";

//     suraj();
//   }

//   return 0;
// }

// int inf = 1e18;
// //.....................................

// //.....................................

// //.....................................
// struct segmentTree
// {
//   vector<int> segTree;
//   int len;

//   // BUILDING THE SEG TREE IN O(N).
//   void build(vector<int> &v, int n)
//   {
//     len = 1;
//     while (len < n)
//       len *= 2;
//     segTree = vector<int>(2 * len - 1, -inf);
//     build(v, n, 0, 0, len - 1);
//   }
//   int build(vector<int> &v, int lenv, int node, int lx, int rx)
//   {
//     if (lx == rx)
//     {
//       // we are dealing with the leaves
//       if (lx < lenv)
//         segTree[node] = v[lx];
//       else
//         segTree[node] = -inf;
//       return segTree[node];
//     }
//     build(v, lenv, node * 2 + 1, lx, (lx + rx) / 2);
//     build(v, lenv, node * 2 + 2, (lx + rx) / 2 + 1, rx);
//     segTree[node] = max(segTree[node * 2 + 1], segTree[node * 2 + 2]);
//     return segTree[node];
//   }

//   // POINT UPDATES IN O(LOG N)
//   void update(int index, int val)
//   {
//     update(index, val, 0, 0, len - 1);
//   }
//   int update(int index, int val, int node, int lx, int rx)
//   {
//     if (lx == rx)
//     {
//       segTree[node] = val;
//       return segTree[node];
//     }
//     int mid = (lx + rx) / 2;
//     if (index <= mid)
//     {
//       update(index, val, node * 2 + 1, lx, (lx + rx) / 2);
//     }
//     else if (index > mid)
//     {
//       update(index, val, node * 2 + 2, (lx + rx) / 2 + 1, rx);
//     }
//     segTree[node] = max(segTree[node * 2 + 1], segTree[node * 2 + 2]);
//     return segTree[node];
//   }

//   // RANGE QUERIES IN O(LOG N)
//   int query(int l, int r)
//   {
//     return query(l, r, 0, 0, len - 1);
//   }
//   int query(int l, int r, int node, int lx, int rx)
//   {
//     if (lx == rx)
//     {
//       if (lx >= l && lx <= r)
//         return segTree[node];
//       else
//         return -inf;
//     }
//     if (lx >= l && rx <= r)
//       return segTree[node];
//     else if (rx < l || lx > r)
//       return -inf; // i.e. this segment should not contribute to the ans;
//     else
//       return max(query(l, r, node * 2 + 1, lx, (lx + rx) / 2), query(l, r, node * 2 + 2, (lx + rx) / 2 + 1, rx));
//   }
// };
// //.....................................

// void suraj()
// {
//   int n, k;
//   cin >> n >> k;

//   vector<int> v(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> v[i];
//   }

//   segmentTree st;
//   st.build(v, n);
//   // cout << "segTree" << endl;
//   // for (auto el : st.segTree)
//   //   cout << el << " ";
//   // cout << endl;

//   vector<vector<int>> dp(n, vector<int>(k + 1, 0));
//   // dp[i][j] = max sum of skill levels of the first i cows if the ith cow is in a team of size j.

//   dp[0][0] = 0;
//   dp[0][1] = v[0];

//   vector<int> mxTill(n, 0);
//   mxTill[0] = dp[0][1];

//   for (int i = 1; i < n; i++)
//   {
//     for (int j = 1; j <= k; j++)
//     {
//       if (j > i + 1)
//         break;

//       if (j > 1)
//       {
//         if (j == i + 1)
//           dp[i][j] = 0 + j * st.query(i - j + 1, i);
//         else if (j < i + 1)
//           dp[i][j] = mxTill[i - j] + j * st.query(i - j + 1, i);
//       }
//       else
//       {
//         dp[i][1] = mxTill[i - 1] + v[i];
//       }
//       mxTill[i] = max(mxTill[i], dp[i][j]);
//     }
//   }

//   int ans = 0;
//   for (int j = 1; j <= k; j++)
//   {
//     ans = max(ans, dp[n - 1][j]);
//   }
//   cout << ans << endl;

//   // for (int i = 0; i < n; i++)
//   // {
//   //   for (int j = 1; j <= k; j++)
//   //   {
//   //     cout << dp[i][j] << " ";
//   //   }
//   //   cout << endl;
//   // }
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<int> skill(n);
  for (int i = 0; i < n; i++)
  {
    cin >> skill[i];
  }

  vector<int> dp(n, -1);
  for (int i = 0; i < n; i++)
  {
    // by not joining it to a team, the default value is just skill[i]
    int cur = skill[i];
    for (int j = i; j >= (i - k + 1) && ~j; j--)
    {
      cur = max(cur, skill[j]);
      /*
       * update answer: dp[i] = max(dp[i],
       * the skill of joining this cow to a team + all of the previous sums)
       */
      if (j > 0)
      {
        dp[i] = max(dp[i], dp[j - 1] + (cur * (i - j + 1)));
      }
      else
      {
        dp[i] = max(dp[i], cur * (i - j + 1));
      }
    }
  }
  cout << dp[n - 1] << endl;
}
