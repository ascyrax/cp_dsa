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

const ll mod = 1e9 + 7;
int dp[1001][1001];
//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<string> v(n);
        for (string &s : v)
                cin >> s;
        dp[1][1] = 1;

        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        if (v[i - 1][j - 1] == '*')
                        {
                                // cout << "if" << endl;
                                dp[i][j] = 0;
                        }
                        else if (v[i - 1][j - 1] == '.')
                        {
                                // cout << "else" << endl;
                                (dp[i][j] += dp[i][j - 1] + dp[i - 1][j]) %= mod;
                        }
                }
        }

        cout << dp[n][n] << endl;
}

//................................
