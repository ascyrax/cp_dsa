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

        freopen("pairup.in", "r", stdin);
        freopen("pairup.out", "w", stdout);

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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> yx;
        for (ll i = 0; i < n; i++)
        {
                ll x, y;
                cin >> x >> y;

                yx.pb(make_pair(y, x));
        }

        sort(yx.begin(), yx.end());

        ll l = 0, r = n - 1;
        ll ans = 0;
        while (l < r)
        {
                ll &cntl = yx[l].second;
                ll &cntr = yx[r].second;

                ll mn = min(cntl, cntr);

                cntl -= mn;
                cntr -= mn;

                ans = max(ans, yx[l].first + yx[r].first);

                if (cntl == 0)
                        l++;
                if (cntr == 0)
                        r--;
        }

        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
