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
ll a, b, n, x;
ll result = 1;
//...............................
// ll power(ll a, ll b)
// {
//         ll result = 1;
//         while (b > 0)
//         {
//                 if (b % 2 == 1)
//                 {
//                         result *= a;
//                         result %= MOD;
//                 }
//                 a = (a * a) % MOD;
//                 b /= 2;
//         }
//         return result;
// }
ll f(ll n)
{
        if (n == 0)
                return 1;
        else if (n == 1)
                return ((a * x + b) % MOD);
        else
        {
                ll rec = f(n / 2) % MOD;
                rec = (rec * rec) % MOD;
                if (n % 2 == 1)
                        rec *= (f(1ll));
                return (rec % MOD);
        }
}
//...............................

void suraj()
{

        cin >> a >> b >> n >> x;
        // cout << f(n) << endl;
        ll result = 1ll;

        ll fval = a * x + b;
        fval %= MOD;
        while (n > 0)
        {
                if (n % 2 == 1)
                {
                        result = (result * fval) % MOD;
                        cout << "result = " << result << endl;
                }
                fval = ((a * fval) % MOD + b) % MOD;
                cout << "fval = " << fval << endl;
                // fval %= MOD;
                n /= 2;
        }
        cout << result << endl;
}

//................................
