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
vector<vector<int>> ab, cd;
//...............................

//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;
        ab = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        cd = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                ab[a][b] = 1;
                ab[b][a] = 1;
        }
        for (int i = 0; i < m; i++)
        {
                int c, d;
                cin >> c >> d;
                cd[c][d] = 1;
                cd[d][c] = 1;
        }

        // cout << "cd[3][2] = " << cd[3][2] << endl;

        vector<int> p;
        for (int i = 1; i <= n; i++)
                p.pb(i);
        // cout << "a" << endl;
        do
        {
                // cout << "p  : ";
                // for (int i : p)
                //         cout << i << " ";
                // cout << endl;
                bool flag = true;
                // cout << "b" << endl;
                for (int i = 1; i <= n; i++)
                {
                        for (int j = 1; j <= n; j++)
                        {
                                if (i == j)
                                        continue;
                                // cout << "i = " << i << "   j = " << j << endl;
                                // cout << "ab[i][j] = " << ab[i][j] << endl;
                                // cout << "p[i-1] = " << p[i - 1] << endl;
                                // cout << "p[j-1] = " << p[j - 1] << endl;
                                // cout << "cd[p[i-1]][p[j-1]] = " << cd[p[i - 1]][p[j - 1]] << endl;
                                // cout << ab[i][j] << " " << cd[p[i - 1]][p[j - 1]] << endl;
                                if (ab[i][j] != cd[p[i - 1]][p[j - 1]])
                                {
                                        flag = false;
                                        break;
                                }
                                else
                                {
                                        flag = true;
                                        // break;
                                }
                        }
                        if (flag == false)
                                break;
                }
                // cout << "hi" << endl;
                if (flag == true)
                {
                        cout << "Yes" << endl;
                        return;
                }
        } while (next_permutation(p.begin(), p.end()));
        cout << "No" << endl;
}

//................................
