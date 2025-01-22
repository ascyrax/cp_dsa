// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  ioss

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

//...............................

//...............................

void suraj()
{
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> graph(n, vector<int>());
  vector<bool> frozen(n, false);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  queue<int> que;
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
      b--;
      if (!frozen[b])
      {
        frozen[b] = true;
        que.push(b);
      }
    }
    else if (a == 2)
    {
      // run the bfs b times.
      while (b--)
      {
        queue<int> nextQue;
        while (!que.empty())
        {
          int front = que.front();
          que.pop();
          for (int neigh : graph[front])
          {
            if (!frozen[neigh])
            {
              frozen[neigh] = true;
              nextQue.push(neigh);
            }
          }
        }
        que = nextQue;
        if (que.empty())
          break;
      }
    }
    else if (a == 3)
    {
      b--;
      if (frozen[b])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}

//................................

// int

// int

// int

// int
