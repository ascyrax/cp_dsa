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

//...............................
ll power(ll a, ll b)
{
        ll result = 1;
        while (b)
        {
                if (b & 1)
                {
                        result *= a;
                        result %= MOD;
                }
                a *= a;
                a %= MOD;
                b /= 2;
                // cout << "result = " << result << " a = " << a << " b = " << b << endl;
        }
        return result;
}
//...............................

void suraj()
{
        ll k;
        cin >> k;
        ll ans = 6;
        if (k == 1)
                cout << ans << endl;
        else
        {
                for (int i = 2; i <= k; i++)
                {
                        ll ni = pow(2, i - 1);
                        // cout << "ni = " << ni << endl;
                        // cout << "power(4,ni) = " << power(4, ni) << endl;
                        ans = ans * power(4, ni);
                        // cout << "ans = " << ans << endl;
                        ans %= MOD;
                        // cout << "ans after mod = " << ans << endl;
                }
                cout << ans << endl;
        }
}

//................................
