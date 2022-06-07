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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}
int n;
vector<vector<int>> grid;
int nPaths = 0;
vector<vector<bool>> visited;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int cnt = 0;
//...............................
// i m also counting the unwanted loops where same cell is visited infinite times
void dfs(int r, int c, int last)
{

        cnt++;
        // if (cnt % 10000 == 0)
        if (cnt < 20)
        {
                cout << "cnt = " << cnt << endl;
                cout << "r = " << r << " , c = " << c << endl;
        }
        if (r < 0 || c < 0 || r >= n || c >= n)
                return;
        if (visited[r][c])
                return;
        visited[r][c] = true;
        if (r == n - 1 && c == n - 1)
        {
                nPaths++;
                return;
        }
        for (int i = 0; i < 4; i++)
        {
                if (i != ((last + 2) % 4))
                {
                        dfs(r + dr[i], c + dc[i], i);
                        visited[r + dr[i]][c + dc[i]] = false;
                }
        }
        return;
}
//...............................

void suraj()
{
        n = 2;
        grid = vector<vector<int>>(n, vector<int>(n, 0));
        visited = vector<vector<bool>>(n, vector<bool>(n, false));

        dfs(0, 0, 0); // thirs parameter => last move was a right move
        // so for index 0,0 our we cant move to the left, which does not
        // hurt us in any way.

        cout << "nPaths = " << nPaths << endl;
}

//................................
// int
// int
// int
// int
