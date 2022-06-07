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
        int r, c, m;
        cin >> r >> c >> m;

        map<int, int> cntr, cntc;

        map<pair<int, int>, bool> bomb;

        for (int i = 0; i < m; i++)
        {
                int tr, tc;
                cin >> tr >> tc;

                bomb[make_pair(tr, tc)] = true;

                cntr[tr]++;
                cntc[tc]++;
        }

        int temp = 0;

        vector<int> bestr, bestc;

        for (auto el : cntr)
        {
                if (el.second > temp)
                {
                        bestr.clear();
                        bestr.pb(el.first);
                        temp = el.second;
                }
                else if (el.second == temp)
                {
                        bestr.pb(el.first);
                        temp = el.second;
                }
        }
        temp = 0;
        for (auto el : cntc)
        {
                if (el.second > temp)
                {
                        bestc.clear();
                        bestc.pb(el.first);
                        temp = el.second;
                }
                else if (el.second == temp)
                {
                        bestc.pb(el.first);
                        temp = el.second;
                }
        }

        int flag = -1;
        int ans = 0;

        // for (auto el : bestr)
        //         cout << el << " ";
        // cout << endl;
        // for (auto el : bestc)
        //         cout << el << " ";
        // cout << endl;

        // cout << "bestr.size() = " << bestr.size() << endl;
        // cout << cntr[bestr[0]] << " " << cntr[bestr[1]] << endl;
        // cout << cntc[bestc[0]] << " " << cntc[bestc[1]] << " " << cntc[bestc[2]] << endl;

        for (int i = 0; i < bestr.size(); i++)
        {
                for (int j = 0; j < bestc.size(); j++)
                {
                        // cout << "i = " << i << ", j = " << j << endl;
                        if (bomb[make_pair(bestr[i], bestc[j])] == false)
                        {
                                ans = cntr[bestr[i]] + cntc[bestc[j]];
                                flag = 1;
                                break;
                        }
                }
                if (flag == 1)
                        break;
        }

        // cout << "flag = " << flag << endl;

        if (flag == 1)
                cout << ans << endl;
        else
                cout << cntr[bestr[0]] + cntc[bestc[0]] - 1 << endl;
}

//................................

// int

// int

// int

// int
