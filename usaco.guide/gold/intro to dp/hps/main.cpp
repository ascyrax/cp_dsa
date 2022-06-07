/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back

double startTime;
double gct() // get_current_time
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int dp[100001][21][3];

void suraj()
{ ///////////////////////

    int n, k;
    cin >> n >> k;
    vector<string> john(n);
    for (string &i : john)
        cin >> i;
    // 0-hoof 1-paper 2-scissor

    for (int i = 0; i < n; i++)
    {
        if (john[i] == "P")
        {
            for (int nchanges = 0; nchanges <= k; nchanges++)
                dp[i][nchanges][2] = 1 + max(dp[i - 1][nchanges][2], max(dp[i - 1][nchanges - 1][0], dp[i - 1][nchanges - 1][1]));
        }
        else if (john[i] == "H")
        {
            for (int nchanges = 0; nchanges <= k; nchanges++)
                dp[i][nchanges][1] = 1 + max(dp[i - 1][nchanges][1], max(dp[i - 1][nchanges - 1][0], dp[i - 1][nchanges - 1][2]));
        }
        else if (john[i] == "S")
        {
            for (int nchanges = 0; nchanges <= k; nchanges++)
                dp[i][nchanges][0] = 1 + max(dp[i - 1][nchanges][0], max(dp[i - 1][nchanges - 1][2], dp[i - 1][nchanges - 1][1]));
        }
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b <= k; b++)
        {
            cout << dp[a][b][0] << " " << dp[a][b][1] << " " << dp[a][b][2] << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans = max(ans, max(max(dp[n - 1][i][0], dp[n - 1][i][1]), dp[n - 1][i][2]));
    }
    // cout<<max(2,3,4,55)<<endl;
    cout << ans << endl;

} ////////////////////////////

int main()
{
    startTime = (double)clock();
    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    // int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
