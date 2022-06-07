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
        //ioss
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
const ll llinf = 9223372036854775807;
const ll llninf = -9223372036854775807 - 1;
//...............................
ll graph[501][501];
//...............................

//...............................

void suraj()
{
        ioss ll n, m, q;
        cin >> n >> m >> q;

        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= n; j++)
                {
                        if (i != j)
                        {
                                graph[i][j] = llinf;
                                graph[j][i] = llinf;
                        }
                }
        }
        for (ll i = 0; i < m; i++)
        {
                ll a, b, c;
                cin >> a >> b >> c;
                graph[a][b] = min(graph[a][b], c);
                graph[b][a] = min(graph[b][a], c);
        }
        // for (ll i = 1; i <= n; i++)
        // {
        //         for (ll j = 1; j <= n; ++j)
        //         {
        //                 cout << graph[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        for (ll k = 1; k <= n; k++)
        {
                for (ll i = 1; i <= n; i++)
                {
                        for (ll j = 1; j <= n; j++)
                        {
                                if (graph[i][k] != llinf && graph[k][j] != llinf)
                                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                }
        }
        // for (ll i = 1; i <= n; i++)
        // {
        //         for (ll j = 1; j <= n; ++j)
        //         {
        //                 cout << graph[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        for (ll i = 0; i < q; i++)
        {
                ll a, b;
                cin >> a >> b;
                if (graph[a][b] == llinf)
                        cout << -1 << endl;
                else
                        cout << graph[a][b] << endl;
        }
}

//................................
