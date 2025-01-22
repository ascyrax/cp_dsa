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
        vector<string> grid, guess;

        for (int i = 0; i < 3; i++)
        {
                string el;
                cin >> el;
                grid.pb(el);
        }
        for (int i = 0; i < 3; i++)
        {
                string el;
                cin >> el;
                guess.pb(el);
        }
        int green = 0, yellow = 0;
        map<char, int> cntGrid, cntGuess;
        for (int i = 0; i < 3; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                        if (grid[i][j] == guess[i][j])
                        {
                                green++;
                        }
                        else
                        {
                                cntGrid[grid[i][j]]++;
                                cntGuess[guess[i][j]]++;
                        }
                }
        }

        for (auto a : cntGrid)
        {
                // cout << a.first << " " << a.second << " " << cntGuess[a.first] << endl;
                yellow += min(a.second, cntGuess[a.first]);
        }

        cout << green << endl;
        cout << yellow << endl;
}

//................................

// int

// int

// int

// int
