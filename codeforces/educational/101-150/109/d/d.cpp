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
        // ioss
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll mod = 1e9 + 7;
const int inf = int(1e9);
const int ninf = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n;
vector<int> a, one, zero;
int ans = 0;
//...............................

//...............................

void suraj()
{
        cin >> n;
        a = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }
        vector<int> pos;
        for (int i = 0; i < n; i++)
        {
                if (a[i] == 1)
                        pos.pb(i);
        }
        int k = pos.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));

        //dp[i][j] =minimum time taken if from the first  i+1 i.e. ranging till the index of i chairs, we choose any j chairs as the optimal final chairs for people

        //assuming initially people are sitting on x1,x2,x3..xk. and finally on y1,y2,y3....yk optimally

        for (int i = 0; i < n; i++)
        { //for all chairs present

                for (int j = 0; j <= min(i, k); j++)
                {
                        if (j == 0)
                        {
                                dp[i][j] = 0;
                                continue;
                        }
                        if (a[i] == 0)
                        {
                                //jth starting chair is
                                int jth = pos[j - 1];
                                //if the current chair is chosen as one end pt
                                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(jth - i));
                                //else
                                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                        }
                        else
                        {
                                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                        }
                }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //         for (int j = 0; j <= k; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        cout << dp[n - 1][k] << endl;
}

//................................
