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
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;
        int flag = 1; // -1 for no // 1 for yes.
        vector<int> diffs;
        for (int i = 0; i < n; i++)
        {
                if (b[i] >= a[i])
                        diffs.pb(b[i] - a[i]);
                else
                        // diffs.pb(((b[i] - a[i]) + 26) % 26);
                        diffs.pb(26 - (a[i] - b[i]));
        }

        vector<int> psPosFirst, psNegFirst;

        psPosFirst.push_back(diffs[0]);
        for (int i = 1; i < n; i++)
        {
                if (i % 2 == 1)
                {
                        // -
                        psPosFirst.pb(psPosFirst.back() - diffs[i]);
                }
                else
                {
                        psPosFirst.pb(psPosFirst.back() + diffs[i]);
                }
        }

        psNegFirst.push_back(-1 * diffs[0]);
        for (int i = 1; i < n; i++)
        {
                if (i % 2 == 1)
                {
                        psNegFirst.pb(psNegFirst.back() + diffs[i]);
                }
                else
                {
                        psNegFirst.pb(psNegFirst.back() - diffs[i]);
                }
        }

        // cout << "diffs" << endl;
        // for (auto el : diffs)
        //         cout << el << " ";
        // cout << endl;

        // cout << "psPosFirst" << endl;
        // for (auto el : psPosFirst)
        //         cout << el << " ";
        // cout << endl;

        // cout << "psNegFirst" << endl;
        // for (auto el : psNegFirst)
        //         cout << el << " ";
        // cout << endl;

        for (int i = 0; i < q; i++)
        {
                int l, r;
                cin >> l >> r;

                l--, r--;
                // if we move from left to right, then when making the rth indices equal, we have to do nMoves = diff at rth index - (moves done at (r-1)th index) which forms a recursive iteration till the lth index.
                // i.e choose a prefix sum in which rth index is being added.
                ll val = -1;
                if (r % 2 == 1)
                {
                        if (l >= 1)
                                val = psNegFirst[r] - psNegFirst[l - 1];
                        else
                                val = psNegFirst[r];
                }
                else
                {
                        if (l >= 1)
                                val = psPosFirst[r] - psPosFirst[l - 1];
                        else
                                val = psPosFirst[r];
                }
                // if A = "abc" and B = "nbp". then diffs={13,0,13}. here val=26. therefore, we need to do val%26==0.
                if ((val % 26) == 0)
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
