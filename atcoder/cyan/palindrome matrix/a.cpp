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
        int row, col;
        cin >> row >> col;

        vector<string> grid;

        map<char, int> cnt;

        int a = 0, b = 0, c = 0, d = 0; // d represent 4, a represent 1, b represent 2, c represent 3

        for (int i = 0; i < row; i++)
        {
                string s;
                cin >> s;

                grid.pb(s);

                for (int j = 0; j < col; j++)
                {
                        cnt[s[j]]++;
                }
        }

        for (auto &el : cnt)
        {

                if (el.second >= 4)
                {
                        d += el.second / 4;
                        el.second %= 4;
                }
                if (el.second >= 2)
                {
                        b += el.second / 2;
                        el.second %= 2;
                }
                a += el.second;
        }

        if (row % 2 == 0 && col % 2 == 0)
        {
                if (d * 4 == row * col)
                        cout << "Yes" << endl;
                else
                        cout << "No" << endl;
        }
        else if (row % 2 == 0 && col % 2 == 1)
        {
                if (d * 4 >= (row * col - row))
                        b += (4 * d - (row * col - row)) / 2;
                else
                {
                        cout << "No" << endl;
                        return;
                }
                if (b * 2 == row)
                        cout << "Yes" << endl;
                else
                        cout << "No" << endl;
        }
        else if (row % 2 == 1 && col % 2 == 0)
        {
                if (d * 4 >= (row * col - col))
                        b += (4 * d - (row * col - col)) / 2;
                else
                {
                        cout << "No" << endl;
                        return;
                }
                if (b * 2 == col)
                        cout << "Yes" << endl;
                else
                        cout << "No" << endl;
        }
        else if (row % 2 == 1 && col % 2 == 1)
        {
                if (d * 4 >= (row * col - row - col + 1)) // +1 becz the middle element of the grid gets removed twice
                        b += (4 * d - (row * col - row - col + 1)) / 2;
                else
                {
                        cout << "No" << endl;
                        return;
                }
                if (b * 2 == (row + col - 1) - 1)
                        cout << "Yes" << endl;
                else
                        cout << "No" << endl;
        }
}

//................................

// int

// int

// int

// int
