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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //ioss
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................
int n, x;
vector<int> vprice, vpages;
int dp[1001][(int)1e5 + 1]; //dp[i][x]=max no pages within total price x ,
//if books from the first i books are only taken
//...............................

//...............................

void suraj()
{
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
                int a;
                cin >> a;
                vprice.pb(a);
        }
        for (int i = 0; i < n; i++)
        {
                int a;
                cin >> a;
                vpages.pb(a);
        }
        //dp[i][x] =max(dp[i][x],max(dp[i-1][x],pages[ith book] + dp[i-1][x-vprice[ith book]]));
        for (int i = 1; i <= n; i++)
        {
                for (int price = 1; price <= x; price++)
                {
                        dp[i][price] = dp[i - 1][price]; // if the ith book was not bought then we can simply replace dp[i][price](since its current value is 0 anyways)

                        //below is corresponding to the case if the ith book was bought => it gave vpages[ith book]  and cost vprice[ith book]
                        if (price - vprice[i - 1] >= 0)
                                dp[i][price] = max(dp[i][price], vpages[i - 1] + dp[i - 1][price - vprice[i - 1]]);
                }
        }

        cout << dp[n][x] << endl;
}

//................................
