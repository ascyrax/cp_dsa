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

        for (int i = 0; i <= n - 2; i++)
        {
                for (int j = 0; j <= m - 2; j++)
                {
                        int black = 0;
                        int white = 0;
                        grid[i][j] == '0' ? white++ : black++;
                        grid[i][j + 1] == '0' ? white++ : black++;
                        grid[i + 1][j] == '0' ? white++ : black++;
                        grid[i + 1][j + 1] == '0' ? white++ : black++;
                        if (white == 1)
                        {
                                cout << "NO" << endl;
                                return;
                        }
                }
        }
        cout << "YES" << endl;
}

//................................

// int

// int

// int

// int
