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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        vector<ll> diff;
        for (ll i = 1; i < n; i++)
                diff.pb(v[i] - v[i - 1]);
        sort(diff.rbegin(), diff.rend());
        // k subarrays means (k-1) walls.
        // assuming that out of all these differences, I will build wall
        // at top k-1 differences. So, i wont have to count these diff in the sum.
        ll sum = 0;

        for (ll i = k - 1; i < diff.size(); i++)
                sum += diff[i];

        cout << sum << endl;
}

//................................
// ll
// int
// int
// int
