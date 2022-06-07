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
        startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
vector<string> grid;
vector<vector<bool>> visited;
int row, col;
int ans = 0;
//...............................
void dfs(int r, int c, int dist)
{
        // cout << "before if" << endl;
        // cout << "r = " << r << " c = " << c << " dist = " << dist << endl;

        if (r >= row || r < 0 || c < 0 || c >= col)
        {
                // cout << "else if" << endl;
                return;
        }
        else if (grid[r][c] == '#' || visited[r][c] == true)
        {
                // cout << "if" << endl;
                return;
        }
        // cout << "after if" << endl;
        // cout << "r = " << r << " c = " << c << " dist = " << dist << endl;

        ans = max(ans, dist);

        visited[r][c] = true;
        // cout << "first" << endl;
        // cout << "r = " << r << " c = " << c << " dist = " << dist << endl;
        dfs(r + 1, c, dist + 1);

        // cout << "second" << endl;
        // cout << "r = " << r << " c = " << c << " dist = " << dist << endl;
        dfs(r, c + 1, dist + 1);

        return;
}
//...............................

void suraj()
{
        cin >> row >> col;
        grid = vector<string>(row);
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++)
        {
                cin >> grid[i];
        }
        dfs(0, 0, 1);
        cout << ans << endl;
}

//................................
