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
        // two elements cannot be equal
        // min possible x = n+1
        //
        ll n;
        cin >> n;

        vector<ll> v(n);
        ll sum_total = 0;
        for (ll &i : v)
        {
                cin >> i;
                sum_total += i;
        }

        ll sum1 = n * (n + 1) / 2;

        ll sum2 = sum_total - sum1;
        if (sum2 < 0)
        {
                cout << "NO" << endl;
                return;
        }
        if (sum2 == 0)
        {
                cout << "YES " << n + 1 << endl;
                return;
        }

        // sum2%x==0
        map<ll, ll> fac;
        vector<ll> x;
        for (ll i = 1; i * i <= sum2; i++)
        {
                if (sum2 % i == 0)
                {
                        if (fac.count(sum2 / i) == 0)
                        {
                                x.pb(sum2 / i);
                                fac[sum2 / i]++;
                        }
                        if (fac.count(sum2 / (sum2 / i)) == 0)
                        {
                                x.pb(sum2 / (sum2 / i));
                                fac[sum2 / (sum2 / i)]++;
                        }
                }
        }

        for (ll el : x)
        {
                // vector<ll> v = v;
                ll flag = 1;
                map<ll, ll> m;
                ll val = 0;
                for (ll i = 0; i < n; i++)
                {
                        val = v[i] % el;
                        if (val > n || val == 0 || (m.count(val) > 0))
                        {
                                flag = -1;
                                break;
                        }
                        else if (m.count(val) == 0)
                        {
                                m[val]++;
                        }
                }
                if (flag == 1)
                {
                        cout << "YES " << el << endl;
                        return;
                }
        }
        cout << "NO" << endl;
}

//................................

// ll

// ll

// int

// int
