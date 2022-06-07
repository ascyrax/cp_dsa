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
        // ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;
bool dp[101][100001];
//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        //dp[i]=nsums   on dealing with i nos from the left inside the array
        //              we found nsums distinct sums

        //or
        //dp[i][j]= wrt first i nos from the left is the sum=j possible

        for (int i = 1; i <= n; i++)
        {
                // cout << i << " ";
                dp[i][v[i - 1]] = true;
                for (int j = 1; j <= n * 1000; j++)
                {
                        if (dp[i - 1][j] == true)
                        {

                                dp[i][j] = true;
                        }
                        else if ((j >= v[i - 1]) && (dp[i - 1][j - v[i - 1]] == true))
                        {

                                dp[i][j] = true;
                        }
                }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //         for (int j = 1; j <= 13; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        int ans = 0;
        vector<int> vans;
        for (int i = 1; i <= n * 1000; i++)
        {
                if (dp[n][i] == true)
                {
                        ans++;
                        vans.pb(i);
                }
        }
        cout << ans << endl;
        for (int i : vans)
                cout << i << " ";
        cout << endl;
}
//................................
