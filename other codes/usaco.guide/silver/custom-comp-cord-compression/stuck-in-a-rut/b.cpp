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
vector<int> parent, cnt;
vector<vector<int>> child;
//...............................
bool columnWise(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
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

        child = vector<vector<int>>(n, vector<int>());

        for (int i = 0; i < n; i++)
        {
                // child.pb(-1);
                parent.pb(i);
                cnt.pb(0);
        }

        vector<pair<pair<int, int>, int>> east, north;

        for (int i = 0; i < n; i++)
        {
                char dir;
                cin >> dir;
                int r, c;
                cin >> r >> c;
                if (dir == 'E')
                {
                        east.pb(make_pair(make_pair(r, c), i));
                }
                else
                        north.pb(make_pair(make_pair(r, c), i));
        }

        sort(east.begin(), east.end(), columnWise);
        sort(north.begin(), north.end());

        for (int i = 0; i < north.size(); i++)
        {
                int r = north[i].first.first;
                int c = north[i].first.second;
                for (int j = 0; j < east.size(); j++)
                {
                        if (parent[east[j].second] != east[j].second)
                                continue;
                        if (east[j].first.second > c && east[j].first.first < r)
                        {
                                int colDiff = east[j].first.second - c;
                                int rowDiff = r - east[j].first.first;
                                if (colDiff > rowDiff)
                                {
                                        parent[north[i].second] = east[j].second;
                                        child[east[j].second].pb(north[i].second);
                                        break;
                                }
                                else if (colDiff < rowDiff)
                                {
                                        parent[east[j].second] = north[i].second;
                                        child[north[i].second].pb(east[j].second);
                                }
                        }
                }
        }

        for (int i = 0; i < east.size(); i++)
        {
                if (parent[east[i].second] != east[i].second)
                        continue;
                int r = east[i].first.first;
                int c = east[i].first.second;
                // cout << r << " " << c << " " << north[i].second << endl;
                for (int j = 0; j < north.size(); j++)
                {
                        if (parent[north[j].second] != north[j].second)
                                continue;
                        if (north[j].first.second < c && north[j].first.first > r)
                        {
                                int colDiff = c - north[j].first.second;
                                int rowDiff = north[j].first.first - r;
                                if (colDiff < rowDiff)
                                {
                                        // cout << north[j].first.first << " " << north[j].first.second << " " << north[j].second << endl;
                                        parent[east[i].second] = north[j].second;
                                        child[north[j].second].pb(east[i].second);
                                        break;
                                }
                                else if (colDiff < rowDiff)
                                {
                                        parent[north[j].second] = east[i].second;
                                        child[east[i].second].pb(north[j].second);
                                }
                        }
                }
        }

        for (int i = 0; i < n; i++)
        {
                if (child[i].size() == 0)
                {
                        // implies that this is either a leaf node or disconnected individual node(movind infinitely in their direction)
                        cnt[i] = 0;

                        // if infinite moving cow
                        if (parent[i] == i)
                                continue;

                        // if leaf node of a component (dag) where children point to their parent
                        int j = i;
                        // cout << "i = " << i << endl;
                        int up = 1;
                        while (parent[j] != j)
                        {
                                cnt[parent[j]] += up;
                                up++;
                                j = parent[j];
                                // cout << "j = " << j << endl;
                        }
                        // cout << "cnt :" << endl;
                        // for (auto el : cnt)
                        // cout << el << " ";
                        // cout << endl;
                }
        }
        // for (int i = 0; i < n; i++)
        // {
        //         // cout << "i = " << i << " ,parent[i] = " << parent[i] << endl;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //         // cout << "children of i = " << i << " : ";
        //         for (auto el : child[i])
        //                 // cout << el << " ";
        //         // cout << endl;
        // }
        for (int i = 0; i < n; i++)
                cout << cnt[i] << endl;
}

//................................

// int

// int

// int

// int
