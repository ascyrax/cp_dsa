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

//   // ioss

//   // startTime=(double)clock();

//   // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

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

// //.....................................

// void print(string s, vector<int> v)
// {
//   cout << s << endl;
//   for (auto el : v)
//     cout << el << " ";
//   cout << endl;
// }
// void print(string s, set<int> st)
// {
//   cout << s << endl;
//   for (auto el : st)
//     cout << el << " ";
//   cout << endl;
// }
// void print(string s, vector<pair<int, int>> vp)
// {
//   cout << s << endl;
//   for (auto el : vp)
//   {
//     cout << el.first << " " << el.second << endl;
//   }
// }
// int inf = 1e18;
// int mod = 1e9 + 7;
// // int mod = 998244353;
// //.....................................

// //.....................................

// //.....................................

// void suraj()
// {
//   int a, b;
//   cin >> a >> b;

//   vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
//   // dp[i][j] = min no of moves to solve the rectangle of size i*j

//   for (int i = 0; i <= a; i++)
//   {
//     for (int j = 0; j <= b; j++)
//     {
//       if (i == j)
//       {
//         dp[i][j] = 0;
//         continue;
//       }
//       for (int k = 1; k <= j - 1; k++)
//         dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
//       for (int k = 1; k <= i - 1; k++)
//         dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
//     }
//   }

//   cout << dp[a][b] << endl;
// }

#include <iostream >
#include < vector >
using namespace std;
vector<int> adj[10];
int main()
{
  int x, y, nodes, edges;
  cin >> nodes;
  // Number of nodes
  cin >> edges;
  // Number of edges
  for (int i = 0; i < edges; ++i)
  {
    cin >> x >> y;
    adj[x].push_back(y);
    // Insert y in adjacency list of x
  }
  for (int i = 1; i <= nodes; ++i)
  {
    cout << "Adjacency list of node " << i << ": ";
    for (int j = 0; j < adj[i].size(); ++j)
    {
      if (j == adj[i].size() - 1)
        cout << adj[i][j] << endl;
      else
        cout << adj[i][j] << " --> ";
    }
  }
  return 0;
}