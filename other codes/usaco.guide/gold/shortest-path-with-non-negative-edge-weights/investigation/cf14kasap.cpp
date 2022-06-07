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
//...............................
int n, m;
vector<vector<pair<int, int>>> graph((int)1e5 + 1);
vector<ll> vdistance((int)1e5 + 1, (ll)1e15);
vector<bool> vfrozen((int)1e5 + 1, false);
//...............................
void dijkstra(int node)
{
        vdistance[node] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, node));

        while (!pq.empty())
        {
                auto current = pq.top();
                auto current_node = pq.top().second;
                auto current_dist = abs(pq.top().first);
                // cout << current_node << " " << current_dist << endl;
                pq.pop();

                if (vfrozen[current_node])
                        continue;
                vfrozen[current_node] = true;
                for (auto neigh : graph[current_node])
                {
                        if (vfrozen[neigh.first])
                                continue;
                        // cout << vdistance[neigh.first] << " " << vdistance[current_node] << " " << current_dist << endl;
                        if (vdistance[neigh.first] > vdistance[current_node] + neigh.second)
                        {
                                // cout << "if" << endl;
                                vdistance[neigh.first] = vdistance[current_node] + neigh.second;
                                pq.push(make_pair(-vdistance[neigh.first], neigh.first));
                        }
                }
                // priority_queue<pair<int, int>> copy = pq;
                // while (!copy.empty())
                // {
                //         auto i = copy.top();
                //         copy.pop();
                //         cout << i.first << " " << i.second << "      ";
                // }
                // cout << endl;
        }
        return;
}
//...............................

void suraj()
{
        cin >> n >> m;
        graph.resize(n + 1);
        vdistance.resize(n + 1, (ll)1e15); //1e15 => infinity
        vfrozen.resize(n + 1, false);

        for (int i = 0; i < m; i++)
        {
                int a, b, w;
                cin >> a >> b >> w;
                graph[a].pb(make_pair(b, w));
        }
        dijkstra(1);
        cout << vdistance[n] << endl;
}

//................................
