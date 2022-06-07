// @author: ascyrax

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                     \
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

//...............................

//...............................
//N- 1e5
//v- 1e6
//S- 2000
//k- 1e9

void suraj()
{
    int s, n;
    cin >> s >> n;
    vector<vector<pair<int, int>>> by_weight(s + 1);
    for (int i = 0; i < n; i++)
    {
        int v, w, q;
        cin >> v >> w >> q;
        by_weight[w].pb(make_pair(v, q));
    }

    for (int i = 0; i <= s; i++)
    {
        sort(by_weight[i].rbegin(), by_weight[i].rend());
    }

    vector<vector<ll>> best(s + 1, vector<ll>(s + 1, 0ll));
    //best[i][j] => max value obtained if from the first i weight, objects of total weight of j is chosen
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            best[i][j] = max(best[i][j], best[i - 1][j]); //if no objects with weight i was taken
            ll totW = 0, totV = 0;
            // while (totW <= j)
            // {
            int flag = 0;
            //if objects with weight i were taken
            for (auto vq : by_weight[i])
            {
                ll nvq = vq.second;
                while (nvq--)
                {
                    totW += i;
                    totV += vq.first;
                    if (j - totW >= 0)
                        best[i][j] = max(best[i][j], best[i - 1][j - totW] + totV);
                    else
                    {
                        flag = -1;
                        break;
                    }
                }
                if (flag == -1)
                    break;
            }
            // }
        }
    }
    cout << best[s][s] << endl;
}

//................................
