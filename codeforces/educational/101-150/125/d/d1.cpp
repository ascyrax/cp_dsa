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
        ll n, C;
        cin >> n >> C;

        vector<ll> best(C + 1, 0);

        for (ll i = 0; i < n; i++)
        {
                ll c, d, h;
                cin >> c >> d >> h;
                // for cost c, the max d*h value is best[c].
                best[c] = max(best[c], d * h);
        }
        for (int c = 1; c <= C; c++)
                for (ll temp = c; temp <= C; temp += c)
                {
                        best[temp] = max(best[temp], best[c] * temp / c);
                }

        for (ll i = 1; i <= C; i++)
                best[i] = max(best[i], best[i - 1]);

        ll m;
        cin >> m;
        vector<ll> ans;
        for (ll i = 0; i < m; i++)
        {
                ll d, h;
                cin >> d >> h;
                ll prod = d * h;
                ll val = upper_bound(best.begin(), best.end(), d * h) - best.begin();
                if (val > C)
                        ans.pb(-1);
                else
                        ans.pb(val);
        }
        for (auto el : ans)
                cout << el << " ";
        cout << endl;
}

//................................

// ll

// ll

// int

// int
