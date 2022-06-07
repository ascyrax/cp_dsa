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
//         freopen("paintbarn.in", "r", stdin);
//         freopen("paintbarn.out", "w", stdout);
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

// //...............................

// //...............................

// void suraj()
// {
//         int n, k;
//         cin >> n >> k;
//         vector<vector<int>> dp(1005, vector<int>(1005, 0));

//         while (n--)
//         {
//                 int a, b, c, d;
//                 cin >> a >> b >> c >> d;
//                 for (int i = a; i < c; i++)
//                 {
//                         dp[i][b]++;
//                         dp[i][d]--;
//                 }
//         }
//         // for (int i = 0; i <= 10; i++)
//         // {
//         //         for (int j = 0; j <= 10; j++)
//         //         {
//         //                 cout << dp[i][j] << " ";
//         //         }
//         //         cout << endl;
//         // }
//         int ret = 0;
//         for (int i = 0; i <= 1000; i++)
//         {
//                 for (int j = 0; j <= 1000; j++)
//                 {
//                         if (dp[i][j] == k)
//                                 ret++;
//                         dp[i][j + 1] += dp[i][j];
//                 }
//         }
//         // for (int i = 0; i <= 10; i++)
//         // {
//         //         for (int j = 0; j <= 10; j++)
//         //         {
//         //                 cout << dp[i][j] << " ";
//         //         }
//         //         cout << endl;
//         // }
//         cout << ret << endl;
// }

// //................................

// 2D prefix sum

// @author: ascyrax

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define pb push_back

double startTime;
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        freopen("paintbarn.in", "r", stdin);
        freopen("paintbarn.out", "w", stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n, k;
        cin >> n >> k;
        vector<vector<int>> dp(1005, vector<int>(1005, 0));
        while (n--)
        {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                dp[a][b]++;
                dp[a][d]--;
                dp[c][b]--;
                dp[c][d]++;
        }
        // for (int i = 0; i <= 10; i++)
        // {
        //         for (int j = 0; j <= 10; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        int ret = 0;
        for (int i = 0; i <= 1000; i++)
        {
                for (int j = 0; j <= 1000; j++)
                {
                        if (i && j)
                                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i][j] - dp[i - 1][j - 1];
                        else if (j)
                                dp[i][j] = dp[i][j - 1] + dp[i][j];
                        else if (i)
                                dp[i][j] = dp[i - 1][j] + dp[i][j];

                        if (dp[i][j] == k)
                                ret++;
                }
        }
        // for (int i = 0; i <= 10; i++)
        // {
        //         for (int j = 0; j <= 10; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        cout << ret << endl;
}

//................................
