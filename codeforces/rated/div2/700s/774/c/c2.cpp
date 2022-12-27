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
// ll
void suraj()
{
        ll n;
        cin >> n;

        vector<ll> fact(16, 1);
        for (ll i = 1; i <= 15; i++)
        {
                fact[i] = fact[i - 1] * i;
        }
        // for (auto el : fact)
        //         cout << el << " ";
        // cout << endl;
        // fact.erase(fact.begin());
        // for (auto el : fact)
        //         cout << el << " ";
        // cout << endl;

        ll ans = __builtin_popcountll(n); // this is the max possible ans.
                                          // ans will never be -1;
        // order of subtracting the factorials or the powersof2 doesnt matter.
        for (ll i = 0; i <= (1 << 15) - 1; i++)
        {
                // all the subsets of the factorials.
                ll cnt1 = __builtin_popcountll(i);
                ll sum = 0;
                for (ll j = 0; j <= (14); j++)
                {
                        if (i & (1 << j))
                        {
                                sum += fact[j];
                        }
                }
                ll cnt2 = __builtin_popcountll(n - sum);
                ans = min(ans, cnt1 + cnt2);
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// ll

// int
