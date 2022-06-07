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

        map<int, int> dp;

        // dp[i] = len of the required lis ending at i.
        int lislen = 0;
        int last = 0;

        for (int i = 0; i < n; i++)
        {
                dp[v[i]] = max(dp[v[i]], dp[v[i] - 1] + 1);
                if (dp[v[i]] > lislen)
                {
                        lislen = max(lislen, dp[v[i]]);
                        last = v[i];
                }
        }

        cout << lislen << endl;
        vector<int> indices;
        for (int i = n - 1; i >= 0; i--)
        {
                if (v[i] == last)
                {
                        indices.pb(i);
                        last--;
                }
        }
        reverse(indices.begin(), indices.end());
        for (int el : indices)
                cout << el + 1 << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
