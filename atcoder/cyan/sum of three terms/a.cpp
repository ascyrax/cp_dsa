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

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;

        vector<ll> s(n);
        for (ll &i : s)
                cin >> i;

        // 1st = a[0] = x
        // 2nd = a[1] = y
        // 3rd = a[2] = s[0]-x-y
        // 4th = a[3] = s[1]-a[2]-a[1] = s[1]-s[0]+x+y-y = s[1]-s[0]+x
        // a[4] = s[2] - s[1] +s[0] - x - s[0] + x + y = s[2] - s[1] + y

        // kth = a[k] = s[k-2]-a[k-1]-a[k-2] except a[1] and a[2]

        // a[k] >=0

        // most imp concept
        // if we put x=0 and y=0 then in every step we will get the constant other than the x and y.
        // since xs and ys will be replaced by 0s and we will get the remaining constant values.

        vector<ll> a = {0, 0};
        ll l = 0, r = 1;

        ll c1 = -1e9, c2 = -1e9, c3 = 1e9;
        // x >= c1
        // y >= c2
        // x+y >= c3

        for (ll i = 0; i < n; i++)
        {
                ll temp = s[i] - a[l] - a[r];
                // cout << "temp : " << temp << endl;
                a.pb(temp);
                l++;
                r++;

                // temp >= 0
                if (i % 3 == 1) // a[i]+a[i+1]+a[i+2] = s[i] => a[i] = s[i] - a[i] - a[i+1] => a[i] = const + x => this const + x>= 0 => x>= -const;
                {               // here const = temp
                        c1 = max(c1, -1 * temp);
                }
                else if (i % 3 == 2) //
                {                    // for these cases a[i] = temp + y => temp + y >=0 => y>=-temp;
                        c2 = max(c2, -1 * temp);
                }
                else if (i % 3 == 0)
                { // for these cases a[i] = temp - x - y => temp -x - y >=0 since ai >=0 (given in the constralls);
                        // => x+y<=temp
                        c3 = min(c3, temp);
                }
                // cout << c1 << " " << c2 << " " << c3 << endl;
        }

        // now we know,
        // x >= c1
        // y >= c2
        // x+y<=c3
        // cout << c1 << " " << c2 << " " << c3 << endl;
        ll x, y;

        if (c3 < 0 || (max(0ll, c1) + max(0ll, c2) > c3))
        {
                cout << "No" << endl;
                return;
        }

        cout << "Yes" << endl;

        x = max(c1, 0ll);
        y = max(c2, 0ll);

        vector<ll> ans = {x, y};
        l = 0ll, r = 1;
        for (ll i = 0ll; i < n; i++)
        {
                ll temp = s[i] - ans[l] - ans[r];
                ans.pb(temp);
                l++;
                r++;
        }
        // cout << ans.size() << endl;
        for (auto el : ans)
                cout << el << " ";
        cout << endl;
}

//................................

// ll

// ll

// int

// int
