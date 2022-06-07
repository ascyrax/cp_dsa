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

        freopen("countcross.in", "r", stdin);
        freopen("countcross.out", "w", stdout);

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
int n, k, r;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
int colorValue = 1;
vector<vector<int>> color;
map<pair<pair<int, int>, pair<int, int>>, bool> road;
vector<pair<int, int>> cows;
bool check(int r, int c, int rnew, int cnew)
{
        if (rnew >= 0 && rnew < n && cnew >= 0 && cnew < n)
        {
                if (road[make_pair(make_pair(r, c), make_pair(rnew, cnew))] || road[make_pair(make_pair(rnew, cnew), make_pair(r, c))])
                {
                        // cout << "r = " << r + 1 << " , c = " << c + 1 << " , rnew = " << rnew + 1 << " , cnew = " << cnew + 1 << endl;
                        return false;
                }
                else
                        return true;
        }
        else
                return false;
}

void dfs(int r, int c, int colorValue)
{
        for (int i = 0; i < 4; i++)
        {
                if (check(r, c, r + dr[i], c + dc[i]) && color[r + dr[i]][c + dc[i]] == 0)
                {
                        color[r + dr[i]][c + dc[i]] = colorValue;
                        dfs(r + dr[i], c + dc[i], colorValue);
                }
        }
}
//...............................

void suraj()
{
        cin >> n >> k >> r;
        color = vector<vector<int>>(n, vector<int>(n, 0));

        // roads input
        for (int i = 0; i < r; i++)
        {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                a--;
                b--;
                c--;
                d--;
                road[make_pair(make_pair(a, b), make_pair(c, d))] = true;
        }

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        if (color[i][j] == 0)
                        {
                                // cout << "i = " << i << " , j = " << j << endl;
                                color[i][j] = colorValue;
                                dfs(i, j, colorValue);
                                colorValue++;
                        }
                }
        }

        // printing the color of the grid
        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = 0; j < n; j++)
        //         {
        //                 cout << color[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        // input location of cows
        for (int i = 0; i < k; i++)
        {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                cows.pb(make_pair(a, b));
        }
        map<int, int> m;
        for (auto el : cows)
        {
                m[color[el.first][el.second]]++;
        }
        int ans = 0;
        ll counted = 0;
        for (auto el : m)
        {
                // cout << el.first + 1 << " " << el.second + 1 << " " << color[el.first][el.second] << endl;
                ans += (el.second * counted);
                counted += el.second;
        }
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
