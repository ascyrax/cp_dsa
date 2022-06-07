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

        // freopen("b.in", "r", stdin);
        // freopen("b.out", "w", stdout);

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

int r, c;
vector<string> grid;
pair<int, int> root;
vector<pair<int, int>> monsters;
vector<vector<int>> visit;
queue<pair<pair<int, int>, int>> q;
vector<vector<bool>> flag;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
//...............................

bool check(int x, int y)
{
        if (x < 0 || y < 0 || x >= r || y >= c)
                return false;
        else if (grid[x][y] == '#' || grid[x][y] == 'M' || grid[x][y] == 'A')
                return false;
        else
                return true;
}

void bfs()
{
        flag = vector<vector<bool>>(r, vector<bool>(c, false));

        while (!q.empty())
        {
                auto top = q.front();
                q.pop();

                // cout << "yo" << endl;
                int topx = top.first.first;

                int topy = top.first.second;
                int topd = top.second;

                // cout << topx << " " << topy << " " << topd << endl;

                if (flag[topx][topy] == true)
                        continue;
                else
                        flag[topx][topy] = true;
                // cout << "hi" << endl;
                if (topd < visit[topx][topy])
                        visit[topx][topy] = topd;
                else
                        continue;
                // cout << "Hello" << endl;
                for (int i = 0; i < 4; i++)
                {
                        // cout << "i : " << i << endl;
                        if (check(topx + dx[i], topy + dy[i]))
                                q.push(make_pair(make_pair(topx + dx[i], topy + dy[i]), topd + 1));
                }
        }
        // cout << "done" << endl;
}
map<pair<int, int>, pair<int, int>> parent;
pair<pair<int, int>, int> last;
bool bfs2(int x, int y)
{
        q.push(make_pair(make_pair(x, y), 0));
        parent[make_pair(x, y)] = make_pair(-1, -1);

        flag = vector<vector<bool>>(r, vector<bool>(c, false));

        while (!q.empty())
        {
                auto top = q.front();
                q.pop();
                int topx = top.first.first;
                int topy = top.first.second;
                int topd = top.second;

                // cout << topx << " " << topy << " " << topd << endl;

                if (flag[topx][topy] == true)
                        continue;
                else
                        flag[topx][topy] = true;

                if (topd >= visit[topx][topy])
                        continue;

                if (topx == 0 || topx == r - 1 || topy == 0 || topy == c - 1)
                {
                        last = top;
                        return true;
                }
                // cout << "passed " << topx << " " << topy << " " << topd << endl;

                for (int i = 0; i < 4; i++)
                {
                        if (grid[topx + dx[i]][topy + dy[i]] != '#')
                        {
                                q.push(make_pair(make_pair(topx + dx[i], topy + dy[i]), topd + 1));
                                if (parent.count(make_pair(topx + dx[i], topy + dy[i])) == 0)
                                        parent[make_pair(topx + dx[i], topy + dy[i])] = make_pair(topx, topy);
                        }
                }
        }
        return false;
}
//...............................

void suraj()
{
        cin >> r >> c;

        visit = vector<vector<int>>(r, vector<int>(c, 1e9));

        for (int i = 0; i < r; i++)
        {
                string temp;
                cin >> temp;
                grid.pb(temp);

                for (int j = 0; j < c; j++)
                {
                        if (temp[j] == 'M')
                                monsters.pb(make_pair(i, j));
                        if (temp[j] == 'A')
                                root = make_pair(i, j);
                }
        }

        for (auto el : monsters)
                q.push(make_pair(make_pair(el.first, el.second), 0));

        bfs();

        // cout << "hello" << endl;
        // for (int i = 0; i < r; i++)
        // {
        //         for (int j = 0; j < c; j++)
        //         {
        //                 if (visit[i][j] == 1e9)
        //                         cout << "#"
        //                              << " ";
        //                 else
        //                         cout << visit[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        // cout << "hello" << endl;

        if (bfs2(root.first, root.second))
        {
                cout << "YES" << endl;
                cout << last.second << endl;

                vector<char> ans;
                pair<int, int> current = last.first;
                while (1)
                {
                        pair<int, int> p = parent[current];
                        // cout << "current: " << current.first << " " << current.second << endl;
                        // cout << "parent: " << p.first << " " << p.second << endl;

                        if (p == make_pair(-1, -1))
                                break;

                        if (p.first == current.first)
                        {
                                // L or R
                                if (p.second < current.second)
                                        ans.pb('L');
                                else
                                        ans.pb('R');
                        }
                        else
                        {
                                if (p.first < current.first)
                                        ans.pb('U');
                                else
                                        ans.pb('D');
                        }
                        current = p;
                }
                reverse(ans.begin(), ans.end());
                for (auto el : ans)
                {
                        if (el == 'L')
                                cout << "R";
                        else if (el == 'R')
                                cout << "L";
                        else if (el == 'U')
                                cout << "D";
                        else
                                cout << "U";
                }
                cout << endl;
        }
        else
        {
                cout << "NO" << endl;
        }
}

//................................

// int

// int

// int

// int
