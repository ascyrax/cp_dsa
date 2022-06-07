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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax
int n, m;
const ll mod = 1e9 + 7;
vector<string> grid;
vector<vector<bool>> visited, visited2;
int flag;
//...............................

void checkBG(int i, int j) //for checking if B and G are adjacent anywhere or not
{
        if (visited[i][j])
                return;
        visited[i][j] = true;
        if (grid[i][j] == 'G')
        {
                flag = -1;
                return;
        }
        else if (grid[i][j] == 'B')
        {
                if (j + 1 < m)
                {
                        checkBG(i, j + 1);
                }
                if (j - 1 >= 0)
                {
                        checkBG(i, j - 1);
                }
                if (i - 1 >= 0)
                {
                        checkBG(i - 1, j);
                }
                if (i + 1 < n)
                {
                        checkBG(i + 1, j);
                }
        }
        else
        {
                grid[i][j] = '#';
        }
}

// func to check for each G , if he can leave the maze or not
int path = 0;
void checkPath(int i, int j)
{
        if (make_pair(i, j) == make_pair(n - 1, m - 1))
        {
                path = 1;
                return;
        }
        if (visited2[i][j])
                return;
        if (!visited2[i][j])
                visited2[i][j] = true;

        if (grid[i][j] == '.' || grid[i][j] == 'G')
        {
                if (j + 1 < m)
                {
                        checkPath(i, j + 1);
                        if (path == 1)
                                return;
                }
                if (j - 1 >= 0)
                {
                        checkPath(i, j - 1);
                        if (path == 1)
                                return;
                }
                if (i - 1 >= 0)
                {
                        checkPath(i - 1, j);
                        if (path == 1)
                                return;
                }
                if (i + 1 < n)
                {
                        checkPath(i + 1, j);
                        if (path == 1)
                                return;
                }
        }
        else
                return;
}

void suraj()
{

        cin >> n >> m;
        grid = vector<string>(n);
        visited = vector<vector<bool>>(n, vector<bool>(m));
        flag = 0;

        for (int i = 0; i < n; i++)
        {
                string s;
                cin >> s;
                grid[i] = s;
        }
        int cntg = 0;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        if (!visited[i][j] && grid[i][j] == 'B')
                        {
                                checkBG(i, j);
                        }
                        if (flag == -1)
                        {
                                cout << "NO" << endl;
                                return;
                        }
                        if (grid[i][j] == 'G')
                                cntg++;
                }
        }
        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = 0; j < m; j++)
        //         {
        //                 cout << grid[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        if (grid[n - 1][m - 1] == 'B')
        {
                cout << "NO" << endl;
        }
        else if (grid[n - 1][m - 1] == '#')
        {
                if (cntg > 0)
                        cout << "NO" << endl;
                else
                        cout << "YES" << endl;
        }
        else
        {
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (grid[i][j] == 'G')
                                {
                                        visited2 = vector<vector<bool>>(n, vector<bool>(m));

                                        path = 0;
                                        checkPath(i, j);
                                        if (path != 1)
                                        {
                                                cout << "NO" << endl;
                                                return;
                                        }
                                }
                        }
                }
                cout << "YES" << endl;
        }
}

//................................
