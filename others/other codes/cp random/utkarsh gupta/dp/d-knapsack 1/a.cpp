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
///////////////// SLOW RECURSIVE SOLUTION.
ll n, w;
vector<ll> weights, values;
ll dp[101][100001];
//...............................
ll solve(ll index, ll wLeft)
{
        // cout << "index: " << index << " , wLeft " << wLeft << endl;
        if (index == 0)
        {
                // cout << "index = 0" << endl;
                if (weights[0] <= wLeft)
                        return values[0];
                else
                        return 0;
        }
        if (wLeft - weights[index] >= 0)
        {
                // cout << "if" << endl;
                return max(solve(index - 1, wLeft), values[index] + solve(index - 1, wLeft - weights[index]));
        }
        else
        {
                // cout << "else" << endl;
                return solve(index - 1, wLeft);
        }
}
//...............................

void suraj()
{
        cin >> n >> w;

        for (ll i = 0; i < n; i++)
        {
                ll wi, vi;
                cin >> wi >> vi;
                weights.pb(wi);
                values.pb(vi);
        }

        ll ans = solve(n - 1, w);
        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
