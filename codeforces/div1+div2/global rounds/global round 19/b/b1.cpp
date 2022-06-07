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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        vector<int> ps;
        if (v[0] == 0)
                ps.pb(1);
        else
                ps.pb(0);

        for (int i = 1; i < n; i++)
        {
                if (v[i] == 0)
                {
                        ps.pb(ps.back() + 1);
                }
                else
                        ps.pb(ps.back());
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
                for (int j = i; j < n; j++)
                {
                        // current subsegment will be v[i to j];
                        int len = j - i + 1;
                        int n_zeros = 0;
                        if (i - 1 >= 0)
                                n_zeros = ps[j] - ps[i - 1];
                        else
                                n_zeros = ps[j];
                        ans += (len + n_zeros);
                }
        }
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
