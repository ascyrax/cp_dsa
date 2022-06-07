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
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        freopen("hps.in", "r", stdin);
        freopen("hps.out", "w", stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, k;
vector<string> john;
int dp[100001][21][3];
//...............................

//...............................

void suraj()
{
        cin >> n >> k;
        john = vector<string>(n + 1, "");
        for (int i = 1; i <= n; i++)
        {
                cin >> john[i];
        }
        // let dp[i][j][k] = no of wins for bessie for the first i games if she makes j changes and the current choice is k
        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= k; j++)
                {
                        for (int state = 0; state <= 2; state++)
                        { // assume state={hoof, paper, scissor}
                                int ostate1 = (state + 1) % 3;
                                int ostate2 = (state + 2) % 3;
                                if (i == 0)
                                        dp[i][j][state] = 0;
                                else
                                {
                                        if (j == 0)
                                        {
                                                dp[i][j][state] = dp[i - 1][j][state];
                                                if (john[i] == "H" && state == 1)
                                                {
                                                        dp[i][j][state] += 1;
                                                }
                                                else if (john[i] == "P" && state == 2)
                                                {
                                                        // cout << "p" << endl;
                                                        dp[i][j][state] += 1;
                                                        // cout << "i = " << i << " j = " << j << " state = " << state << endl;
                                                        // cout << dp[i][j][state] << endl;
                                                }
                                                else if (john[i] == "S" && state == 0)
                                                {
                                                        dp[i][j][state] += 1;
                                                }
                                        }
                                        else
                                        {
                                                if (j - 1 >= 0)
                                                        dp[i][j][state] = max(max(dp[i - 1][j][state], dp[i - 1][j - 1][ostate1]), dp[i - 1][j - 1][ostate2]);
                                                if (john[i] == "H" && state == 1)
                                                {
                                                        dp[i][j][state] += 1;
                                                }
                                                else if (john[i] == "P" && state == 2)
                                                {
                                                        // cout << "p" << endl;
                                                        dp[i][j][state] += 1;
                                                        // cout << "i = " << i << " j = " << j << " state = " << state << endl;
                                                        // cout << dp[i][j][state] << endl;
                                                }
                                                else if (john[i] == "S" && state == 0)
                                                {
                                                        dp[i][j][state] += 1;
                                                }
                                        }
                                }
                        }
                }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //         for (int j = 0; j <= k; j++)
        //         {
        //                 for (int l = 0; l <= 2; l++)
        //                 {
        //                         cout << dp[i][j][l] << " ";
        //                 }
        //                 cout << endl;
        //         }
        //         cout << endl;
        // }
        cout << max(max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]) << endl;
}

//................................
