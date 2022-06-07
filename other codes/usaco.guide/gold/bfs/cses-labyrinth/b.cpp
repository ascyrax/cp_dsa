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
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
vector<string> lab;
pair<int, int> a, b;
vector<vector<bool>> visited;
// right down left up
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<pair<int, int>>> parent;
int distAB = -1;
//...............................
bool check(pair<int, int> newCord)
{
        int x = newCord.first, y = newCord.second;
        if (x >= 0 && x < n && y >= 0 && y < m && (lab[x][y] == '.' || lab[x][y] == 'B'))
                return true;
        else
                return false;
}
void bfs(pair<int, int> a)
{
        queue<pair<pair<int, int>, int>> q; //((x,y),dist)
        q.push(make_pair(a, 0));
        // cout << q.front().first.first << " " << q.front().first.second << " " << q.front().second << endl;
        while (!q.empty())
        {
                auto curr = q.front();
                q.pop();
                auto currCord = curr.first;
                auto currDist = curr.second;
                // cout << currCord.first << " " << currCord.second << endl;
                visited[currCord.first][currCord.second] = true;
                // cout << "before for 4" << endl;
                for (int i = 0; i < 4; i++)
                {
                        // cout << "q.size = " << q.size() << endl;
                        auto newCord = make_pair(currCord.first + dx[i], currCord.second + dy[i]);
                        if (check(newCord) && !visited[newCord.first][newCord.second])
                        {
                                // cout << newCord.first << " " << newCord.second << endl;
                                if (parent[newCord.first][newCord.second] == make_pair(-1, -1))
                                        parent[newCord.first][newCord.second] = currCord;

                                q.push(make_pair(newCord, currDist + 1));
                                if (newCord == b)
                                {
                                        distAB = currDist + 1;
                                        return;
                                }
                                visited[newCord.first][newCord.second] = true;
                        }
                }
                // cout << "hello" << endl;
        }
        return;
}
//...............................

void suraj()
{
        cin >> n >> m;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        parent = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
        for (int i = 0; i < n; i++)
        {
                string row;
                cin >> row;
                lab.pb(row);
                for (int j = 0; j < m; j++)
                {
                        if (row[j] == 'A')
                                a = make_pair(i, j);
                        else if (row[j] == 'B')
                                b = make_pair(i, j);
                }
        }
        bfs(a);
        if (distAB == -1)
                cout << "NO" << endl;
        else
        {
                cout << "YES" << endl;
                cout << distAB << endl;
                vector<string> ans;
                auto i = b;
                for (i = b; i != a; i = parent[i.first][i.second])
                {
                        auto par = parent[i.first][i.second];
                        int parX = par.first;
                        int parY = par.second;
                        int iX = i.first;
                        int iY = i.second;
                        // cout << parX << " " << parY << endl;
                        if (iX == parX)
                        {
                                if (iY < parY)
                                        ans.pb("L");
                                else
                                        ans.pb("R");
                        }
                        else
                        {
                                if (iX < parX)
                                        ans.pb("U");
                                else
                                        ans.pb("D");
                        }
                }
                reverse(ans.begin(), ans.end());
                for (string s : ans)
                        cout << s;
                cout << endl;
        }
}

//................................
