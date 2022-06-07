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
        // ioss
        startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
ll consSum(ll n)
{
        // cout << (n * (n + 1) / 2) << endl;
        return (n * (n + 1)) / 2;
}
//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &i : a)
                cin >> i;
        sort(a.rbegin(), a.rend());
        ll l = 0, r = 2e9;
        while (l < r)
        {
                ll m = l + (r - l) / 2;
                ll sum = 0;
                for (ll i = 0; i < n; i++)
                {
                        if (a[i] - m > 0)
                                sum += (a[i] - m);
                }
                // cout << "sum = " << sum << endl;

                if (sum > k)
                {
                        // if r=l+1 then this case can lead to an infinite loop
                        if (r == l + 1)
                                break;
                        l = m;
                }
                else if (sum < k)
                        r = m;
                else if (sum == k)
                {
                        l = m;
                        r = m;
                        break;
                }
        }
        // cout << "l = " << l << ", r = " << r << endl;
        ll ans = 0;
        //  r=l+1
        // go with l only.. but i will have to remove 1 extra case
        // i.e. i gotta remove (l+1) from the sum

        // r=l
        for (ll i = 0; i < n; i++)
        {
                if (a[i] > l)
                {
                        ans += (consSum(a[i]) - consSum(l));
                }
        }
        if (l + 1 == r)
                ans -= (l + 1);
        cout << ans << endl;
}

//................................
