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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        ll ans = 0;

        if (n % 2 == 0)
        {
                for (ll i = 0; i <= n - 2; i += 2)
                {
                        if (v[i] > v[i + 1])
                        {
                                // flag = -1;
                                cout << -1 << endl;
                                return;
                        }
                        else if (v[i] < v[i + 1])
                        {
                                ll diff = v[i + 1] - v[i];
                                if (i + 2 < n)
                                {
                                        ans += 2 * diff;
                                        v[i + 1] -= diff;
                                        v[i + 2] -= diff;
                                        if (v[i + 2] < 0)
                                        {
                                                cout << -1 << endl;
                                                return;
                                        }
                                }
                                else
                                {
                                        cout << -1 << endl;
                                        return;
                                }
                        }
                }
                ll mn = 1e9;
                for (ll i = 0; i < n; i++)
                        mn = min(v[i], mn);
                for (ll i = 0; i < n; i++)
                {
                        ans += v[i] - mn;
                }
        }
        else
        {
                for (ll i = 0; i <= n - 3; i += 2)
                {
                        if (v[i] > v[i + 1])
                        {
                                cout << -1 << endl;
                                return;
                        }
                        else if (v[i] < v[i + 1])
                        {
                                ll diff = v[i + 1] - v[i];
                                ans += 2 * diff;
                                v[i + 1] -= diff;
                                v[i + 2] -= diff;
                                if (v[i + 2] < 0)
                                {
                                        cout << -1 << endl;
                                        return;
                                }
                        }
                }
                ll mn = 1e9;
                for (ll i = 0; i < n; i++)
                        mn = min(v[i], mn);
                if (v[n - 1] > mn)
                {
                        cout << -1 << endl;
                        return;
                }
                else
                {
                        for (ll i = 0; i < n; i++)
                        {
                                ans += v[i] - mn;
                        }
                }
        }

        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
