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

        int h, w, d;
        cin >> h >> w >> d;

        vector<vector<int>> grid(h + 1, vector<int>(w + 1));
        map<int, pair<int, int>> cord;
        for (int i = 1; i <= h; i++)
        {
                for (int j = 1; j <= w; j++)
                {
                        cin >> grid[i][j];
                        cord[grid[i][j]] = make_pair(i, j);
                }
        }

        vector<int> ps[d + 1];

        for (int i = 1; i <= d; i++)
        {
                // cout << "i = " << i << endl;
                int j = i;
                while (j < w * h)
                {
                        // cout << "j = " << j << endl;
                        int next = j + d;
                        if (j + d > w * h)
                                break;
                        int diffx = abs(cord[next].first - cord[j].first);
                        int diffy = abs(cord[next].second - cord[j].second);
                        j += d;
                        ps[i].pb(diffx + diffy);
                        // cout << j - d << " " << j << endl;
                        // cout << diffx << " " << diffy << endl;
                }
                for (j = 1; j < ps[i].size(); j++)
                {
                        ps[i][j] += ps[i][j - 1];
                }
        }

        // for (int i = 0; i <= d; i++)
        // {
        //         for (auto el : ps[i])
        //                 // cout << el << " ";
        //         // cout << endl;
        // }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++)
        {
                ll sum = 0;
                int l, r;
                cin >> l >> r;
                int first;
                if (r % d == 0)
                        first = d;
                else
                        first = r % d;
                // cout << "first = " << first << endl;
                int posl, posr;
                posl = (l - first) / d;
                posr = (r - first) / d;
                // cout << "posl = " << posl << endl;
                // cout << "posr = " << posr << endl;
                if (l == first)
                {
                        if (r == first)
                                sum = 0;
                        else
                                sum += (ps[first][posr - 1] - 0);
                }
                else
                {
                        if (r == first)
                                sum = 0;
                        else
                                sum += ps[first][posr - 1] - ps[first][posl - 1];
                }
                cout << sum << endl;
        }
}

//................................

// int

// int

// int

// int
