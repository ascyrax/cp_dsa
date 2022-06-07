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

        // cout << vectorprecision(15) << fixed;

        int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
vector<vector<int>> g;
vector<set<int>> g2;

vector<bool> visited, bfsvisit;
int cnt = 1;
// int lo = 1e9, hi = 0;
vector<int> vdfs;
int dfsno = 0;
void dfs(int node)
{
        for (auto neigh : g[node])
        {
                if (!visited[neigh])
                {
                        // lo = min(lo, neigh);
                        // hi = max(hi, neigh);
                        // cnt++;
                        vdfs[neigh] = dfsno;
                        visited[neigh] = true;
                        dfs(neigh);
                }
        }
        return;
}
vector<int> vdist;
// void dfs2(int node, int dist)
// {
//         for (auto neigh : g2[node])
//         {
//                 if (!bfsvisit[neigh])
//                 {
//                         vdist[neigh] = dist + 1;
//                         bfsvisit[neigh] = true;
//                         dfs2(neigh, dist + 1);
//                 }
//         }
// }
queue<pair<int, int>> q;
void bfs()
{
        // cout << "bfs" << endl;
        // q.push(make_pair(0, 0));
        // vdist[0] = 0;
        // bfsvisit[0] = true;
        while (!q.empty())
        {
                pair<int, int> top = q.front();
                q.pop();
                // cout << "hi" << endl;
                // cout << g2[top.first].size() << endl;
                // if (g2[top.first].size() > 0)
                for (auto neigh : g2[top.first])
                {
                        // cout << "neigh = " << neigh << endl;
                        if (!bfsvisit[neigh])
                        {
                                bfsvisit[neigh] = true;
                                vdist[neigh] = min(vdist[neigh], vdist[top.first] + 1);
                                q.push(make_pair(neigh, vdist[neigh]));
                        }
                }
        }
        return;
}
int nNodes = 0;
void dfs2(int node)
{
        for (auto neigh : g2[node])
        {
                if (!bfsvisit[neigh])
                {
                        bfsvisit[neigh] = true;
                        nNodes++;
                        dfs2(neigh);
                }
        }
        return;
}
//...............................

void suraj()
{
        cnt = 1;
        dfsno = 0;
        nNodes = 0;
        int n, m;
        cin >> n >> m;
        visited = vector<bool>(n, false);
        g = vector<vector<int>>(n, vector<int>());

        vdfs = vector<int>(n, -1);

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                g[a].pb(b);
                g[b].pb(a);
        }

        int ans = n - 1;

        dfsno = 0;

        for (int i = 0; i < n; i++)
        {
                if (!visited[i])
                {
                        dfsno++;
                        // cnt = 1;
                        // lo = i;
                        visited[i] = true;
                        vdfs[i] = dfsno;
                        dfs(i);
                        // ans -= (cnt - 1);
                }
        }

        // cout << "dfsno = " << dfsno << endl;
        // for (int i = 0; i < vdfs.size(); i++)
        //         cout << vdfs[i] << " ";
        // cout << endl;

        g2 = vector<set<int>>(dfsno + 1, set<int>());
        bfsvisit = vector<bool>(dfsno + 1, false);
        vdist = vector<int>(dfsno + 1, 1e9);
        map<pair<int, int>, int> m2;
        for (int i = 1; i < n; i++)
        {
                // cout << "i = " << i << endl;
                // cout << vdfs[i - 1] << " " << vdfs[i] << endl;
                if (vdfs[i] == vdfs[i - 1])
                        continue;
                // if (m2.count(make_pair(vdfs[i], vdfs[i - 1])) == 0 && m2.count(make_pair(vdfs[i - 1], vdfs[i])) == 0)
                // {
                g2[vdfs[i]].insert(vdfs[i - 1]);
                g2[vdfs[i - 1]].insert(vdfs[i]);
                // m2[make_pair(vdfs[i], vdfs[i - 1])]++;
                // m2[make_pair(vdfs[i - 1], vdfs[i])]++;
                // }
        }
        // cout << "Hi" << endl;

        // for (auto el : g2)
        // {
        //         for (int i : el)
        //                 cout << i << " ";
        //         cout << endl;
        // }

        // int dist = 0;
        // bfs();
        int first = vdfs[0];    // = 1.
        int last = vdfs[n - 1]; // = range[1,dfsno]
        // shortest dist between the first and the last node.
        if (first == last)
        {
                cout << 0 << endl;
                return;
        }
        // bfsvisit[1] = true;
        // nNodes++;
        // dfs2(1);
        // cout << nNodes - 1 << endl;
        // cout << vdist[dfsno] << endl;
        q.push(make_pair(first, 0));
        bfsvisit[1] = true;
        vdist[1] = 0;
        bfs();
        cout << vdist[last] << endl;
}

//................................

// int

// int

// int

// int
