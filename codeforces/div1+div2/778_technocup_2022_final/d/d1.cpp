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
const int N = 1000000;
vector<int> vprimes;
#define SIEVE
int primes[N];
vector<int> pr;
void sieve()
{
  for (int i = 2; i < N; i++)
  {
    if (primes[i] == 0) // means if i is a prime
    {
      pr.pb(i);
      for (int j = i * i; j < N; j += i)
        primes[j] = 1;
    }
    primes[i] ^= 1;
    if (primes[i] == 1)
      vprimes.pb(i);
  }
}
signed main()
{
  sieve();
  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

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
map<pair<int, int>, pair<int, int>> ratios;
vector<vector<int>> tree;
vector<bool> visited;
vector<pair<int, int>> val;
map<int, int> primePow;
void bfs(int root)
{
  queue<int> q;
  q.push(root);
  while (!q.empty())
  {
    int top = q.front();
    q.pop();
    for (auto neigh : tree[top])
    {
      if (!visited[neigh])
      {
        visited[neigh] = true;
        q.push(neigh);
        val[neigh].first = ratios[make_pair(neigh, top)].first * val[top].first;
        val[neigh].second = ratios[make_pair(neigh, top)].second * val[top].second;
      }
    }
  }
}

void calcPrimePow(int num)
{
  for (int prime : vprimes)
  {
    int cnt = 0;
    while (num % prime == 0)
    {
      num /= prime;
      cnt++;
    }
    primePow[prime] = cnt;
  }
}
//...............................

void suraj()
{
  cout << vprimes.size() << endl;
  int mod = 998244353;
  return;
  int n;
  cin >> n;

  ratios.clear();
  tree = vector<vector<int>>(n + 1, vector<int>());
  visited = vector<bool>(n + 1, false);
  val = vector<pair<int, int>>(n + 1, make_pair(1, 1));
  primePow.clear();

  for (int i = 0; i < n - 1; i++)
  {
    int a, b, ra, rb;
    cin >> a >> b >> ra >> rb;

    ratios[make_pair(a, b)] = make_pair(ra, rb);
    ratios[make_pair(b, a)] = make_pair(rb, ra);
  }

  val[1] = make_pair(1, 1);

  bfs(1);

  // now we need the lcm of all the denominators of the val[nodes].
  for (int i = 1; i <= n; i++)
  {
    int temp = val[i].second;
    calcPrimePow(temp);
  }
}

//................................

// int

// int

// int

// int
