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

        ioss

            // startTime=(double)clock();

            //     freopen("shell.in", "r", stdin);
            // freopen("shell.out", "w", stdout);

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

ll n, m;
vector<vector<pair<ll, ll>>> dg;
vector<ll> dist;
using T = pair<ll, int>;
priority_queue<T, vector<T>, greater<T>> q;
//...............................
void dijkstra()
{
        dist = vector<ll>(n, LLONG_MAX);
        dist[0] = 0;
        q.push(make_pair(0, 0));

        while (q.size())
        {
                pair<ll, ll> top = q.top();
                q.pop();

                // cout << top.first << " " << dist[top.second] << endl;

                if (top.first > dist[top.second])
                        continue;

                for (auto neigh : dg[top.second])
                {
                        if (dist[top.second] + neigh.first < dist[neigh.second])
                        {
                                dist[neigh.second] = dist[top.second] + neigh.first;
                                neigh.first = dist[neigh.second];
                                q.push(neigh);
                        }
                }
        }
}
//...............................

void suraj()
{
        // cout << "gct: " << gct() << endl;

        cin >> n >> m;

        dg = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>());

        for (ll i = 0; i < m; i++)
        {
                ll a, b, c;
                cin >> a >> b >> c;

                dg[a - 1].pb(make_pair(c, b - 1)); // {weight,target node}
        }

        // for (int i = 1; i <= n; i++)
        // {
        //         sort(dg[i].begin(), dg[i].end());
        // }

        // cout << "gct: " << gct() << endl;

        dijkstra();

        // cout << "gct: " << gct() << endl;

        for (int i = 0; i < n; i++)
                cout << dist[i] << " ";
        cout << endl;
}

//................................

// ll

// int

// int

// int
