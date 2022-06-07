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
        // ioss
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
int n;
vector<string> grid;
//right down left top
int dR[4] = {0, 1, 0, -1};
int dC[4] = {1, 0, -1, 0};
vector<vector<bool>> visited;
set<char> chars;
vector<pair<pair<int, int>, pair<int, int>>> pcls;
int nComponents = 1;
int ans = 0;
char a, b;
void flood_fill2(int r1, int c1, int r2, int c2, int R, int C);
void flood_fill(int r1, int c1, int r2, int c2, int R, int C);

//...............................
void flood_fill2(int r1, int c1, int r2, int c2, int R, int C)
{
        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                cout << "2 flood fill" << endl;
        if (R < r1 || R > r2 || C < c1 || C > c2)
        {
                return;
        }
        if (visited[R][C])
                return;
        visited[R][C] = true;
        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                cout << visited[i][j] << " ";
                        }
                        cout << endl;
                }
        chars.insert(grid[R][C]);
        if (grid[R][C] != a && grid[R][C] != b)
        {
                nComponents = 100;
                return;
        }
        else if (grid[R][C] == a)
        {
                flood_fill(r1, c1, r2, c2, R, C);
                return;
        }
        else if (grid[R][C] == b)
                for (int i = 0; i < 4; i++)
                {
                        int newR = R + dR[i];
                        int newC = C + dC[i];
                        flood_fill2(r1, c1, r2, c2, newR, newC);
                }
        return;
}
void flood_fill(int r1, int c1, int r2, int c2, int R, int C)
{
        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                cout << "flood_fill " << R << " " << C << endl;
        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
        if (R < r1 || R > r2 || C < c1 || C > c2)
        {
                return;
        }
        if (visited[R][C])
                return;

        chars.insert(grid[R][C]);
        if (grid[R][C] == a)
        {
                if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                        cout << "flood if" << endl;
                visited[R][C] = true;
                if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                        for (int i = 0; i < n; i++)
                        {
                                for (int j = 0; j < n; j++)
                                {
                                        cout << visited[i][j] << " ";
                                }
                                cout << endl;
                        }
                for (int i = 0; i < 4; i++)
                {
                        int newR = R + dR[i];
                        int newC = C + dC[i];
                        flood_fill(r1, c1, r2, c2, newR, newC);
                }
        }
        else
        {
                b = grid[R][C];
                if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                {
                        cout << a << " " << b << endl;
                        cout << "flood else" << endl;
                }
                nComponents++;
                flood_fill2(r1, c1, r2, c2, R, C);
                return;
        }
        return;
}
//...............................

void suraj()
{
        cin >> n;

        visited = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
                string x;
                cin >> x;
                grid.pb(x);
        }

        for (int r1 = 0; r1 < n; r1++)
        {
                for (int c1 = 0; c1 < n; c1++)
                {
                        for (int r2 = 0; r2 < n; r2++)
                        {
                                for (int c2 = 0; c2 < n; c2++)
                                {
                                        a = grid[r1][c1]; ///////////
                                        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                                                cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
                                        nComponents = 1;                    ///////////////////
                                        flood_fill(r1, c1, r2, c2, r1, c1); ///////////////
                                        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                                                cout << chars.size() << " " << nComponents << endl;
                                        if (chars.size() == 2 && nComponents == 3) ///////
                                        {                                          ////////
                                                if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                                                        cout << "if" << endl;
                                                pcls.pb(make_pair(make_pair(r1, c1), make_pair(r2, c2))); //////////////
                                        }                                                                 /////////
                                        else if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                                                cout << "else" << endl;
                                        chars.clear();                                             /////////
                                        visited = vector<vector<bool>>(n, vector<bool>(n, false)); ///////////
                                        if (r1 == 0 && c1 == 0 && r2 == 3 && c2 == 2)
                                                cout << "---------" << endl;
                                }
                        }
                }
        }
        for (auto i : pcls)
                cout << i.first.first << " " << i.first.second << "             " << i.second.first << " " << i.second.second << endl;

        for (int i = 0; i < (int)pcls.size(); i++)
        {
                for (int j = 0; j < pcls.size(); j++)
                {
                        if (i != j)
                        {
                                int ir1 = pcls[i].first.first;
                                int ic1 = pcls[i].first.second;
                                int ir2 = pcls[i].second.first;
                                int ic2 = pcls[i].second.second;
                                int jr1 = pcls[j].first.first;
                                int jc1 = pcls[j].first.second;
                                int jr2 = pcls[j].second.first;
                                int jc2 = pcls[j].second.second;
                                if (ir1 >= jr1 && ir2 <= jr2 && ic1 >= jc1 && ic2 <= jc2)
                                {
                                        continue;
                                }
                                else
                                {
                                        ans++;
                                }
                        }
                }
        }
        cout << ans << endl;
}

//................................
