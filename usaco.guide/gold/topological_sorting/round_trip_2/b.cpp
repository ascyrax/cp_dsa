// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// bool visited[(int)1e5 + 5], on_stack[(int)1e5 + 5];
// vector<int> adj[(int)1e5 + 5];
// vector<int> cycle;
// int N, M;
// bool dfs(int n)
// {
//         cout << "dfs " << n << endl;
//         visited[n] = on_stack[n] = true;
//         for (int u : adj[n])
//         {
//                 cout << "u = " << u << endl;
//                 for (int i = 0; i < 5; i++)
//                 {
//                         cout << visited[i] << " ";
//                 }
//                 cout << endl;
//                 for (int i = 0; i < 5; i++)
//                 {
//                         cout << on_stack[i] << " ";
//                 }
//                 cout << endl;
//                 for (int i : cycle)
//                         cout << i << " ";
//                 cout << endl;
//                 if (on_stack[u])
//                 {
//                         cycle.push_back(n); // start cycle
//                         on_stack[n] = on_stack[u] = false;
//                         return true;
//                 }
//                 else if (!visited[u])
//                 {
//                         if (dfs(u))
//                         { // continue cycle
//                                 if (on_stack[n])
//                                 {
//                                         cycle.push_back(n);
//                                         on_stack[n] = false;
//                                         return true;
//                                 }
//                                 else
//                                 { // found u again
//                                         cycle.push_back(n);
//                                         return false;
//                                 }
//                         }
//                         if (!cycle.empty()) // finished with cycle
//                                 return false;
//                 }
//         }
//         on_stack[n] = false;
//         return false;
// }
// int main()
// {
//         // take input, etc
//         cin >> N >> M;
//         for (int i = 0; i < M; i++)
//         {
//                 int a, b;
//                 cin >> a >> b;
//                 adj[a].push_back(b);
//         }
//         for (int i = 1; cycle.empty() && i <= N; i++)
//         {
//                 dfs(i);
//         }
//         if (cycle.empty())
//                 cout << "IMPOSSIBLE";
//         else
//         {
//                 reverse(cycle.begin(), cycle.end());
//                 cout << cycle.size() + 1 << "\n";
//                 for (int n : cycle)
//                         cout << n << " ";
//                 cout << cycle.at(0);
//         }
// }
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
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, m;
//...............................

//...............................

void suraj()
{
        cin >> n >> m;
}

//................................
