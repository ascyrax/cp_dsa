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

        freopen("citystate.in", "r", stdin);
        freopen("citystate.out", "w", stdout);

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

        map<string, ll> m;

        vector<pair<string, string>> ab;

        for (ll i = 0; i < n; i++)
        {
                string a, b;
                cin >> a >> b;
                ab.pb(make_pair(a, b));
                m[a.substr(0, 2) + b]++;
        }
        ll ans = 0;
        // for (auto el : m)
        //         cout << el.first << " " << el.second << endl;
        for (ll i = 0; i < n; i++)
        {
                string a = ab[i].first;
                string b = ab[i].second;

                // if both cities belong to the same state
                if (b == a.substr(0, 2))
                        continue;

                string find = b + a.substr(0, 2);
                ll c = 0;
                if (m.count(find) > 0)
                        c = m[find];
                ans += c;
        }
        cout << ans / 2 << endl;
}

//................................

// ll

// int

// int

// int
