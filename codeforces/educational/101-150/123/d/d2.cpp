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

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
ll mod = 998244353;
//...............................

void suraj()
{
        ll n, m, k, q;
        cin >> n >> m >> k >> q;

        vector<pair<ll, ll>> queries;

        for (ll i = 0; i < q; i++)
        {
                ll x, y;
                cin >> x >> y;
                queries.pb(make_pair(x, y));
        }

        set<ll> r, c;

        ll cnt = 0;

        for (ll i = q - 1; i >= 0; i--)
        {
                bool rno = false, cno = false;
                if (r.size() == n || c.size() == m)
                {
                        rno = true; // => row will get colored by some other color later.
                        cno = true;
                }
                if (r.count(queries[i].first))
                        rno = true;
                if (c.count(queries[i].second))
                        cno = true;

                if (rno && cno)
                        continue;

                cnt++;

                if (rno == false)
                        r.insert(queries[i].first);
                if (cno == false)
                        c.insert(queries[i].second);
        }

        ll ans = 1;
        for (ll i = 0; i < cnt; i++)
        {
                ans *= k;
                ans %= mod;
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
