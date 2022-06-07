// // @author: ascyrax

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double ld;

// #define endl "\n"
// #define ioss                         \
//         ios::sync_with_stdio(false); \
//         cin.tie(0);
// #define pb push_back

// double startTime;
// double gct() //get_current_time
// {
//         return ((double)clock() - startTime) / CLOCKS_PER_SEC;
// }
// void suraj();

// int main()
// {
//         ioss
//             startTime = (double)clock();
//         //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
//         //cout << setprecision(15) << fixed << endl;
//         //int t;cin>>t;for(int i=1;i<=t;i++)
//         {
//                 //cout<<"Case #"<<i<<": ";
//                 suraj();
//         }
//         return 0;
// }

// const ll MOD = 1e9 + 7;
// const int INF = int(1e9);
// const int NEG_INF = int(-1e9);
// //const int INF = 2147483647;
// //const int NEG_INF = -2147483647 - 1;
// //............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
// int n, x;
// // int dp[(int)1e6 + 1][101];
// //...............................

// //...............................

// void suraj()
// {
//         cin >> n >> x;
//         vector<int> coins(n);
//         for (int &i : coins)
//                 cin >> i;
//         vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));
//         dp[0][0] = 1;
//         // for (int coin : coins)
//         //         dp[coin][1] = 1;
//         //dp[i][j]=no of ways of getting the sum of i using the first j coins in an ordered manner
//         for (int i = 0; i <= x; i++)
//         {
//                 for (int j = 1; j <= n; j++)
//                 {
//                         // cout << i << " " << j << endl;
//                         dp[i][j] += dp[i][j - 1];
//                         dp[i][j] %= MOD;
//                         if (i - coins[j - 1] >= 0)
//                         {
//                                 dp[i][j] += dp[i - coins[j - 1]][j];
//                                 dp[i][j] %= MOD;
//                         }
//                 }
//         }
//         // for (int i = 1; i <= x; i++)
//         // {
//         //         for (int j = 1; j <= n; j++)
//         //         {
//         //                 cout << dp[i][j] << " ";
//         //         }
//         //         cout << endl;
//         // }
//         cout << dp[x][n] % MOD << endl;
// }

// //................................
#include <bits/stdc++.h>
using namespace std;

int main()
{
        int mod = 1e9 + 7;
        int n, target;
        cin >> n >> target;
        vector<int> x(n);
        for (int &v : x)
                cin >> v;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= target; j++)
                {
                        dp[i][j] = dp[i - 1][j];
                        int left = j - x[i - 1];
                        if (left >= 0)
                        {
                                (dp[i][j] += dp[i][left]) %= mod;
                        }
                }
        }
        cout << dp[n][target] << endl;
}