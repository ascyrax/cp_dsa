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

        // freopen("shell.in", "r", stdin);
        // freopen("shell.out", "w", stdout);

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
ll mod = 1e9 + 7;
ll ans = 1;
//...............................

//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n);
        ll neg = 0;
        for (ll &el : v)
        {
                cin >> el;
                if (el < 0)
                        neg++;
        }

        if (k == n)
        {
                for (ll i = 0; i < n; i++)
                {
                        ans = ((ans % mod) * (v[i] % mod)) % mod;
                        if (ans < 0)
                        {
                                ans = (ans + 1000000007) % mod;
                        }
                }
                cout << ans << endl;
                return;
        }
        else if (k < n && neg == n && k % 2 == 1)
        {
                sort(v.rbegin(), v.rend());
                for (ll i = 0; i < k; i++)
                {
                        ans = ((ans % mod) * (v[i] % mod)) % mod;
                }
                if (ans < 0)
                {
                        ans = (ans + 1000000007) % mod;
                }
                cout << ans << endl;
                return;
        }

        sort(v.begin(), v.end());

        ll a = 0, b = 1, c = n - 2, d = n - 1;
        while (k > 0)
        {
                // cout << a << " " << b << " " << c << " " << d << endl;

                ll prod1 = abs(v[a] * v[b]);
                ll prod2 = abs(v[c] * v[d]);
                if (k == 1)
                {
                        // cout << a << " " << b << " " << c << " " << d << endl;
                        ans = ((ans % mod) * (v[d] % mod)) % mod;
                        k--;
                }
                else if (prod1 >= prod2)
                {
                        ans = ((ans % mod) * (prod1 % mod)) % mod;
                        a += 2;
                        b += 2;
                        k -= 2;
                }
                else
                {
                        ans = ((ans % mod) * (v[d] % mod)) % mod;
                        c -= 1;
                        d -= 1;
                        k--;
                }
                if (ans < 0)
                {
                        ans = (ans + 1000000007) % mod;
                }
        }

        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
