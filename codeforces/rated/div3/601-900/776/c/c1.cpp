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
        int n, m;
        cin >> n >> m;

        vector<pair<pair<int, int>, int>> xw;

        for (int i = 0; i < m; i++)
        {
                int x, w;
                cin >> x >> w;
                xw.pb(make_pair(make_pair(w, x), i + 1));
        }

        sort(xw.begin(), xw.end());

        int wSum = 0;
        vector<pair<int, int>> ans;
        for (int i = 0; i < 2 * n; i++)
        {
                wSum += xw[i].first.first;
                ans.pb(make_pair(xw[i].first.second, xw[i].second));
        }

        cout << wSum << endl;

        sort(ans.begin(), ans.end());

        for (int i = 0; i < n; i++)
        {
                cout << ans[i].second << " " << ans[2 * n - 1 - i].second << endl;
        }
}

//................................

// int

// int

// int

// int
