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
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
                cin >> v[i];

        vector<int> ans(n + 1, 0);
        int rShift = 0;
        for (int i = n; i >= 1; i--)
        {
                // cout << "i = " << i << endl;
                // cout << "v " << endl;
                // for (auto el : v)
                //         cout << el << " ";
                // cout << endl;
                for (int j = i; j >= 0; j--)
                {
                        // cout << "j = " << j << endl;
                        if (v[j] == i)
                        {
                                if (i == j)
                                        rShift = 0;
                                else
                                        rShift = (i - (i - j));
                                // cout << "rShift = " << rShift << endl;
                                ans[i] = rShift;
                                break;
                        }
                }
                int temp = i - rShift;
                vector<int> bef_r_shift(n + 1);
                for (int j = 1; j <= i; j++)
                {
                        if (j + temp <= i)
                                bef_r_shift[j + temp] = v[j];
                        else
                                bef_r_shift[(j + temp) % (i)] = v[j];
                }
                for (int j = i + 1; j <= n; j++)
                        bef_r_shift[j] = v[j];
                v = bef_r_shift;
        }

        for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
