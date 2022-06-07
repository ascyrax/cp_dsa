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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        vector<ll> xorby;
        xorby.pb(0);
        for (ll i : v)
                xorby.pb(i);

        vector<ll> bits(60);
        for (ll i : v)
        {
                ll bitno = 0;
                while (i)
                {
                        if (i & 1)
                        {
                                bits[bitno]++;
                        }
                        i /= 2;
                        bitno++;
                }
        }

        // for (int i = 0; i < 10; i++)
        // {
        //         cout << bits[i] << " ";
        // }
        // cout << endl;

        ll ans = 0;
        for (auto el : xorby)
        {
                vector<ll> temp(60);
                ll bitno = 0;

                // cout << "el : " << el << endl;
                while (el)
                {
                        if (el & 1)
                        {
                                temp[bitno] = 1;
                        }
                        else
                        {
                                temp[bitno] = 0;
                        }
                        el /= 2;
                        bitno++;
                }

                // for (int i = 0; i < 10; i++)
                //         cout << temp[i] << " ";
                // cout << endl;

                ll sum = 0;
                for (ll i = 0; i < 60; i++)
                {
                        if (temp[i] == 1)
                        {
                                sum += (pow(2, i) * (n - bits[i]));
                        }
                        else
                        {
                                sum += (pow(2, i) * bits[i]);
                        }
                }
                // cout << "sum : " << sum << endl;
                ans = max(ans, sum);
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// ll

// ll
