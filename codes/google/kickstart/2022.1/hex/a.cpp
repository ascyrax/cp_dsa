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

                cout << "Case #" << i << ": ";

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

        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cin >> grid[i][j];
                }
        }

        // checking for blue.
        // bfs from edges of row1 of first column, counting the min
        // distance to reach the rowLast from any row1.

        // similarly check for red.
}

//................................

// int

// int

// int

// int
