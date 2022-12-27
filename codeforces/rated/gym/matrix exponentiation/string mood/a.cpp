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
        //cout << setprecision(15) << fixed;
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
ll power(ll a, ll b)
{
        ll result = 1;
        while (b > 0)
        {
                if (b & 1)
                {
                        result *= a;
                        result %= MOD;
                }
                a *= a;
                a %= MOD;
                b /= 2;
        }
        return result;
}
//...............................

void suraj()
{
        ll n;
        cin >> n;

        // p[1]=19 => mood does not change
        // p[2]=p[1]*p[1] + (26-p[1])*(26-p[1])

        // initially the person is happy therefore
        // ll p = 19;
        // ll happy_string_cnt = 1;
        // ll x = 1;
        // while (n > 0)
        // {
        //         if (n & 1)
        //         {
        //                 happy_string_cnt = happy_string_cnt * p;
        //                 happy_string_cnt %= MOD;
        //         }
        //         // p = p * p + (26 - p) * (26 - p);
        //         p = p * p + (power(26, x) - p) * (power(26, x) - p - 1);
        //         p %= MOD;
        //         x++;
        //         n /= 2;
        // }
        // cout << happy_string_cnt % MOD << endl;

        // 0 stands for happy
        // 1=> sad
        vector<vector<ll>> p(2, vector<ll>(2, 1)), q(2, vector<ll>(2, 0));
        p[0][0] = 19;
        p[0][1] = 7;
        p[1][0] = 6;
        p[1][1] = 20;
        ll result = 1;
        while (n > 0)
        {
                if (n % 2 == 1)
                {
                        result *= p[0][0];
                        result %= MOD;
                }
                for (ll i = 0; i <= 1; i++)
                {
                        for (ll j = 0; j <= 1; j++)
                        {
                                for (ll k = 0; k <= 1; k++)
                                {
                                        q[i][j] += (p[i][k] * p[k][j]);
                                        q[i][j] %= MOD;
                                }
                                cout << "q[0][0] = " << q[0][0] << endl;
                        }
                }
                p[0][0] = q[0][0];
                p[0][1] = q[0][1];
                p[1][0] = q[1][0];
                p[1][1] = q[1][1];
                q[0][0] = 0;
                q[0][1] = 0;
                q[1][0] = 0;
                q[1][1] = 0;
                for (int i = 0; i <= 1; i++)
                {
                        for (int j = 0; j <= 1; j++)
                        {
                                cout << p[i][j] << " ";
                        }
                        cout << endl;
                }
                n /= 2;
        }
        cout << result << endl;
}

//................................
