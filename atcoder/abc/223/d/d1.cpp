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

//...............................

//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dag(n, vector<int>());
        vector<int> indeg(n, 0);
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                dag[a - 1].pb(b - 1);
                indeg[b - 1]++;
        }

        priority_queue<int, vector<int>, greater<int>> zeroIndeg;
        for (int i = 0; i < n; i++)
        {
                if (indeg[i] == 0)
                {
                        zeroIndeg.push(i);
                }
        }
        vector<int> topSort;
        while (1)
        {
                if (zeroIndeg.size() == 0)
                        break;
                int smallest = zeroIndeg.top();
                topSort.push_back(smallest);
                zeroIndeg.pop();
                for (int neigh : dag[smallest])
                {
                        indeg[neigh]--;
                        if (indeg[neigh] == 0)
                                zeroIndeg.push(neigh);
                }
        }
        for (int i = 0; i < n; i++)
        {
                if (indeg[i] > 0)
                {
                        cout << -1 << endl;
                        return;
                }
        }
        for (int i : topSort)
                cout << i + 1 << " ";
        cout << endl;
}

//................................
// int
// int
// int
// int
