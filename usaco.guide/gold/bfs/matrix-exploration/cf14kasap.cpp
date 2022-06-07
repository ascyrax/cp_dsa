#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int n, m, k;

vector<vector<int>> vdist;
vector<string> grid;
vector<vector<bool>> visited;

queue<pair<pair<int, int>, int>> q;

bool check(int r, int c)
{
        // cout << "check " << r << " " << c << endl;
        if (!(r >= 0 && r <= n - 1 && c >= 0 && c <= m - 1))
        {
                // cout << "if" << endl;
                return false;
        }
        else if (grid[r][c] == '#')
        {
                // cout << "else if -1 " << endl;
                return false;
        }
        else if (visited[r][c])
        {
                // cout << "else if - 2" << endl;
                return false;
        }
        else
        {
                // cout << "else " << endl;
                return true;
        }
}

void bfs(int r, int c)
{
        // cout << "in" << endl;

        visited[r][c] = true;

        while (!q.empty())
        {
                // cout << "q.size()= " << q.size() << endl;
                // cout << "q.front() = " << q.front().first.first << " " << q.front().first.second << " " << q.front().second << endl;
                r = q.front().first.first;
                c = q.front().first.second;
                vdist[r][c] = min(vdist[r][c], q.front().second);
                if (check(r - 1, c))
                {
                        // cout << "a" << endl;
                        q.push(make_pair(make_pair(r - 1, c), q.front().second + 1));
                }
                if (r - 1 >= 0)
                        visited[r - 1][c] = true;
                if (check(r + 1, c))
                {
                        // cout << "b" << endl;
                        q.push(make_pair(make_pair(r + 1, c), q.front().second + 1));
                }
                if (r + 1 <= n - 1)
                        visited[r + 1][c] = true;
                if (check(r, c - 1))
                {
                        // cout << "c" << endl;
                        q.push(make_pair(make_pair(r, c - 1), q.front().second + 1));
                }
                if (c - 1 >= 0)
                        visited[r][c - 1] = true;
                if (check(r, c + 1))
                {
                        // cout << "d" << endl;
                        q.push(make_pair(make_pair(r, c + 1), q.front().second + 1));
                }
                if (c + 1 <= m)
                        visited[r][c + 1] = true;
                q.pop();
        }
        // cout << "out" << endl;
        return;
}

int main()
{
        cin >> n >> m >> k;

        vdist = vector<vector<int>>(n, vector<int>(m, 1e9));

        for (int i = 0; i < n; i++)
        {
                string row;
                cin >> row;
                grid.pb(row);
        }
        // cout << grid[4][1] << endl;
        // cout << grid[4][3] << endl;
        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = 0; j < m; j++)
        //         {
        //                 cout << grid[i][j];
        //         }
        //         cout << endl;
        // }

        vector<pair<int, int>> vk;

        for (int i = 0; i < k; i++)
        {
                int r, c;
                cin >> r >> c;
                vk.pb(make_pair(r - 1, c - 1));
                // vdist[r-1][c-1]=0;//these are already initialized to 0
        }

        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for (auto el : vk)
        {
                q.push(make_pair(el, 0));
        }

        bfs(q.front().first.first, q.front().first.second);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        // cout << vdist[i][j] << " ";
                        if (grid[i][j] == '.')
                                ans += vdist[i][j];
                }
                // cout << endl;
        }

        cout << ans << endl;

        return 0;
}