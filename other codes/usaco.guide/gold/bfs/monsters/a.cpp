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
        // ioss
        cout
            << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

int n, m;
vector<string> lab;
// vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0}; //R D L U
string sdir = "RDLU";
vector<vector<int>> vMonsReach, vReach;
pair<int, int> start, finish;
vector<vector<int>> dir; //for reaching the sqaure x,y what move was done among R,D,L AND U.
//...............................
bool check(int x, int y)
{
        if (x < 0 || x >= n || y < 0 || y >= m || lab[x][y] == '#' || lab[x][y] == 'M')
        {
                return false;
        }
        else
                return true;
}
bool check2(int x, int y)
{
        if (x < 0 || x >= n || y < 0 || y >= m || lab[x][y] == '#' || lab[x][y] == 'M' || vMonsReach[x][y] <= vReach[x][y])
        {
                return false;
        }
        else
                return true;
}
// void bfs(pair<int, int> startNode)
void bfs()
{

        // visited = vector<vector<bool>>(n, vector<bool>(m, false));
        // q.push(startNode);
        // visited[startNode.first][startNode.second] = true;

        while (!q.empty())
        {
                // cout << "a" << endl;
                pair<int, int> v = q.front();
                vMonsReach[v.first][v.second] = 0;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                        int x = v.first + dx[i];
                        int y = v.second + dy[i];
                        if (check(x, y))
                        {
                                // visited[x][y] = true;
                                vMonsReach[x][y] = min(vMonsReach[x][y], vMonsReach[v.first][v.second] + 1);
                                q.push(make_pair(x, y));
                        }
                }
        }
        return;
}

bool bfsFinal(pair<int, int> startNode)
{
        if (startNode.first == 0 || startNode.first == n - 1 || startNode.second == 0 || startNode.second == m - 1)
        {
                return true;
        }
        // vReach[startNode.first][startNode.second] = 0;
        // visited = vector<vector<bool>>(n, vector<bool>(m, false));
        vReach[startNode.first][startNode.second] = 0;
        q.push(startNode);
        // visited[startNode.first][startNode.second] = true;
        while (!q.empty())
        {
                // cout << "b" << endl;
                pair<int, int> v = q.front();

                q.pop();
                for (int i = 0; i < 4; i++)
                {
                        int x = v.first + dx[i];
                        int y = v.second + dy[i];
                        vReach[x][y] = min(vReach[x][y], vReach[v.first][v.second] + 1);
                        if (check2(x, y))
                        {
                                // cout << "if " << x << " " << y << endl;
                                dir[x][y] = i;
                                // visited[x][y] = true;
                                q.push(make_pair(x, y));
                                if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                                {
                                        finish = make_pair(x, y);
                                        return true;
                                }
                        }
                        // else
                        // {
                        //         cout << "else " << x << " " << y << endl;
                        // }
                }
        }
        return false;
}

void suraj()
{

        cin >> n >> m;
        vMonsReach = vector<vector<int>>(n, vector<int>(m, mod));
        vReach = vector<vector<int>>(n, vector<int>(m, mod));
        dir = vector<vector<int>>(n, vector<int>(m, -1));
        vector<pair<int, int>> vmonsters;
        for (int i = 0; i < n; i++)
        {
                string ts;
                cin >> ts;
                lab.pb(ts);
                for (int j = 0; j < m; j++)
                {
                        if (ts[j] == 'M')
                        {
                                vmonsters.pb(make_pair(i, j));
                                vMonsReach[i][j] = 0;
                        }
                        else if (ts[j] == 'A')
                        {
                                vReach[i][j] = 0;
                                start = make_pair(i, j);
                        }
                }
        }
        // cout << vmonsters.size() << endl;
        // if (vmonsters.size() > 0)
        for (auto monster : vmonsters)
        {
                // cout << monster.first << " " << monster.second << endl;
                // cout << "Hi" << endl;
                // bfs(monster);
                q.push(monster);
        }
        // cout << "hello" << endl;

        if (bfsFinal(start))
        {
                // cout << start.first << " " << start.second << endl;
                // cout << finish.first << " " << finish.second << endl;
                cout << "YES" << endl;
                if (vReach[finish.first][finish.second] == mod)
                {
                        cout << 0 << endl;
                        return;
                }
                cout << vReach[finish.first][finish.second] << endl;
                int x = finish.first;
                int y = finish.second;
                vector<char> ans;
                // cout << "dir[1][1] = " << dir[1][1] << endl;
                while (make_pair(x, y) != start)
                {
                        // cout << x << " " << y << endl;
                        ans.pb(sdir[dir[x][y]]);
                        int temp = x - dx[dir[x][y]];

                        y = y - dy[dir[x][y]];
                        x = temp;
                        // cout << "changed" << endl;
                        // cout << temp << " " << x << " " << y << endl;
                        // cout << x << " " << y << endl;
                        // for (char c : ans)
                        //         cout << c;
                        // cout << endl;
                }
                reverse(ans.begin(), ans.end());
                for (char c : ans)
                        cout << c;
                cout << endl;
        }
        else
        {
                cout << "NO" << endl;
        }
}

//................................
