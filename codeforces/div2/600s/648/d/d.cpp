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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        // ioss
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<char>> grid;
vector<vector<int>> visit, visit2;
int neigh = 0; // -1 => b and g are neighbors
//...............................
bool ok(int x, int y)
{
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && visit[x][y] != 1)
        {
                return true;
        }
        else
                return false;
}
bool ok2(int x, int y)
{
        if (x >= 0 && x < n && y >= 0 && y < m && visit2[x][y] != 1)
                return true;
        else
                return false;
}
void dfs(int x, int y)
{
        for (int i = 0; i < 4; i++)
        {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (ok(nx, ny))
                {
                        visit[nx][ny] = 1;
                        dfs(nx, ny);
                }
        }
        return;
}
void boundB(int x, int y)
{
        if (neigh == -1)
                return;
        // if (grid[x][y] != 'B')
        //         for (int i = 0; i < 4; i++)
        //         {
        //                 int nx = x + dx[i];
        //                 int ny = y + dy[i];
        //                 if (ok2(nx, ny))
        //                 {
        //                         visit2[nx][ny] = 1;
        //                         // cout << "nx = " << nx << " ny = " << ny << endl;
        //                         boundB(nx, ny);
        //                         if (neigh == -1)
        //                                 return;
        //                 }
        //         }
        for (int i = 0; i < 4; i++)
        {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (ok2(nx, ny))
                {
                        visit2[nx][ny] = 1;
                        if (grid[nx][ny] == 'G')
                        {
                                neigh = -1;
                                return;
                        }
                        else if (grid[nx][ny] == '.')
                        {
                                grid[nx][ny] = '#';
                                // visit2[nx][ny] = 1;
                                // boundB(nx, ny);
                        }
                        else if (grid[nx][ny] == 'B')
                        {
                                boundB(nx, ny);
                                if (neigh == -1)
                                        return;
                        }
                }
        }

        return;
}
//...............................

void suraj()
{
        // cout << "----------------------------------------------------------------" << endl;
        cin >> n >> m;
        grid = vector<vector<char>>(n, vector<char>(m));
        visit = vector<vector<int>>(n, vector<int>(m));
        visit2 = vector<vector<int>>(n, vector<int>(m));
        vector<pair<int, int>> gs, bs;
        neigh = 0;
        for (int i = 0; i < n; i++)
        {
                string row;
                cin >> row;
                for (int j = 0; j < m; j++)
                {
                        grid[i][j] = row[j];
                        if (row[j] == 'G')
                        {
                                gs.pb(make_pair(i, j));
                        }
                        else if (row[j] == 'B')
                        {
                                bs.pb(make_pair(i, j));
                        }
                }
        }
        // cout << "hi" << endl;
        for (auto el : bs)
                if (visit2[el.first][el.second] != 1)
                        boundB(el.first, el.second);

        // print the grid after adding new walls
        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = 0; j < m; j++)
        //         {
        //                 cout << grid[i][j];
        //         }
        //         cout << endl;
        // }

        // if any g and b are neighboring then cout no
        if (neigh == -1)
        {
                cout << "NO" << endl;
                return;
        }
        // if all g dont have visit=1 cout no
        if (grid[n - 1][m - 1] != '#')
                dfs(n - 1, m - 1); //starting from the position (n-1,m-1);
        for (auto el : gs)
        {
                if (visit[el.first][el.second] != 1)
                {
                        cout << "NO" << endl;
                        return;
                }
        }
        for (auto el : bs)
        {
                if (visit[el.first][el.second] == 1)
                {
                        cout << "NO" << endl;
                        return;
                }
        }
        cout << "YES" << endl;
}

//................................
