#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;
int dp[1001][int(1e5) + 1];
//...............................

void suraj()
{
        int n, x;
        cin >> n >> x;
        //dp[i][0]=sum of pages if ith book is not taken
        //and dp[i][1]=sum of pages if ith book is taken
        vector<int> vprice(n + 1);
        for (int i = 1; i <= n; i++)
                cin >> vprice[i];
        vector<int> vpage(n + 1);
        for (int i = 1; i <= n; i++)
                cin >> vpage[i];
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // for (int i = 1; i < n; i++)
        // {
        //         dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        //         dp[i][1]=vprice[i]+
        // }
        //dp[i][x]= max no of pages if books of price <=x are chosen among the first i books
        //ans=dp[n][x];
        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= x; j++)
                {
                        if (j >= vprice[i])
                        {
                                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                                dp[i][j] = max(dp[i][j], dp[i - 1][j - vprice[i]] + vpage[i]);
                        }
                        cout << dp[i][j] << " ";
                }
                cout << endl;
        }
        cout << dp[n][x] << endl;
}

//................................

//4 10
// 4 8 5 3
// 5 12 8 1