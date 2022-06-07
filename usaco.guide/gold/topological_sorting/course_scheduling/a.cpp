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
        cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................
vector<vector<int>> dag;
vector<bool> discovered;
deque<int> topSort;
//...............................

void dfs(int node)
{
        if (discovered[node])
                return;
        else
                discovered[node] = true;
        for (int neighNode : dag[node])
        {
                dfs(neighNode);
        }
        topSort.push_front(node);
        return;
}
//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;
        dag = vector<vector<int>>(n, vector<int>(0));
        discovered = vector<bool>(n, false);

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                dag[a - 1].pb(b - 1);
        }

        for (int i = 0; i < n; i++)
        {
                if (!discovered[i])
                        dfs(i);
        }
        vector<int> ind(n);
        for (int i = 0; i < n; i++)
        {
                ind[topSort[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
                for (int neigh : dag[i])
                {
                        if (ind[neigh] <= ind[i])
                        {
                                cout << "IMPOSSIBLE" << endl;
                                return;
                        }
                }
        }
        for (auto i : topSort)
                cout << i + 1 << " ";
        cout << endl;
}

//................................
