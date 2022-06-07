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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c));
        vector<vector<int>> tgrid(c, vector<int>(r));
        for (int i = 0; i < r; i++)
        {
                for (int j = 0; j < c; j++)
                {
                        cin >> grid[i][j];
                        tgrid[j][i] = grid[i][j];
                }
        }

        for (int i = 0; i < c; i++)
        {
                for (int j = 0; j < r; j++)
                {
                        cout << tgrid[i][j] << " ";
                }
                cout << endl;
        }
}

//................................

// int

// int

// int

// int
