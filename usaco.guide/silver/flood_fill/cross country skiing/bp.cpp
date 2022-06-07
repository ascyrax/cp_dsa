#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int r, c;
vector<vector<int>> grid; // grid stores the elevation

// this will be true if the corresponding location
// of the grid has been visited atleast once
vector<vector<bool>> visited;

// right bottom left top
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// this will contain all the waypoints
vector<pair<int, int>> wpts;

void dfs(int row, int col, int mid)
{
        if (row < 0 || col >= c)
        {
                return;
        }
        visited[row][col] = true;
        for (int i = 0; i <= 3; i++)
        {
                int newRow = row + dy[i];
                int newCol = col + dx[i];

                // all three conditions below need to be met simultaneously

                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c)
                        if (!visited[newRow][newCol])
                                if (abs(grid[newRow][newCol] - grid[row][col]) <= mid)
                                        dfs(newRow, newCol, mid);
        }
        return;
}

bool check()
{
        for (auto i : wpts)
        {
                // checking if all the waypoints were visited in the last dfs, or not
                if (visited[i.first][i.second] == false)
                        return false;
        }
        return true;
}

int main()
{

        freopen("ccski.in", "r", stdin);
        freopen("ccski.out", "w", stdout);

        cin >> r >> c;

        grid = vector<vector<int>>(r, vector<int>(c));
        visited = vector<vector<bool>>(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
                for (int j = 0; j < c; j++)
                {
                        cin >> grid[i][j];
                }
        }

        for (int i = 0; i < r; i++)
        {
                for (int j = 0; j < c; j++)
                {
                        int x;
                        cin >> x;
                        if (x == 1)
                                wpts.pb(make_pair(i, j)); // wpts contains all the waypoints
                }
        }

        // Binary search for the minimum possible value of d that works
        // We can set "hi" to 1e9 because that will be the
        // maximum value of d we need to try

        int lo = 0, hi = 1e9;
        while (lo < hi)
        {
                int mid = lo + (hi - lo) / 2;

                // mid is the maximum absolute elevation difference
                dfs(0, 0, mid);

                // checking if all the waypoints were visited or not
                if (check())
                {
                        hi = mid;
                }
                else
                        lo = mid + 1;

                visited = vector<vector<bool>>(r, vector<bool>(c, false));
        }

        cout << lo << endl;
}
