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

//...............................

void suraj()
{
        ll n, x;
        cin >> n >> x;

        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        sort(v.begin(), v.end());

        map<ll, vector<ll>> m;
        vector<bool> flag(n, false);
        map<ll, ll> need, waiting;

        for (ll i = 0; i < n; i++)
        {
                if (need[v[i]] > 0)
                {
                        need[v[i]]--;
                        waiting[v[i] / x]--;
                }
                else
                {
                        waiting[v[i]]++;
                        need[v[i] * x]++;
                }
        }
        ll ans = 0;
        for (auto el : waiting)
        {
                if (el.second > 0)
                        ans += el.second;
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
