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

        ll ans = 0;

        // ll k;

        // for (long long i = 1; i <= n; i++)
        // {
        //         if (i * i <= n)
        //                 k = i;
        //         else
        //                 break;
        // }
        auto k = sqrt(n);
        ll b = sqrt(n);
        cout << "b+1 = " << b + 1 << endl;
        cout << "n/(b+1) = " << n / (b + 1) << endl;
        cout << "k + 1 = " << k + 1 << endl;
        cout << "n/(k+1) = " << n / (k + 1) << endl;
        /////////////////////////////////////////////////////
        for (ll i = 1; i <= n / (k + 1); i++)
        {
                cout << "i = " << i << endl;
                ans += (n / i);
        }
        // cout << "ans = " << ans << endl;
        for (ll quo = 1; quo <= k; quo++)
        {
                cout << "quo = " << quo << endl;
                ll left = n / (quo + 1) + 1;
                ll right = n / quo;
                ll range = right - left + 1;
                ans += (quo * range);
        }
        //////////////////////////////////////
        for (ll i = 1; i <= n / (b + 1); i++)
        {
                cout << "i = " << i << endl;
                ans += (n / i);
        }
        // cout << "ans = " << ans << endl;
        for (ll quo = 1; quo <= b; quo++)
        {
                cout << "quo = " << quo << endl;
                ll left = n / (quo + 1) + 1;
                ll right = n / quo;
                ll range = right - left + 1;
                ans += (quo * range);
        }

        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
