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
int r, c;
queue<pair<int, int>> q;
vector<string> grid;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int cnt = 0;
int ans = 0;
//...............................
void bfs()
{
        cout << "cnt = " << cnt << endl;
        while (!q.empty())
        {

                pair<int, int> front = q.front();
                q.pop();
                if (front == make_pair(-1, -1))
                {
                        cout << "front = " << front.first << " " << front.second << endl;
                        ans++;
                        if (q.empty())
                        {
                                return;
                        }
                        front = q.front();
                        q.pop();
                        q.push(make_pair(-1, -1));
                }
                cout << "front = " << front.first << " " << front.second << endl;
                for (int i = 0; i < 4; i++)
                {
                        int rnew = front.first + dr[i];
                        int cnew = front.second + dc[i];

                        cout << "rnew = " << rnew << ", cnew = " << cnew << endl;
                        if (rnew < 0 || cnew < 0 || rnew >= r || cnew >= c || grid[rnew][cnew] == '#')
                        {
                                cout << "if" << endl;
                                continue;
                        }
                        else
                        {
                                cout << "else " << endl;
                                cnt--;
                                q.push(make_pair(rnew, cnew));
                        }
                        if (cnt == 0)
                                return;
                        else
                        {
                                cout << "cnt = " << cnt << endl;
                        }
                }
        }
}
//...............................

void suraj()
{
        cin >> r >> c;

        cnt = r * c;

        grid = vector<string>(r, "");

        for (string &s : grid)
                cin >> s;

        if (r == 1 && c == 1)
        {
                cout << 0 << endl;
                return;
        }

        for (int i = 0; i < r; i++)
        {
                for (int j = 0; j < c; j++)
                {
                        if (grid[i][j] == '#')
                        {
                                cout << "i = " << i << "  ,  j = " << j << endl;
                                cnt--;
                                q.push(make_pair(i, j));
                        }
                }
        }
        ans = 1;
        q.push(make_pair(-1, -1));

        bfs();

        cout << ans << endl;
}

//................................
// int
// int
// int
// int
