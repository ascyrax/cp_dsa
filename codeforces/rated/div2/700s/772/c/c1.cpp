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

        if (v[n - 2] > v[n - 1])
        {
                cout << -1 << endl;
                return;
        }

        ll cnt = 0;
        vector<vector<ll>> ans;

        if (v[n - 3] > v[n - 2])
        {
                v[n - 3] = v[n - 2] - v[n - 1];
                if (v[n - 3] > v[n - 2])
                {
                        cout << -1 << endl;
                        return;
                }
                cnt++;
                vector<ll> temp;
                temp.pb(n - 3);
                temp.pb(n - 2);
                temp.pb(n - 1);
                // ans.pb({n - 3, n - 2, n - 1});
                ans.pb(temp);
        }

        ll pos = n; // leftmost positive value in the array.

        if (v[n - 1] >= 0)
                pos = n - 1;
        // if (v[n - 2] > 0)
        //         pos = n - 2;
        // if (v[n - 3] > 0)
        //         pos = n - 3;

        for (ll i = n - 4; i >= 0; i--)
        {
                if (v[i] > v[i + 1])
                {
                        if (pos == n)
                        {
                                cout << -1 << endl;
                                return;
                        }
                        // if (pos != i + 1)
                        // {
                        v[i] = v[i + 1] - v[pos];
                        // ans.pb({i, i + 1, pos});
                        vector<ll> temp;
                        temp.pb(i);
                        temp.pb(i + 1);
                        temp.pb(pos);
                        ans.pb(temp);
                        // }
                        // else
                        // {
                        //         v[i] = v[i + 1] - v[pos + 1];
                        //         // ans.pb({i, i + 1, pos + 1});
                        //         vector<ll> temp;
                        //         temp.pb(i);
                        //         temp.pb(i + 1);
                        //         temp.pb(pos + 1);
                        //         ans.pb(temp);
                        // }
                        cnt++;
                }

                // if (v[i] > 0)
                //         pos = i;
        }

        cout << cnt << endl;
        for (auto vec : ans)
        {
                for (auto el : vec)
                        cout << el + 1 << " ";
                cout << endl;
        }

        // for (int i : v)
        //         cout << i << " ";
        // cout << endl;
}

//................................

// ll

// ll

// int

// int
