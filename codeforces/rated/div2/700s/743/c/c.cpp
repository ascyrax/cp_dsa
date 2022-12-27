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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
vector<vector<int>> dag;
vector<bool> discovered;
deque<int> topSort;
vector<deque<int>> vTopSort;
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
        cin >> n;
        dag = vector<vector<int>>(n + 1, vector<int>(0));
        discovered = vector<bool>(n, false);

        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                for (int j = 0; j < x; j++)
                {
                        int book;
                        cin >> book;
                        dag[book].pb(i);
                }
        }
        for (int i = 1; i <= n; i++)
        {
                if (!discovered[i])
                        dfs(i);
                vTopSort.pb(topSort);
        }
        vector<int> index(n + 1);
        for (int i = 0; i < n; i++)
        {
                index[topSort[i]] = i + 1;
        }

        for (int i = 1; i <= n; i++)
        {
                for (int neigh : dag[i])
                {
                        if (index[neigh] <= index[i])
                        {
                                cout << -1 << endl;
                                topSort.clear();
                                vTopSort.clear();
                                return;
                        }
                }
        }
        for (int i : topSort)
                cout << i << " ";
        cout << endl;
        int cnt = 1;
        for (int i = 1; i < (int)topSort.size(); i++)
        {
                if (topSort[i] > topSort[i - 1])
                {
                        //all ok
                        ;
                }
                else
                {
                        cnt++;
                }
        }

        cout << cnt << endl;
        topSort.clear(); //check
        vTopSort.clear();
        cout << "-------------------------" << endl;
}

//................................
