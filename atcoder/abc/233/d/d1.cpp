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

//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &i : a)
                cin >> i;
        ll ps = 0;
        map<ll, vector<ll>> m;
        for (ll i = 0; i < n; i++)
        {
                ps += a[i];
                m[ps].pb(i);
        }
        for (auto el : m)
        {
                sort(el.second.begin(), el.second.end());
        }
        ps = 0;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
                ps += a[i];
                ll find = 0;
                if (ps == k)
                {
                        find = 0;
                        for (auto el : m[0])
                        {
                                // m[find] is a sorted vector
                                if (el > i)
                                        break;
                                else
                                {
                                        ans++;
                                }
                        }
                        ans++; // this + by 1 becz -> if we dont remove any prefix subarray then the ps is already equal to k
                }
                else
                {
                        find = ps - k;
                        for (auto el : m[find])
                        { // m[find] is a sorted vector
                                if (el > i)
                                        break;
                                else
                                {
                                        ans++;
                                }
                        }
                };
        }
        cout << ans << endl;
}

//................................
// ll
// ll
// ll
// int
