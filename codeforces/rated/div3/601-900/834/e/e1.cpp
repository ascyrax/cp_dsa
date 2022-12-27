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

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................
int aliveAnts(int a, int b, int c, vector<int> ants, int h)
{
  sort(ants.begin(), ants.end());
  h *= a;
  vector<int> temp1;
  for (int i : ants)
  {
    if (i < h)
      h += i / 2;
    else
      temp1.pb(i);
  }
  h *= b;
  vector<int> temp2;
  sort(temp1.begin(), temp1.end());
  for (int i : temp1)
  {
    if (i < h)
      h += i / 2;
    else
      temp2.pb(i);
  }

  h *= c;
  vector<int> temp3;
  sort(temp2.begin(), temp2.end());
  for (int i : temp2)
  {
    if (i < h)
      h += i / 2;
    else
      temp3.pb(i);
  }
  return temp3.size();
}
//.....................................

void suraj()
{
  int n, h;
  cin >> n >> h;
  vector<int> ants(n);
  for (int i = 0; i < n; i++)
    cin >> ants[i];

  sort(ants.begin(), ants.end());
  vector<int> temp;
  for (int ant : ants)
  {
    if (ant < h)
      h += (ant / 2);
    else
      temp.pb(ant);
  }

  int minAliveAnts = 1e9;
  // 2 2 3
  minAliveAnts = min(minAliveAnts, aliveAnts(2, 2, 3, temp, h));

  // 2 3 2
  minAliveAnts = min(minAliveAnts, aliveAnts(2, 3, 2, temp, h));
  // 3 2 2
  minAliveAnts = min(minAliveAnts, aliveAnts(3, 2, 2, temp, h));

  cout << n - minAliveAnts << endl;
}
