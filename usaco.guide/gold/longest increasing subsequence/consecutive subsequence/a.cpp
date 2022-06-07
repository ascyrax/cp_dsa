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
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        vector<int> dp(n + 1, 2e9);
        dp[0] = -2e9;

        for (int i = 0; i < n; i++)
        {
                int j = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
                if (dp[j - 1] < v[i] && v[i] < dp[j])
                {
                        if (j > 1)
                        {
                                if (v[i] == dp[j - 1] + 1)
                                        dp[j] = v[i];
                        }
                        else
                        {
                                dp[j] = v[i];
                        }
                }
        }

        for (auto el : dp)
                cout << el << " ";
        cout << endl;

        int lislen = 0;
        for (int i = 1; i <= n; i++)
        {
                if (dp[i] < 2e9)
                        lislen = max(lislen, i);
        }

        cout << lislen << endl;
}

//................................

// int

// int

// int

// int
