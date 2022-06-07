#include <iostream>
#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> ans;
int dist = 0;

int bfs(int node)
{

        queue<pair<int, int>> q;
        visited = vector<bool>(n + 1, false);

        q.push(make_pair(v, 0));
        visited[v] = true;

        while (!q.empty())
        {
                for (int neigh : graph[q.front().first])
                {
                        if (neigh == node)
                        {
                                return q.front().second + 1;
                        }
                        if (!visited[neigh])
                        {
                                visited[neigh] = true;
                                q.push(make_pair(neigh, q.front().second + 1));
                        }
                }
                q.pop();
        }
        return -1;
}

int main()
{
        cin >> n >> m >> v;
        graph = vector<vector<int>>(n + 1, vector<int>());

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
        }

        for (int i = 1; i <= n; i++)
        {
                dist = 0;
                if (i == v)
                {
                        ans.pb(0);
                        continue;
                }
                else
                        ans.pb(bfs(i));
        }
        for (int i : ans)
        {
                cout << i << " ";
        }
        cout << endl;

        return 0;
}