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

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        // cin>>t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

int n, m;
map<pair<int, int>, int> dne; // this contains edges that does not exist hence dne.
set<int> unvisited;           // nodes which have not been visited yet.
vector<bool> visited;
int compSize = 1;
vector<int> comps; // contains the sizes of all the components.
//...............................
void dfs(int node)
{
        for (auto loc = unvisited.begin(); loc != unvisited.end(); loc++)
        {
                if (dne[make_pair(node, *loc)] == 1)
                { // ie if the edge between node and *loc dost not exist, skip
                        continue;
                }
                else
                {
                        compSize++;
                        int neigh = *loc;
                        unvisited.erase(loc);
                        dfs(neigh);
                        // loc--; // doesnt work as further recursive dfs also erases some elements.
                        loc = unvisited.upper_bound(neigh);
                }
        }
}
//...............................

void suraj()
{
        cin >> n >> m;

        visited = vector<bool>(n + 1, false);

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                dne[make_pair(a, b)] = 1;
                dne[make_pair(b, a)] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
                unvisited.insert(i);
        }

        for (int i = 1; i <= n; i++)
        {
                auto it = unvisited.find(i);
                if (it != unvisited.end()) // if node i is an unvisited node.
                {
                        compSize = 1;
                        unvisited.erase(it);
                        dfs(i);
                        comps.pb(compSize);
                }
        }
        cout << comps.size() << endl;
        sort(comps.begin(), comps.end());
        for (int el : comps)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
