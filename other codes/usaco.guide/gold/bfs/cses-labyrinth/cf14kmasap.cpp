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
vector<string> grid;
int ansLen = 0;
pair<int, int> start, finish;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1}; //0=>bottom 1=>top 2=>right 3=>left
vector<string> dir = {"D", "U", "R", "L"};          //opposite of what dx and dy suggest
//because we want to travel back from finish to start
vector<vector<string>> eldir;
vector<vector<bool>> visited;
int dist[1001][1001];
vector<vector<pair<int, int>>> parent;
//...............................
queue<pair<int, int>> q;

bool errorfree(int x, int y)
{
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || grid[x][y] == '#' || visited[x][y])
        {
                return false;
        }
        else
                return true;
}

bool bfs()
{
        q.push(start);
        visited[start.first][start.second] = true;
        parent[start.first][start.second] = make_pair(start.first, start.second);
        while (!q.empty())
        {
                // cout << "q.size() = " << q.size() << endl;
                pair<int, int> v = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                        int x = v.first + dx[i];
                        int y = v.second + dy[i];
                        if (errorfree(x, y))
                        {
                                dist[x][y] = dist[v.first][v.second] + 1;
                                eldir[x][y] = dir[i];
                                parent[x][y] = make_pair(v.first, v.second);
                                if (make_pair(x, y) == finish)
                                {
                                        return true;
                                }
                                q.push(make_pair(x, y));
                                visited[x][y] = true;
                        }
                }
        }
        return false;
}

void suraj()
{
        cin >> n >> m;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        eldir = vector<vector<string>>(n, vector<string>(m));
        parent = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
        for (int i = 0; i < n; i++)
        {
                string ts;
                cin >> ts;
                for (int j = 0; j < m; j++)
                {
                        if (ts[j] == 'A')
                        {
                                start = make_pair(i, j);
                        }
                        else if (ts[j] == 'B')
                        {
                                finish = make_pair(i, j);
                        }
                }
                grid.pb(ts);
        }
        if (bfs())
        {
                cout << "YES" << endl;
                vector<string> ans;
                int x = finish.first;
                int y = finish.second;
                cout << dist[x][y] << endl;
                // for (int i = 0; i < n; i++)
                // {
                //         for (int j = 0; j < m; j++)
                //         {
                //                 cout << eldir[i][j] << " ";
                //         }
                //         cout << endl;
                // }
                // int cnt = 0;
                // for (int i = 0; i < n; i++)
                // {
                //         for (int j = 0; j < m; j++)
                //         {
                //                 cout << parent[i][j].first << parent[i][j].second << " ";
                //         }
                //         cout << endl;
                // }
                while (make_pair(x, y) != start)
                {
                        // cnt++;
                        // if (cnt == 40)
                        //         break;
                        // cout << "eldir[x][y] = " << eldir[x][y] << endl;
                        // cout << x << " " << y << endl;
                        ans.pb(eldir[x][y]);
                        x = parent[x][y].first;
                        y = parent[x][y].second;

                        // cout << x << " " << y << endl;
                }
                reverse(ans.begin(), ans.end());
                for (string s : ans)
                        cout << s;
                cout << endl;
        }
        else
                cout << "NO" << endl;
}

//................................
// #include <bits/stdc++.h>

// using namespace std;

// #define ii pair<int, int>
// #define f first
// #define s second
// #define mp make_pair

// int n, m;
// char A[1000][1000];
// bool vis[1000][1000];

// // previousStep stores the previous direction that we moved in to arrive that this cell
// int previousStep[1000][1000];

// // 0 = up, 1 = right, 2 = down, 3 = left
// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};
// string stepDir = "URDL";

// int main()
// {
//         cin >> n >> m;

//         queue<ii> q;
//         ii begin, end;
//         for (int i = 0; i < n; i++)
//         {
//                 for (int j = 0; j < m; j++)
//                 {
//                         cin >> A[i][j];
//                         if (A[i][j] == 'A')
//                         {
//                                 begin = mp(i, j);
//                         }
//                         else if (A[i][j] == 'B')
//                         {
//                                 end = mp(i, j);
//                         }
//                 }
//         }

//         q.push(begin);
//         vis[begin.f][begin.s] = true;

//         while (!q.empty())
//         {
//                 ii u = q.front();
//                 q.pop();
//                 for (int i = 0; i < 4; i++)
//                 {
//                         ii v = mp(u.f + dx[i], u.s + dy[i]);
//                         if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m)
//                                 continue;
//                         if (A[v.f][v.s] == '#')
//                                 continue;
//                         if (vis[v.f][v.s])
//                                 continue;
//                         vis[v.f][v.s] = true;
//                         previousStep[v.f][v.s] = i;
//                         q.push(v);
//                 }
//         }

//         if (vis[end.f][end.s])
//         {
//                 cout << "YES" << endl;
//                 vector<int> steps;
//                 while (end != begin)
//                 {
//                         int p = previousStep[end.f][end.s];
//                         steps.push_back(p);
//                         // undo the previous step to get back to the previous square
//                         // Notice how we subtract dx/dy, whereas we added dx/dy before
//                         end = mp(end.f - dx[p], end.s - dy[p]);
//                 }
//                 reverse(steps.begin(), steps.end());

//                 cout << steps.size() << endl;
//                 for (char c : steps)
//                 {
//                         cout << stepDir[c];
//                 }
//                 cout << endl;
//         }
//         else
//         {
//                 cout << "NO" << endl;
//         }

//         return 0;
// }