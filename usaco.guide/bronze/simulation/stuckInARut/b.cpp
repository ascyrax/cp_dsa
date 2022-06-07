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
bool wrty(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b)
{
        if (a.first.second < b.first.second)
                return true;
        else
                return false;
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        vector<pair<pair<int, int>, int>> east, north;

        for (int i = 0; i < n; i++)
        {
                char dir;
                int x, y;
                cin >> dir >> x >> y;

                if (dir == 'E')
                {
                        east.pb(make_pair(make_pair(x, y), i));
                }
                else if (dir == 'N')
                {
                        north.pb(make_pair(make_pair(x, y), i));
                }
        }
        vector<int> stop(n, 2e9);

        sort(north.begin(), north.end());
        sort(east.begin(), east.end(), wrty);
        // cout << "north:" << endl;
        // for (auto el : north)
        //         cout << el.first.first << " " << el.first.second << " " << el.second << endl;
        // cout << "east:" << endl;
        // for (auto el : east)
        //         cout << el.first.first << " " << el.first.second << " " << el.second << endl;

        for (int i = 0; i < north.size(); i++)
        {
                int nx = north[i].first.first;
                int ny = north[i].first.second;
                for (int j = 0; j < east.size(); j++)
                {
                        int ex = east[j].first.first;
                        int ey = east[j].first.second;
                        if (stop[east[j].second] < north[i].first.first)
                        {
                                continue;
                        }
                        else if (east[j].first.first < north[i].first.first && east[j].first.second > north[i].first.second)
                        {
                                int dx = nx - ex;
                                int dy = ey - ny;
                                if (dx < dy)
                                {
                                        stop[north[i].second] = dy;
                                        break;
                                }
                                else if (dy < dx)
                                {
                                        stop[east[j].second] = dx;
                                }
                        }
                }
        }

        for (int i = 0; i < n; i++)
        {
                if (stop[i] == 2e9)
                        cout << "Infinity" << endl;
                else
                        cout << stop[i] << endl;
        }
}

//................................

// int

// int

// int

// int
