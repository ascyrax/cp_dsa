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

        freopen("lazy.in", "r", stdin);
        freopen("lazy.out", "w", stdout);

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

        // dimension of square grid gb = length of the diagonal of ga + additional blank 0s.
        // which is = n+(n-1)
        vector<vector<ll>> ga(n, vector<ll>(n)), gb(n + n - 1, vector<ll>(n + n - 1));
        ll total = 0;
        for (ll i = 0; i < n; i++)
        {
                for (ll j = 0; j < n; j++)
                {
                        cin >> ga[i][j];
                        total += ga[i][j];
                }
        }

        // flag[i][j] = true means this is a position corresponding to a real location on the farm grid. Not just some lattice poll containing zero values.
        // dimension = n+n becz we will be iterating throught the elements of the ps which is a 2d array of dimension n+n.
        vector<vector<bool>> flag(n + n, vector<bool>(n + n, false));
        // rotate the grid by 45 degrees llo another grid.
        for (ll i = 0; i < n; i++)
        {
                for (ll j = 0; j < n; j++)
                {
                        gb[i + j][n - i + j - 1] = ga[i][j];
                        flag[(i + j) + 1][(n - 1 - i + j) + 1] = true; // since ps is going to be a 1-indexed 2-d array
                }
        }

        // find 2-D ps & then the sums of squares of size k*k
        vector<vector<ll>> ps(n + n, vector<ll>(n + n)); // n+n becz ps will be 1-indexed prefix sum for gb which is of dimension n+n-1
        for (ll i = 1; i <= n + n - 1; i++)
        {
                for (ll j = 1; j <= n + n - 1; j++)
                {
                        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + gb[i - 1][j - 1]; // since gb is 0 indexed.
                }
        }

        // //////////////////////////////////////////////////////////////////
        // for (ll i = 0; i < n + n - 1; i++)
        // {
        //         for (ll j = 0; j < n + n - 1; j++)
        //         {
        //                 cout << gb[i][j] << "    ";
        //         }
        //         cout << endl;
        // }
        // cout << endl;
        // for (ll i = 0; i <= n + n - 1; i++)
        // {
        //         for (ll j = 0; j <= n + n - 1; j++)
        //         {
        //                 cout << ps[i][j] << "    ";
        //         }
        //         cout << endl;
        // }
        // //////////////////////////////////////////////////////////////////

        ll ans = 0;
        // checking for each grazed area's bottom right corner as (i,j)
        ll dist = k + k + 1;
        // dimension of ps is (n+n * n+n)

        bool flag2 = false;

        for (ll i = dist; i < n + n; i++)
        {
                for (ll j = dist; j < n + n; j++)
                {
                        flag2 = true;
                        if (!flag[i][j])
                                continue;
                        ll sum = ps[i][j] - ps[i - dist][j] - ps[i][j - dist] + ps[i - dist][j - dist];
                        // cout << " " << i << " " << j << endl;
                        // cout << ps[i][j] << " " << ps[i - dist][j - dist] << endl;
                        // cout << sum << endl;
                        if (sum >= ans)
                        {
                                ans = max(ans, sum);
                        }
                }
        }
        if (flag2 == false)
        {
                // this loop never ran for an answer
                cout << total << endl;
        }
        else
                cout << ans << endl;
}

//................................

// ll

// ll

// ll

// ll
