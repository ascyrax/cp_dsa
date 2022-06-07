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
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................
bool isPrime(ll n)
{
        if (n == 1 || n == 2 || n == 3)
                return true;
        for (ll i = 2; i * i <= n; i++)
        {
                if (n % i == 0)
                        return false;
        }
        return true;
}
//...............................

void suraj()
{
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        // vector<ll> ps;
        // ps.pb(0);
        // for (ll i : v)
        //         ps.pb(i + ps.back());
        // cout << "ps" << endl;
        // for (ll i : ps)
        //         cout << i << " ";
        // cout << endl;
        ll ansSize = 0;
        ll ansL = 0, ansR = 0;
        vector<ll> ans;
        // ll flag = -1;
        for (ll len = n; len >= 1; len--)
        {
                // find the subset of size i
                for (ll j = 0; j + len - 1 < n; j++)
                {
                        // ll sum = ps[min(n, j + len - 1)] - ps[j - 1];
                        ll sum = 0;
                        for (ll k = j; k <= j + len - 1; k++)
                        {
                                sum += v[k];
                        }
                        // cout << "len = " << len << " j = " << j << "sum = " << sum << endl;
                        if (!isPrime(sum))
                        {
                                if (len >= ansSize)
                                {
                                        ansSize = len;
                                        ansL = j;
                                        ansR = j + len - 1;
                                        // flag = 1;
                                        // break;
                                }
                        }
                }
                // if (flag == 1)
                //         break;
        }
        // if (flag == -1)
        // {
        //         cout << 0 << endl;
        //         return;
        // }
        cout << ansSize << endl;
        for (ll i = ansL; i <= ansR; i++)
                cout << i + 1 << " ";
        cout << endl;
        // cout << "--------------------------------" << endl;
}

//................................
