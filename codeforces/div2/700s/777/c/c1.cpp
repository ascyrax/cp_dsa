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

        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
                cin >> grid[i];
        }
        int cnt = 0;
        vector<vector<int>> ans;
        for (int i = n - 1; i >= 0; i--)
        {
                for (int j = m - 1; j >= 1; j--)
                {
                        // cout << i << " " << j << endl;
                        if (grid[i][j] == '1')
                        {
                                cnt++;
                                vector<int> temp = {i, j - 1, i, j};
                                ans.pb(temp);
                        }
                }
        }
        for (int i = n - 1; i >= 1; i--)
        {
                if (grid[i][0] == '1')
                {
                        cnt++;
                        vector<int> temp = {i - 1, 0, i, 0};
                        ans.pb(temp);
                }
        }
        if (grid[0][0] == '1')
        {
                cout << -1 << endl;
        }
        else
        {
                cout << cnt << endl;
                for (auto el : ans)
                {
                        for (auto i : el)
                                cout << i + 1 << " ";
                        cout << endl;
                }
        }
}

//................................

// int

// int

// int

// int
