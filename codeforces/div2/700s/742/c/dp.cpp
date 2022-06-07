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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
        string s;
        cin >> s;
        int n = (int)s.size();
        //let n= no of digits in s
        int dp[10][2][2]; //10 becz max value of n can be 1e9 which is having 10digits in total
        //dp[i][j][k]=total no of pairs(a,b) , a,b are Integers , such that
        //no formed by the digits of s ranging from i to n-1 is the sum of a and b.
        //where j is the carry-over from one position to the right and k is the carry-over from
        //the ith position

        for (int i = n - 1; i >= 0; i--)
        {
                for (int j = 0; j <= 1; j++)
                {
                        for (int k = 0; k <= 1; k++)
                        {
                                dp[i][j][k] += dp[i + 1][][j];
                        }
                }
        }

        cout << dp[0][0][0] - 2 << endl;
        //there will be two cases (0,b) and (a,0) which are invalid therefore -2
}

//................................
