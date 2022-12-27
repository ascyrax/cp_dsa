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
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
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
int n;
vector<int> a, b, c;
int dp[(int)1e5][3];
//...............................

//...............................

void suraj()
{
        cin >> n;
        a = vector<int>(n);
        b = vector<int>(n);
        c = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
                cin >> a[i] >> b[i] >> c[i];
        }
        for (int i = 0; i < n; i++) //days
        {
                if (i == 0)
                {
                        dp[0][0] = a[0];
                        dp[0][1] = b[0];
                        dp[0][2] = c[0];
                }
                if (i - 1 >= 0)
                {
                        dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i]);
                        dp[i][0] = max(dp[i][0], dp[i - 1][2] + a[i]);
                        dp[i][1] = max(dp[i][1], dp[i - 1][0] + b[i]);
                        dp[i][1] = max(dp[i][1], dp[i - 1][2] + b[i]);
                        dp[i][2] = max(dp[i][2], dp[i - 1][0] + c[i]);
                        dp[i][2] = max(dp[i][2], dp[i - 1][1] + c[i]);
                }
        }

        cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

//................................
