// KICKSTART ROUND D, 2020

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

        ioss

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
        int k;
        cin >> k;
        vector<int> v(k);
        for (int &i : v)
                cin >> i;

        int up = 1, down = 1;
        int ans = 0;
        for (int i = 1; i < k; i++)
        {
                if (v[i] > v[i - 1])
                {
                        down = 1;
                        up++;
                }
                else if (v[i] < v[i - 1])
                {
                        up = 1;
                        down++;
                }
                else
                {
                        up = up;
                        down = down;
                }
                if (up > 4)
                {
                        ans++;
                        up = 1;
                }
                else if (down > 4)
                {
                        ans++;
                        down = 1;
                }
        }
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
