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

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        // cin>>t;

        for (int i = 1; i <= t; i++)
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
        ll n, l, w;
        cin >> n >> l >> w;

        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        ll last = 0;
        ll ans = 0; // no of tarps needed.
        for (ll tno = 0; tno < n; tno++)
        {
                ll dist = v[tno] - last;
                ll q = dist / w;
                ll r = dist % w;
                ans += q;
                last += w * q;
                if (r > 0)
                {
                        last = v[tno] + w;
                        ans++;
                }
                else
                        last = v[tno] + w;
        }
        if (last < l)
        {
                ll dist = l - last;
                ll q = dist / w;
                ll r = dist % w;
                ans += q;
                last += w * q;
                if (r > 0)
                        ans++;
        }

        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
