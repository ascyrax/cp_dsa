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
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        ll plate = 0;

        map<ll, ll> m;
        ll itr = 0;
        ll len = 0; // lenth of the repeating variables.
        ll rem = 0;
        // ll sumb = 0; // sum of left + sum of one loop
        while (1)
        {
                itr++;
                // cout << "itr = " << itr << endl;
                // cout << "plate = " << plate << endl;

                if (itr > k)
                        break;
                rem = plate % n;
                plate += v[rem];
                if (m.count(rem) > 0)
                {
                        len = itr - m[rem];
                        break;
                }
                else
                {
                        m[rem] = itr;
                }
        }

        ll sumLeft = 0;
        for (ll i = 0; i < m[rem]; i++)
        {
                ll rem = sumLeft % n;
                sumLeft += v[rem];
        }

        ll sumLen = plate - sumLeft;
        k -= m[rem];
        ll quo;
        if (len == 0)
                quo = 0;
        else
                quo = k / len;
        ll ans = 0;
        ans += sumLeft;
        ans += sumLen * quo;

        ll r;
        if (len == 0)
                r = 0;
        else
                r = k % len;
        // ll sumr = 0;

        for (ll i = 0; i < r; i++)
        {
                rem = ans % n;
                ans += v[rem];
        }
        // ans += sumr;
        cout << ans << endl;
        // cout << 5 % 0 << endl;
}

//................................

// ll

// ll

// int

// int
