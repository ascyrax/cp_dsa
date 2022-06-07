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

//...............................

//...............................

void suraj()
{
        ll n, m, q;
        cin >> n >> m >> q;
        vector<vector<ll>> free(n + 1, vector<ll>(m + 1, true));

        // count the no of stairs before any queries
        ll stairs = 0;
        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= m; j++)
                {
                        if (i == 1)
                        { // for right down
                                for (ll k = 1;; k++)
                                {
                                        // cout << "if a" << endl;
                                        // right down
                                        ll nx = i + k / 2;
                                        ll ny = j + (k + 1) / 2;
                                        if (nx > n || ny > m)
                                        {
                                                // k--;
                                                stairs += ((k - 1) * ((k - 1) + 1)) / 2;
                                                break;
                                        }
                                }
                        }
                        if (j == 1)
                        { // for down right
                                for (ll k = 1;; k++)
                                {
                                        // cout << "if b" << endl;
                                        // down right
                                        ll nx = i + (k + 1) / 2;
                                        ll ny = j + k / 2;
                                        if (nx > n || ny > m)
                                        {
                                                // k--;
                                                stairs += ((k - 1) * ((k - 1) + 1)) / 2;
                                                break;
                                        }
                                }
                        }
                }
        }
        // adding the stairs of length 1
        stairs += n * m;
        // now we gotta deal with the queries
        ll currStairs = stairs; // since initially all positions are free
        // cout << "stairs = " << stairs << endl;
        for (ll i = 0; i < q; i++)
        {
                ll x, y;
                cin >> x >> y;
                free[x][y] = !free[x][y];
                ll rd = 0;
                // right down
                for (rd = 1;; rd++)
                {
                        ll nx = x + (rd) / 2;
                        ll ny = y + (rd + 1) / 2;
                        if (nx > n || ny > m || !free[nx][ny])
                                break;
                }
                // top left
                ll tl = 0;
                for (tl = 1;; tl++)
                {
                        ll nx = x - (tl + 1) / 2;
                        ll ny = y - tl / 2;
                        if (nx < 1 || ny < 1 || !free[nx][ny])
                                break;
                }
                // down right
                ll dr = 0;
                for (dr = 1;; dr++)
                {
                        ll nx = x + (dr + 1) / 2;
                        ll ny = y + dr / 2;
                        if (nx > n || ny > m || !free[nx][ny])
                                break;
                }
                // left top
                ll lt = 0;
                for (lt = 1;; lt++)
                {
                        ll nx = x - (lt) / 2;
                        ll ny = y - (lt + 1) / 2;
                        if (nx < 1 || ny < 1 || !free[nx][ny])
                                break;
                }
                // cout << rd << " " << tl << " " << dr << " " << lt << endl;
                rd--;
                tl--;
                dr--;
                lt--;
                // if x,y is not free then currStairs-=all the stairs passing through x,y
                if (!free[x][y])
                {
                        currStairs -= ((rd + tl + rd * tl) + (dr + lt + dr * lt) + 1);
                }
                // if x,y becomes free after the query then currStairs+= all the stairs passing through x,y
                else
                {
                        currStairs += ((rd + tl + rd * tl) + (dr + lt + dr * lt) + 1);
                }
                cout << currStairs << endl;
                // cout << "-------------------------" << endl;
        }
}

//................................
