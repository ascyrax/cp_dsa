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
const int INF = int(1e11);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................
ll power(ll a, ll b)
{
        ll result = 1;
        for (int i = 1; i <= b; i++)
        {
                result *= a;
        }
        return result;
}
//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &i : a)
                cin >> i;
        vector<ll> cnt(n, 1e11);
        for (int i = 0; i < n - 1; i++)
        {
                ll diff = pow(10, a[i + 1]) - pow(10, a[i]);
                // cout << "diff = " << diff << endl;
                cnt[i] = diff / ll(pow(10, a[i]));
        }
        // cout << "cnt" << endl;
        // for (ll i : cnt)
        //         cout << i << " ";
        // cout << endl;
        vector<ll> ps(n, 0);
        ps[0] = cnt[0];
        for (int i = 1; i < n; i++)
        {
                ps[i] = ps[i - 1] + cnt[i];
        }
        // cout << "ps" << endl;
        // for (ll i : ps)
        //         cout << i << " ";
        // cout << endl;
        k++;
        auto it = lower_bound(ps.begin(), ps.end(), k);
        auto itr = lower_bound(ps.begin(), ps.end(), k) - ps.begin();

        // cout << "itr = " << itr << endl;
        ll ans = 0;
        // // if (itr == n - 1)
        // // {
        // // }
        // // else
        // // {
        for (int i = 0; i <= itr - 1; i++)
        {
                // cout << "ans before = " << ans << endl;
                // cout << "cnt[i] = " << cnt[i] << endl;
                // cout << "i = " << i << endl;
                // cout << "pow(10,a[i]) = " << power(10, a[i]) << endl;
                // cout << "cnt[i]*pow(10,a[i]) = " << cnt[i] * power(10, a[i]) << endl;
                ans += (cnt[i] * power(10, a[i]));
                k -= cnt[i];
                // cout << "ans = " << ans << " k = " << k << endl;
        }
        // cout << "ans a= " << ans << endl;
        // cout << "k = " << k << endl;
        ans += k * ll(power(10, a[itr]));
        cout << ans << endl;
        // }
}

//................................
